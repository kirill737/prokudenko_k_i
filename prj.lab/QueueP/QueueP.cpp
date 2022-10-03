// QueueP_prokud.cpp: определяет точку входа для консольного приложения.
//
#include "QueueP.h"

QueueP::QueueP(const QueueP& copy) {
	head = std::make_unique<Node>(copy.top());
	//this->head = new Node(copy.head->value);

	Node* current_copy = copy.head->pNext.get();
	Node* current_our = head.get();
	while (current_copy->pNext != nullptr) {
		current_our->pNext = std::make_unique<Node>(current_copy->pNext->value);
		current_our = current_our->pNext.get();
		current_copy = current_copy->pNext.get();
	}

	current_our->pNext = std::make_unique<Node>(current_copy->value);
}
QueueP::~QueueP() {
	while (!isEmpty()) {
		pop();
	}
}

void QueueP::push(const int& value_) {
	std::unique_ptr<Node> temp = std::make_unique<Node>(value_);
	if (head == nullptr || head->value >= value_) {
		temp->pNext = std::move(head);
		head = std::move(temp);
		return;
	}
	Node* current = head.get();
	while ((current->pNext != nullptr) && (value_ >= current->pNext->value)) {
		current = current->pNext.get();
	}
	temp->pNext = std::move(current->pNext);
	current->pNext = std::move(temp);
	return;
}
void QueueP::pop() {
	if (isEmpty()) {
		throw std::string("You can't use 'pop' with an empty queue");
		return;
	}
	head = std::move(head->pNext);
}
const int& QueueP::top() const {
	if (isEmpty()) {
		throw std::string("You can't use 'top' with an empty queue");
		return 0;
	}
	return (head->value);
}
bool QueueP::isEmpty() const {
	if (head == nullptr) {
		return true;
	}
	return false;
}


