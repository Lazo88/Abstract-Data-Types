#include <iostream>
#include "a2_circular_queue.hpp"

using namespace std;

template <class J>
// const QueueItem CircularQueue::EMPTY_QUEUE = -999;
template <class J>
CircularQueue::CircularQueue()
{
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	capacity_ = 16;
	items_ = new T[capacity_];
}
template <class J>
CircularQueue::CircularQueue(unsigned int capacity)
{
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	capacity_ = capacity;
	items_ = new T[capacity_];
}
template <class J>
CircularQueue::~CircularQueue()
{
	delete [] items_;
}
template <class J>
bool CircularQueue::empty() const
{    
	return (size_ == 0);
}
template <class J>
bool CircularQueue::full() const
{
	return (size_ == capacity_);
}
template <class J>
int CircularQueue::size() const
{  
	return size_;
}
template <class J>
bool CircularQueue::enqueue(T value)
{
	if (size_ != capacity_)
	{
		items_[tail_] = value;
		tail_=(tail_+1)%capacity_;
		size_++;
		return true;
	}
	else
		return false;
}
template <class J>
T CircularQueue::dequeue()
{
	if (empty())
		return EMPTY_QUEUE;
	else
	{
		T temp = items_[head_];
		head_=(head_+1)%capacity_;
		size_--;
		return temp;
	}
}
template <class J>
T CircularQueue::peek() const
{
	if(size_ == 0)
		return EMPTY_QUEUE;
	else 
		return items_[head_];
}
template <class J>
void CircularQueue::print() const
{
	int i=head_+1;
	cout << "Values in Queue: [";
	cout << items_[head_];
	while (i!=head_)
	{
		cout << "("<<items_[i] << ")->";
		i=(i+1)%capacity_;
	}
	cout << "]";
}

/*

CIRCULAR QUEUE TESTING RESULTS
******************************
Test1: New queue is valid
TEST PASSED
Test2: Enqueue one item and then dequeue it
TEST PASSED
Test3: Enqueue two items and then dequeue three
TEST PASSED
Test4: Enqueue 16 items, peek 3 items and then dequeue 18 items
TEST PASSED
Test5: Enqueue items onto a full queue returns false
TEST PASSED
Test6: Queue is circular for enqueue()
TEST PASSED
Test7: Fill queue, then empty queue
TEST PASSED
Test8: Queue is circular for dequeue()
TEST PASSED
Test9: Lots of enqueues, dequeues, peeks, all valid
TEST PASSED
Test10: Lots of enqueues, dequeues, peeks, not all valid
TEST PASSED

*/

