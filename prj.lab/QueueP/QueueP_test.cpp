#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <QueueP/QueueP.h>

TEST_CASE("[QueueP] - all tests") {
	QueueP q1;
	q1.push(3);
	std::cout << q1.top() << std::endl;

	q1.push(4);
	std::cout << q1.top() << std::endl;

	q1.push(3);
	std::cout << q1.top() << std::endl;
	q1.pop();
	q1.pop();
	std::cout << q1.top() << std::endl;

	std::cout << q1.isEmpty() << std::endl;
	//std::cout << "FUCK OFF" << std::endl;
}
