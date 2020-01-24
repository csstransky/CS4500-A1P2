Andrew Stam and Hak Joon Lee
CS 4500 - Assignment 1, part 2

For this assignment, we decided to implement an API for Queues. First, we started by setting up an 
interface for Objects. Objects have a constructor and destructor, and the basic methods equals() 
and hash(). These are two methods that all subclasses of Object should implement. This design was 
fairly straightforward, as the base class Object only really needs these methods.

Next came the API design for Queues. Since the assignment specification said that our design had 
to accomodate at least Queues of Object and String, we oriented all of our methods around Object, 
since we expect String to inherit from Object. Therefore, because the methods we designed work 
with Object, they should work with String as well. It is up to the actual implementation to decide 
whether or not Queues of multiple types should be allowed. If it must only be one type, there can 
be checks to ensure that all elements enqueued are the same type, say by checking against the type 
of the first element.

There were several methods to design that we felt were necessary for a Queue. Besides a 
constructor and destructor, there were methods enqueue and dequeue. These methods, as their names 
imply, will respectively add an Object to the end of the Queue or remove the Object from the front 
of the Queue, also returning that Object. The enqueue method returns void, since we decidedd a 
user wouldn't need any additional information after calling this method. Next, we designed clear,
which is meant to remove all elements from the Queue, and isEmpty, which will return whether or 
not the Queue contains any elements. We also added the method called peek, which will return the 
element at the head of the Queue without removing it from the Queue. In addition, there is the 
get method, which will return the element at the specified index without removing it, which we 
felt would be useful to support even though we weren't sure if it was part of the typical behavior 
of a Queue. Lastly, we have the size method, which returns the number of elements stored in the 
Queue.

