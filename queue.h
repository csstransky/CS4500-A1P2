// Andrew Stam, Hak Joon Lee - CS 4500 Assignment 1
#pragma once
#include "object.h"
#include "string.h"

// Represents a queue of Objects
class Queue {
	public:
		// Create a new Queue of Objects
		Queue();

		// Destruct the Queue
		~Queue();

		// Insert the given Object at the end of the Queue
		void enqueue(Object* o);	
	
		// Remove and return the Object at the front of the Queue
		// If the queue is empty, return NULL
		Object* dequeue();

		// Clear the elements of the Queue
		virtual void clear();

		// Check if the Queue is empty
		virtual bool isEmpty();

		// Return the Object at the front of the Queue without removing the element
		// If the queue is empty, return NULL
		Object* peek();

		// Return the size of the Queue
		virtual size_t size();

		// Return the Object at the given index without removing the element
		// If out of bounds, return NULL
		Object* get(size_t index);
};

// Represents a queue of Strings
class StrQueue : public Queue {
	public:
		// Create a new Queue of Strings
		StrQueue();

		// Destruct the StrQueue
		~StrQueue();
		// Insert the given String at the end of the Queue
		void enqueue(String* o);	
	
		// Remove and return the String at the front of the Queue
		// If the queue is empty, return NULL
		String* dequeue();

		// Return the String at the front of the Queue without removing the element
		// If the queue is empty, return NULL
		String* peek();

		// Return the String at the given index without removing the element
		// If out of bounds, return NULL
		String* get(size_t index);	
};
