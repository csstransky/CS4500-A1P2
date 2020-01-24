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

	// Trying to peek on an empty queue should return an error
	try {
		q->peek();
		// Shouldn't make it here
		assert(false);
	} catch (int e) {
		assert(true);
	}

	q->enqueue(o1);
	// This should work now that there's 1 element
	assert(q->get(0)->equals(q->peek()));

	// Trying to get an element out of bounds should return an error
	try {
		q->get(1);
		// Shouldn't make it here
		assert(false);
	} catch (int e) {
		assert(true);
	}

	// After emptying queue, calling dequeue should be an error
	assert(q->dequeue()->equals(o1));
	try {
		q->dequeue();
		// Shouldn't make it here
		assert(false);
	} catch (int e) {
		assert(true);
	}

	// Call the destructor and delete objects after creation
	delete o1;
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
}

