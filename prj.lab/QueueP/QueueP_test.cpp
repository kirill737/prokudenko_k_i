#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <QueueP/QueueP.h>


TEST_CASE("[QueueP] - methods tests") {
	QueueP q1;
	q1.push(3);
	CHECK(q1.top() == 3);
	q1.push(4);
	CHECK(q1.top() == 3);
	q1.push(3);
	CHECK(q1.top() == 3);
	q1.pop();
	q1.pop();
	CHECK(q1.top() == 4);
	CHECK(!(q1.isEmpty()));
	q1.pop();
	CHECK((q1.isEmpty()));
}
TEST_CASE("[QueueP] - constructors tests") {
	QueueP q1;
	CHECK(q1.isEmpty());
	q1.push(3);
	q1.push(1);
	q1.push(2);
	QueueP q2 = q1;
	q2.pop();
	q2.pop();
	q2.pop();
	CHECK(q2.isEmpty());
	CHECK(!(q1.isEmpty()));
}
TEST_CASE("[QueueP] - exeption tests") {
	QueueP q1;
	CHECK_THROWS(q1.top());
	CHECK_THROWS(q1.pop());
}


