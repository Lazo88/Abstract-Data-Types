#include "a1_doubly_linked_list.hpp"
#include <cstdlib>
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	next = NULL;
	prev = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	while(head_) 
		remove_front();
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
	return !head_;
}

bool DoublyLinkedList::full() const
{
	return size_ >= CAPACITY;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const //can be optimized
{
	if(index >= size_)
		return -1;
	
	Node* selected = head_;
	
	for (int i = 0; i < index; i++)
		selected = selected->next;
	
	return selected->value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	unsigned int index = 0;
	Node* item = head_;
	
	while (item && index < CAPACITY)
	{
		if(value == item->value)
			return index;
		
		
		item = item->next;
		index++;
	}
	
	return 66666;
}

void DoublyLinkedList::print() const
{
	Node* selected = head_;
	
	for (int i = 0; i < size_; i++)
	{
		std::cout << "[" << selected->value << "] ";
		selected = selected->next;
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* selected = head_;
	
	for (int i = 0; i < index; i++)
		selected = selected->next;

	return selected;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if (size_ == CAPACITY || index > size_)
		return false;
	
	else if (size_ == 0 )
	{
		Node* newNode = new Node(value);

		head_ = newNode;
		tail_ = newNode;
		
		newNode = NULL;
		size_++;
		return true;
	}
	
	else if (index == 0)
	{
		Node* newNode = new Node(value);
		newNode->next = getNode(index);
		
		head_ = newNode;
		
		Node* nextNode = getNode(1);
		nextNode->prev = newNode;
		nextNode= NULL;
		
		size_++;
		return true;
	}
	
	else if (index == size_)
	{
		Node* newNode = new Node(value);
		newNode->prev = getNode(index - 1);
	
		tail_ = newNode;
	
		Node* prevNode = getNode(index - 1);
		prevNode->next = newNode;
		prevNode = NULL;
		
		size_++;
		return true;
	}
	
	else
	{
		Node* newNode = new Node(value);
		newNode->next = getNode(index);
		newNode->prev = getNode(index - 1);
	
		Node* prevNode = getNode(index - 1);
		prevNode->next = newNode;
		
		Node* nextNode = getNode(index);
		nextNode->prev = newNode;
	
		newNode = NULL;
		prevNode = NULL;
		nextNode = NULL;
		
		size_++;
		return true;
	}
	
}

bool DoublyLinkedList::insert_front(DataType value)
{
	return insert(value, 0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
	return insert(value, size_);
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (index >= size_)
		return false;
	
	else if (size_ == 1)
	{
		delete head_;
		
		head_ = NULL;
		tail_ = NULL; 
		
		size_--;
		return true;
	}
	else if (index == 0)
	{
		Node* temp = getNode(index);
		Node* nextNode = getNode(index +1);
		
		head_ = nextNode;
		nextNode->prev = NULL;
		
		delete temp;
		temp = NULL;
		nextNode = NULL;
	}
	else if (index == size_ - 1)
	{
		delete tail_;
		
		Node* newLast = getNode(size_ - 2);
		newLast->next = NULL;
		newLast = NULL;
		
		tail_ = newLast;
		
		size_--;
		return true;
	}
	
	else
	{
		Node* temp = getNode(index);
		Node* prevNode = getNode(index - 1);
		Node* nextNode = getNode(index +1);
		
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		
		delete temp;
		temp = NULL;
		prevNode = NULL;
		nextNode = NULL;
		
		size_--;
		return true;
	}
	
}

bool DoublyLinkedList::remove_front()
{
	return remove(0);
}

bool DoublyLinkedList::remove_back()
{
	return remove(size_ - 1);
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{	
	if (index >= size_)
		return false;
	
	else
	{
		Node* temp = getNode(index);
	
		temp->value = value;
	
		temp = NULL;
	
		return true;
	}
}
