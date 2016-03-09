//Jonathan Lazo 20564052  , Can Cui 20612025

#include "a1_sequential_list.hpp"

#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	data_ = new DataType[capacity_];	
	size_ = 0;
}

SequentialList::~SequentialList()
{
	delete[] data_;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	return (size_ == 0);
}

bool SequentialList::full() const
{
	return (size_ == capacity_);
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index >= size_) 
		return -1;
	
	return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
	for(int i = 0; i < size_; i++)
	{
		if(data_[i] == val)
			return i;
	}
	return size_; 
}

void SequentialList::print() const
{
	for(int i = 0; i < size_; i++)
	{
		std::cout << "[" << data_[i] << "]";
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(size_ == capacity_ || index > size_)
		return false;
	
	if(size_ == 0)
		data_[0] = val;
		
	else if (size_ == 1)
	{
		if (index == 1)
			data_[1] = val;
			
		else
		{
			data_[1] = data_[0];
			data_[0] = 	val;
		}
	}
	else
	{
		for (int i = size_; i > index; i--)
			data_[i] = data_[i - 1];
	
		data_[index] = val;	
		
	}
	size_++;
	return true;
}

bool SequentialList::insert_front(DataType val)
{
	return insert(val, 0);
}

bool SequentialList::insert_back(DataType val)
{
	return insert(val, size_);
}

bool SequentialList::remove(unsigned int index)
{
	if(size_ == 0 || index >= capacity_)
		return false;
	
	for (int i = index; i < size_; i++)
	{
		if (i + 1 < capacity_)
			data_[i] = data_[i + 1];
	}
	
	size_--;
	return true;
}

bool SequentialList::remove_front()
{
	return remove(0);
}

bool SequentialList::remove_back()
{
	return remove(size_ - 1);
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(index >= size_)
		return false;
		
	data_[index] = val;
	return true;	
}

/*
SEQUENTIAL LIST TESTING RESULTS
*******************************
Test1: New empty list is valid
TEST PASSED
Test2: insert_front() and insert_back() on zero-element list
TEST PASSED
Test3: select() and search() work properly
TEST PASSED
Test4: remove_front() and remove_back() on one-element list
TEST PASSED
Test5: Inserting too many elements should fail
TEST PASSED
Test6: insert_front() keeps moving elements forward
TEST PASSED
Test7: inserting at different positions in the list
TEST PASSED
Test8: try to remove too many elements, then add a few elements
TEST PASSED
Test9: lots of inserts and deletes, all of them valid
TEST PASSED
Test10: lots of inserts and deletes, some of them invalid
TEST PASSED
*/

