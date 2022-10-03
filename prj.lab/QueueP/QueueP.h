#pragma once
#ifndef QUEUEP
#define QUEUEP


#include <iostream>
#include <memory>

class QueueP {
public:
	QueueP() {
		std::unique_ptr<Node> head{ nullptr };
		std::unique_ptr<Node> tail{ nullptr };
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
		std::unique_ptr<Node> pNext{ nullptr };
		Node(int value_)
		{
			this->value = value_;
		}
	};
	std::unique_ptr<Node> head{ nullptr }; 
	std::unique_ptr<Node> tail{ nullptr };
};

#endif QUEUEP