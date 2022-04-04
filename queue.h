// *************************
//  CLASS PROVIDED:  Queue
// *************************
//
// CONSTRUCTOR:  Queue()
//  - DESCRIPTION:  initializes queue
//  - PRECONDITIONS:  N/A
//  - POSTCONDITIONS:  initializes the front, back, and number of items to zero so the stack is empty
//
// DESTRUCTOR:  ~Queue()
//  - DESCRIPTION:  deletes all values from the queue
//  - PRECONDITIONS:  the queue must have at least one value
//  - POSTCONDITIONS:  traverses through queue and all values are removed until the queue is empty
//
// CONSTANT MEMBER FUNCTIONS FOR THE SET CLASS
//   void enqueue(int)
//       - DESCRIPTION:  adds a value to the queue
//       - PRECONDITION:  checks if the queue is empty first
//       - POSTCONDITION:  if empty, new value becomes front, otherwise value is added to back of queue
//
//   int dequeue()
//       - DESCRIPTION:  removes front value from queue
//       - PRECONDITIONS:  queue is checked, if empty, message is printed to screen
//       - POSTCONDITIONS:  if queue was not empty, the front value is removed
//
//   int queueFront()
//       - DESCRIPTION:  returns -1 if empty or the front of queue
//       - PRECONDITIONS:  checks if queue is empty
//       - POSTCONDITIONS:  if queue is empty, -1 is returned, if it is not empty, front value is returned
//
//   int queueBack()
//		 - DESCRIPTION:  returns back of queue or -1 if the queue is empty
//       - PRECONDITIONS:  checks if queue is empty
//       - POSTCONDITIONS:  back of queue is returned, or if the queue was empty, -1 is returned
//
//
//


#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
	public:
		Queue();
		~Queue();
		void enqueue(int);	// enqueue prototype
		int dequeue();		// dequeue prototype
		int queueFront();	// queueFront prototype
		int queueBack();	// queueBack prototype
		
		
	private:
		struct QueueNode	// struct for QueueNode
		{
			int value;			// value in each node
			QueueNode *next;	// next pointer
		};
		QueueNode *front;		// front pointer
		QueueNode *back;		// back pointer
		int numItems;			// int value of number of items in queue
		
};

#endif
