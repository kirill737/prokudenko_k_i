// QueueP_prokud.cpp: определяет точку входа для консольного приложения.
//

#include "QueueP.h"


QueueP::QueueP(const QueueP& copy) {
	this->head = new Node(copy.head->value);
	Node* current_copy = copy.head;
	Node* current_our = this->head;
	while (current_copy->pNext != nullptr) {
		current_our->pNext = new Node(current_copy->pNext->value);
		current_our = current_our->pNext;
		current_copy = current_copy->pNext;
	}

	current_our->pNext = new Node(current_copy->value);
	this->tail = current_our->pNext;

}
QueueP::~QueueP() {
	while (!isEmpty()) {
		pop();
	}
}

void QueueP::push(const int& value_) {

	if (head == nullptr) {
		head = new Node(value_);
		tail = head;
		return;
	}
	else {
		Node* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		tail = current;
	}

	if (head->value >= value_) {
		Node* temp = head;
		head = new Node(value_);
		head->pNext = temp;
		return;
	}
	if (tail->value <= value_) {
		tail->pNext = new Node(value_);
		return;
	}

	else {
		Node* current = this->head;
		while ((current->pNext != nullptr) && (current->value < value_)) {
			current = current->pNext;
		}
		Node* temp = current->pNext;
		current->pNext = new Node(value_);
		current->pNext = temp;
		return;
	}
}
void QueueP::pop() {
	if (isEmpty()) {
		//throw std::string("You can't use 'pop' with an empty queue");
		return;
	}

	this->head = this->head->pNext;
}
const int& QueueP::top() const {
	if (isEmpty()) {
		//throw std::string("You can't use 'top' with an empty queue");
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


