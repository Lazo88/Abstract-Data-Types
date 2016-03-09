#include <iostream>
#include <cstdlib>
#include "a2_dynamic_stack.hpp"

using namespace std;

typedef DynamicStack::StackItem StackItem;  
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	init_capacity_ = 16;
	capacity_ = 16;
	size_ = 0;
	items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	init_capacity_ = capacity;
	capacity_ = capacity;
	size_ = 0;
	items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
	delete [] items_;
}

bool DynamicStack::empty() const
{
	return (size_ == 0);
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_>= capacity_) {
		StackItem* temp = new StackItem[capacity_*2];
		capacity_ *= 2;
		for (int i=0; i<size_; i++){
			temp[i]=items_[i];
		}
		delete [] items_;
		items_ = temp;
		temp = NULL;
		items_[size_]=value;
		size_++;
	}
	else{
		items_[size_]=value;
		size_++;
	}	
}

StackItem DynamicStack::pop()
{
	if(size_ == 0)
		return EMPTY_STACK;
	
	else
	{
		if((size_-1) <= (capacity_/4) && (capacity_/ 2) >= init_capacity_)
		{
		StackItem* temp = new StackItem[capacity_/2];
		capacity_ /= 2;
		
		for (int i=0; i<size_; i++)
			temp[i]=items_[i];

		delete [] items_;
		items_ = temp;
		temp = NULL;
		size_--;
		return items_[size_];
		}
		
		size_--;
		return items_[size_];
	}
}

StackItem DynamicStack::peek() const
{
	if(size_ == 0)
		return EMPTY_STACK;
	
	return items_[size_ - 1];
}

void DynamicStack::print() const
{
	cout << "This Array Contains: [";
	for (int i = 0; i<size_; i++){
		cout << "("<<items_[i] << ")->";
	}
	cout << "]";
}

/*
DYNAMIC STACK TESTING RESULTS
*****************************
Test1: New stack is valid
TEST PASSED
Test2: Push one item and then pop it
TEST PASSED
Test3: Simple push, pop, and peek test
TEST PASSED
Test4: Push 4 items, peek 5 items and then pop 5 items
TEST PASSED
Test5: Full stack doubles properly
TEST PASSED
Test6: Full stack doubles, then full stack doubles
TEST PASSED
Test7: Push a lot, pop a lot, no halving
TEST PASSED
Test8: Push a lot, pop a lot, halving
TEST PASSED
Test9: Lots of pushes, peeks, and pops
TEST PASSED
Test10: Lots of pushes, peeks, and pops
TEST PASSED
*/

