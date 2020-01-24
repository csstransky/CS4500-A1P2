// Andrew Stam, Hak Joon Lee - CS 4500 Assignment 1
#pragma once
#include "object.h"

// Represents a queue of objects (where String inherits from Object)
class Queue {
	public:
		// Create a new Queue of Objects
		Queue();

		// Destruct the Queue
		~Queue();

		// Insert the given Object at the end of the Queue
		void enqueue(Object* o);

		// Remove and return the Object at the front of the Queue
		Object* dequeue();

		// Clear the elements of the Queue
		void clear();

		// Check if the Queue is empty
		bool isEmpty();

		// Return the Object at the front of the Queue without removing the element
		Object* peek();

		// Return the size of the Queue
		size_t size();

		// Return the Object at the given index without removing the element
		Object* get(size_t index);
}

