// Andrew Stam, Hak Joon Lee - CS 4500 Assignment 1

// Import assert purely for testing
#include <assert.h>
#include "object.h"
#include "queue.h"

void test_object_equals() {
	// Object creation
	Object* o1 = new Object();
	Object* o2 = new Object();

	// Two different objects should not be equal
	assert(!(o1->equals(o2)));
	// Same with their hashes
	assert(o1->hash() != o2->hash());

	// An object should equal itself
	assert(o1->equals(o1));
	// Same with its own hash
	assert(o1->hash() == o1->hash());

	// Call the destructor and delete objects after creation
	delete o1;
	delete o2;
}

void test_queue_insert() {
	// Object creation
	Object* o1 = new Object();

	// Queue creation
	Queue* q = new Queue();

	// Check that queue size is 0
	assert(q->size() == 0);
	q->enqueue(o1);
	// Size incremented after insertion
	assert(q->size() == 1);
	// Check value equals what we inserted
	assert(o1->equals(q->peek()));
	
	// Call the destructor and delete objects after creation
	delete o1;
	delete q;
}

void test_queue_remove() {
	// Object creation
	Object* o1 = new Object();

	// Queue creation
	Queue* q = new Queue();

	q->enqueue(o1);
	// Size incremented after insertion
	assert(q->size() == 1);
	// Check value equals what we inserted
	assert(o1->equals(q->dequeue()));
	// Size incremented after removal
	assert(q->size() == 0);
	// Check is queue is empty
	assert(q->isEmpty());
		
	// Call the destructor and delete objects after creation
	delete o1;
	delete q;
}	

void test_queue_clear() {
	// Object creation
	Object* o1 = new Object();
	Object* o2 = new Object();

	// Queue creation
	Queue* q = new Queue();

	q->enqueue(o1);
	q->enqueue(o2);
	// Size incremented after insertion
	assert(q->size() == 2);

	// Clear the queue of all its elements
	q->clear();
	// Check that queue is empty
	assert(q->isEmpty());
		
	// Call the destructor and delete objects after creation
	delete o1;
	delete o2;
	delete q;
}	

void test_queue_get() {
	// Object creation
	Object* o1 = new Object();
	Object* o2 = new Object();

	// Queue creation
	Queue* q = new Queue();

	q->enqueue(o1);
	q->enqueue(o2);
	// Size incremented after insertion
	assert(q->size() == 2);
	// Element 1 should be o1
	// Element 2 should be o2
	assert(q->get(0)->equals(o1));
	assert(q->get(1)->equals(o2));
	// Element 1 should be the same as peek
	assert(q->get(0)->equals(q->peek()));

	// Call the destructor and delete objects after creation
	delete o1;
	delete o2;
	delete q;
}

void test_queue_error_handling() {
	// Object creation
	Object* o1 = new Object();

	// Queue creation
	Queue* q = new Queue();

	// Trying to peek on an empty queue should return NULL
	assert(q->peek() == NULL);

	q->enqueue(o1);
	// This should work now that there's 1 element
	assert(q->get(0)->equals(q->peek()));

	// Trying to get an element out of bounds should return NULL
	assert(q->get(1) == NULL);

	// After emptying queue, calling dequeue should return NULL
	assert(q->dequeue()->equals(o1));
	assert(q->dequeue() == NULL);

	// Call the destructor and delete objects after creation
	delete o1;
	delete q;
}

void test_string_queue() {
	// String creation 
	String* s1 = new String("Hello");

	// StrQueue creation
	StrQueue* q = new StrQueue();

	// Check peek on empty queue returns NULL 
	assert(q->peek() == NULL);

	// Add a string to the queue and that it's added properly
	q->enqueue(s1);
	assert(q->peek()->equals(s1));
	assert(q->size() == 1);	

	// Check accessing element in queue works properly
	assert(q->get(0)->equals(s1));
	assert(q->get(1) == NULL);

	// Check removing elements from the queue works properly
	assert(q->dequeue()->equals(s1));
	assert(q->dequeue() == NULL);
	assert(q->size() == 0);	

	// Call the destructor and delete objects after creation
	delete s1;
	delete q;
}

// Test cases given a correct implementation of Object and Queue
int main() {
	test_object_equals();
	test_queue_insert();
	test_queue_remove();
	test_queue_clear();
	test_queue_get();
	test_queue_error_handling();
	test_string_queue();
}

