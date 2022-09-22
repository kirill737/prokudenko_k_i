#pragma once
#ifndef QUEUEP
#define QUEUEP


#include <iostream>
#include <memory>

class QueueP {
public:
	QueueP() {
		head = nullptr;
		tail = nullptr;
	};
	QueueP(const QueueP& copy);
	~QueueP();

	void pop();
	void push(const int& value_);
	const int& top() const;
	bool isEmpty() const;


private:
	struct Node {
		int value;
		Node* pNext;
		Node(int value_)
		{
			this->value = value_;
			this->pNext = nullptr;
		}
	};
	Node* head = nullptr;
	Node* tail = head;
};

#endif QUEUEP