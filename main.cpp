#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()			// CONSTRUCTOR
{
	front=0;			// initializes front to zero
	back=0;				// initializes back to zero
	numItems=0;			// initializes number of items to zero
}

Queue::~Queue()			// DESTRUCTOR
{
	while(front)		// while there is a front (queue is not empty)
	{
		dequeue();		// remove value
	}
}

void Queue::enqueue(int num)	// enqueue function
{
	QueueNode *newNode = 0;		// pointer to new node initialized to zero
	
	newNode = new QueueNode;	// creates new queue node
	newNode->value = num;		// sets the newNode's value to num
	newNode->next = 0;			// sets newNode's next to 0 (adds it to end of queue)
	
	if(!front)					// if queue is empty (no front)
	{
		front=newNode;			// the newNode becomes the front...
		back=newNode;			// ...and the back
	}
	else						// if its not empty
	{
		back->next = newNode;	// new node becomes the current back's next value
		back = newNode;			// back is set to the new node
	}
	
	numItems++;				// number of items is increased

}

int Queue::dequeue()		// dequeue function
{
	QueueNode *temp = 0;	// initializes pointer to zero
	int num;				// declares int num 
	
	if(!front)				// if queue is empty (no front)
	{
		return -1;
	}
	else					// if queue is not empty
	{
		num = front->value;		// num is set to front's value
		temp=front->next;		// temp is set to front's next
		delete front;			// front is deleted
		front=temp;				// front becomes temp
		numItems--;				// number of items is decreased by 1
	}
	
	return num;					// returns the number removed
	
}


int Queue::queueFront()			// queueFront function
{
	if(!front)					// if queue is empty (no front)
	{
		return -1;				// -1 is returned
	}
	else						// if queue is not empty
	{
		return front->value;	// front's value is returned
	}
}

int Queue::queueBack()		// queueBack function
{
	if(!front)				// if queue is empty (no front)
	{
		return -1;				// -1 is returned
	}
	else						// if queue is not empty
	{
		return back->value;	// back's value is returned
	}
}
