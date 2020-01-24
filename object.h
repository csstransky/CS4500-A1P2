// Andrew Stam, Hak Joon Lee, CS 4500 - Assignment 1
#pragma once

// Generic, base-class for other Objects to inherit from
class Object {
	public:
		// Construct a new Object
		Object();

		// Destruct this Object
		~Object();

		// Does this Object equal the given Object?
		bool equals(Object *other);

		// What is the hash representation of this Object?
		size_t hash();
}

