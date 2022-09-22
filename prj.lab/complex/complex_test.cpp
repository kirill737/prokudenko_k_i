
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <complex/complex.h>

#include <string>
#include <sstream>
#include <vector>


bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error  : " << str << " -> " << z << endl;
	}
	return istrm.good();
}


void Is_same(bool exp, bool rec)
{
	if (exp == rec)
	{
		std::cout << "	Correct \n";
	}
	else
	{
		std::cout << "	Incorrect \n";
	}
}

void Is_same(Complex exp, Complex rec)
{
	if (exp == rec)
	{
		std::cout << "	Correct \n";
	}
	else
	{
		std::cout << "	Incorrect \n";
	}
}


void Comparison_operators_test()
{
	bool right = true, wrong = false;

	// == 
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '==': \n\n";

	std::cout << "Test #1		" << "Testing {3, 4} == {3, 4}		" << "Expected: " << right << ";	" << "Recieved: " << (Complex{ 3, 4 } == Complex{ 3, 4 }) << "\n";
	Is_same(right, (Complex{ 3, 4 } == Complex{ 3, 4 }));

	std::cout << "Test #2		" << "Testing {3, 4} == {3, -4}		" << "Expected: " << wrong << ";	" << "Recieved: " << (Complex{ 3, 4 } == Complex{ 3, -4 }) << "\n";
	Is_same(wrong, (Complex{ 3, 4 } == Complex{ 3, -4 }));

	std::cout << "Test #3		" << "Testing {-3, 4} == {3, 4}		" << "Expected: " << wrong << ";	" << "Recieved: " << (Complex{ -3, 4 } == Complex{ 3, 4 }) << "\n";
	Is_same(wrong, (Complex{ -3, 4 } == Complex{ 3, 4 }));

	std::cout << "Test #3		" << "Testing {-3, 4} == {3, 4.0}		" << "Expected: " << right << ";	" << "Recieved: " << (Complex{ -3, 4 } == Complex{ 3, 4.0 }) << "\n";
	Is_same(wrong, (Complex{ 3, 4 } == Complex{ -3, 4.0 }));
	std::cout << "\n\n\n";


	// != 
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '!=': \n\n";

	std::cout << "Test #1		" << "Testing {3, 4} != {7, 4}		" << "Expected: " << right << ";	" << "Recieved: " << (Complex{ 3, 4 } != Complex{ 7, 4 }) << "\n";
	Is_same(right, (Complex{ 3, 4 } != Complex{ 7, 4 }));

	std::cout << "Test #2		" << "Testing {3, 4} != {3, 4}		" << "Expected: " << wrong << ";	" << "Recieved: " << (Complex{ 3, 4 } != Complex{ 3, 4 }) << "\n";
	Is_same(wrong, (Complex{ 3, 4 } != Complex{ 3, 4 }));

	std::cout << "Test #3		" << "Testing {-3, 4} != {3, 4}		" << "Expected: " << right << ";	" << "Recieved: " << (Complex{ -3, 4 } != Complex{ 3, 4 }) << "\n";
	Is_same(right, (Complex{ -3, 4 } != Complex{ 3, 4 }));

	std::cout << "Test #4		" << "Testing {3, 4} != {3, 4.0}		" << "Expected: " << wrong << ";	" << "Recieved: " << (Complex{ 3, 4 } != Complex{ 3, 4.0 }) << "\n";
	Is_same(wrong, (Complex{ 3, 4 } != Complex{ 3, 4.0 }));

	std::cout << "Test #5		" << "Testing {3, 4} != {3, -4.0}		" << "Expected: " << right << ";	" << "Recieved: " << (Complex{ 3, 4 } != Complex{ 3, -4.0 }) << "\n";
	Is_same(right, (Complex{ 3, 4 } != Complex{ 3, -4.0 }));
	std::cout << "\n\n\n";

}

void Assignment_operators_test()
{
	bool right = true, wrong = false;

	//	=
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '=': \n\n";
	Complex a1{ 1, 5 }, b1; b1 = a1;
	std::cout << "Test #1		" << "a = {1, 5}; Testing b = a;			" << "Expected: b = " << a1 << ";	" << "Recieved: b = " << b1 << "\n";
	Is_same(b1, Complex{ 1, 5 });

	Complex a2{ -8, 3 }, b2; b2 = a2;
	std::cout << "Test #2		" << "a = {-8, 3}; Testing b = a;			" << "Expected: b = " << a2 << ";	" << "Recieved: b = " << b2 << "\n";
	Is_same(b2, Complex{ -8, 3 });
	std::cout << "\n\n\n";

	//	+=
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '+=': \n\n";
	Complex a3{ 1, 5 }, b3{ 3, -5 }; b3 += a3;
	std::cout << "Test #1		" << "a = {1, 5}, b = {3, -5}; Testing b += a;	" << "Expected: b = " << Complex{ 4, 0 } << ";	" << "Recieved: b = " << b3 << "\n";
	Is_same(b3, Complex{ 4, 0 });

	Complex a4{ -8, 3 }, b4{ 3, 1 }; b4 += a4;
	std::cout << "Test #2		" << "a = {-8, 3}, b = {3, 1}; Testing b += a;	" << "Expected: b = " << Complex{ -5, 4 } << ";	" << "Recieved: b = " << b4 << "\n";
	Is_same(b4, Complex{ -5, 4 });
	std::cout << "\n\n\n";

	//	-=
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '-=': \n\n";
	Complex a5{ 1, 5 }, b5{ 3, 5 }; b5 -= a5;
	std::cout << "Test #1		" << "a = {1, 5}, b = {3, 5}; Testing b -= a;	" << "Expected: b = " << Complex{ 2, 0 } << ";	" << "Recieved: b = " << b5 << "\n";
	Is_same(b5, Complex{ 2, 0 });

	Complex a6{ 1, 3 }, b6{ 1, 3 }; b6 -= a6;
	std::cout << "Test #2		" << "a = {1, 3}, b = {1, 3}; Testing b -= a;	" << "Expected: b = " << Complex{ 0, 0 } << ";	" << "Recieved: b = " << b6 << "\n";
	Is_same(b6, Complex{ 0, 0 });
	std::cout << "\n\n\n";

	//	*=
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '*=': \n\n";
	Complex a7{ 3, 2 }, b7{ 2, 3 }; b7 *= a7;
	std::cout << "Test #1		" << "a = {3, 2}, b = {2, 3}; Testing b *= a;	" << "Expected: b = " << Complex{ 0, 13 } << ";	" << "Recieved: b = " << b7 << "\n";
	Is_same(b7, Complex{ 0, 13 });

	Complex a8{ 3, 0.5 }, b8{ 4, 4 }; b8 *= a8;
	std::cout << "Test #2		" << "a = {3, 0.5}, b = {4, 4}; Testing b *= a;	" << "Expected: b = " << Complex{ 10, 14 } << ";	" << "Recieved: b = " << b8 << "\n";
	Is_same(b8, Complex{ 10, 14 });
	std::cout << "\n\n\n";

	//	/=
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '/=': \n\n";
	Complex a9{ 4, 3 }, b9{ 3, 6 }; b9 /= a9;
	std::cout << "Test #1		" << "a = {3, 6}, b = {4, 3}; Testing b *= a;	" << "Expected: b = " << Complex{ 1.2, 0.6 } << ";	" << "Recieved: b = " << b9 << "\n";
	Is_same(b9, Complex{ 1.2, 0.6 });

	Complex a10{ 1, -1 }, b10{ -1, 1 }; b10 /= a10;
	std::cout << "Test #2		" << "a = {1, -1}, b = {-1, 1}; Testing b *= a;	" << "Expected: b = " << Complex{ -1, 0 } << ";	" << "Recieved: b = " << b10 << "\n";
	Is_same(b10, Complex{ -1, 0 });
	std::cout << "\n\n\n";
	

}

void Arithmetic_operators_test()
{
	//	+
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '+': \n\n";
	Complex a1{ 1, 5 }, b1{ 3, -5 };
	std::cout << "Test #1		" << "a = {1, 5}, b = {3, -5}; Testing a + b;	" << "Expected: " << Complex{ 4, 0 } << ";	" << "Recieved: " << a1 + b1 << "\n";
	Is_same(a1 + b1, Complex{ 4, 0 });

	Complex a2{ -8, 3 }, b2{ 3, 1 };
	std::cout << "Test #2		" << "a = {-8, 3}, b = {3, 1}; Testing a + b;	" << "Expected: " << Complex{ -5, 4 } << ";	" << "Recieved: " << a2 + b2 << "\n";
	Is_same(a2 + b2, Complex{ -5, 4 });
	std::cout << "\n\n\n";

	//	-
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '-': \n\n";
	Complex a3{ 1, 5 }, b3{ 3, 5 }; 
	std::cout << "Test #1		" << "a = {1, 5}, b = {3, 5}; Testing a - b;	" << "Expected: " << Complex{ -2, 0 } << ";	" << "Recieved: " << a3 - b3 << "\n";
	Is_same(a3 - b3, Complex{ -2, 0 });

	Complex a4{ 1, 3 }, b4{ 1, 3 }; 
	std::cout << "Test #2		" << "a = {1, 3}, b = {1, 3}; Testing a - b;	" << "Expected: " << Complex{ 0, 0 } << ";	" << "Recieved: " << a4 - b4 << "\n";
	Is_same(a4 - b4, Complex{ 0, 0 });
	std::cout << "\n\n\n";

	//	*
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '*': \n\n";
	Complex a5{ 3, 2 }, b5{ 2, 3 }; b5 * a5;
	std::cout << "Test #1		" << "a = {3, 2}, b = {2, 3}; Testing a * b;	" << "Expected: b = " << Complex{ 0, 13 } << ";	" << "Recieved: " << a5 * b5 << "\n";
	Is_same(a5 * b5, Complex{ 0, 13 });

	Complex a6{ 3, 0.5 }, b6{ 4, 4 }; b6 * a6;
	std::cout << "Test #2		" << "a = {1, 3}, b = {1, 3}; Testing a * b;	" << "Expected: b = " << a6 << ";	" << "Recieved: " << a6 * b6 << "\n";
	Is_same(a6 * b6, Complex{ 10, 14 });
	std::cout << "\n\n\n";

	//	/
	std::cout << "<--------------------------------------------------------------------------------------->\n";
	std::cout << "				Testing operation '/': \n\n";
	Complex a7{ 3, 6 }, b7{ 4, 3 }; a7 / b7;
	std::cout << "Test #1		" << "a = {3, 6}, b = {4, 3}; Testing a7 / b7;	" << "Expected: b = " << a7 << ";	" << "Recieved: " << a7 / b7 << "\n";
	Is_same(a7 / b7, Complex{ 1.2, 0.6 });

	Complex a8{ -1, 1 }, b8{ 1, -1 }; a8 * b8;
	std::cout << "Test #2		" << "a = {-1, 1}, b = {1, -1}; Testing b *= a;	" << "Expected: b = " << a8 << ";	" << "Recieved: " << a8 / b8 << "\n";
	Is_same(a8 / b8, Complex{ -1, 0 });
	std::cout << "\n\n\n";


}

//int main()
//{
//	
//	/*Comparison_operators_test();
//	Assignment_operators_test();
//	Arithmetic_operators_test();
//	Complex a{ 1, 7 }, b{5, 6};
//	std::cout << a * b;*/
//	Complex a, b;
//	std::cin >> a >> b;
//	return 0;
//
//}

//TEST_CASE("testing complex constructors") {
//	CHECK_NOTHROW(Complex(7.1, 3.5));
//	CHECK_NOTHROW(Complex(7.2, -3.6));
//	CHECK_NOTHROW(Complex(-7.3, 3.7));
//	CHECK_NOTHROW(Complex(-7.4, -3.8));
//	CHECK_NOTHROW(Complex(4.2));
//	CHECK_NOTHROW(Complex(-4.3));
//	CHECK_NOTHROW(Complex());
//	CHECK_NOTHROW(Complex(Complex(1.3, 2.7)));
//}
//
//TEST_CASE("testing complex arithmetics") {
//	CHECK((Complex{ 3.4, 7.2 } + Complex{ 2.3, 9.2 }) != Complex{ 5.7, 16.4 });
//	CHECK((Complex{ -2.3, 9.7 } - Complex{ 6.7, 9.3 }) != Complex{ -9, 0.4 });
//}
//
//TEST_CASE("testing complex I/O") {
//	std::vector<std::stringstream*> correct_inputs{ new std::stringstream("{7.7,3.3}"),
//													 new std::stringstream("{-3.7, 1}") };
//	std::vector<Complex> inputs_complex{ Complex(7.7, 3.3),
//										 Complex(-3.7, 1) };
//
//	for (int64_t i = 0; i < correct_inputs.size(); ++i) {
//		Complex input{ 1, 1 };
//		*(correct_inputs[i]) >> input;
//		CHECK(input == inputs_complex[i]);
//	}
//
//	for (auto it : correct_inputs) {
//		delete it;
//	}
//}

TEST_CASE("[complex] - Constructor checks") {
	CHECK((Complex(2) == Complex(double(2))));
	CHECK((Complex(2) == Complex(2, 0)));
	CHECK((Complex() == Complex(0, 0)));
	CHECK((Complex(1, -2) == Complex(1, -2)));
	CHECK((-Complex(1, 2) == Complex(-1, -2)));
}

TEST_CASE("[complex] - Arithmetic") {
	//CHECK(((2 + Complex(2, 1)) == Complex(4, 1)));

	//CHECK(((2 - Complex(3, 1)) == Complex(-1, -1)));

	//CHECK((2 * Complex(2, 1) == Complex(4, 2)));

	//CHECK((Complex(6, 2) / 2 == Complex(3, 1)));

	CHECK((Complex(2, 1) + Complex(5, 6) == Complex(7, 7)));
	CHECK((Complex(2, 3) + Complex(-5, -6) == Complex(-3, -3)));

	CHECK(((Complex(2, 1) += Complex(5, 6)) == Complex(7, 7)));
	CHECK(((Complex(2, 3) += Complex(-5, -6)) == Complex(-3, -3)));

	//CHECK((Complex(2, 3) + int(2) == Complex(4, 3)));

	//CHECK(((Complex(2, 3) += int(2)) == Complex(4, 3)));

	CHECK((Complex(1, 2) - Complex(9, 3) == Complex(-8, -1)));
	CHECK((Complex(3, 5) - Complex(1, 5) == Complex(2)));

	CHECK(((Complex(1, 2) -= Complex(9, 3)) == Complex(-8, -1)));
	CHECK(((Complex(3, 5) -= Complex(1, 5)) == Complex(2)));

	//CHECK((Complex(3, 3) - int(2) == Complex(1, 3)));

	//CHECK(((Complex(3, 3) -= int(2)) == Complex(1, 3)));

	CHECK((Complex(1, -1) * Complex(3, 6) == Complex(9, 3)));

	CHECK(((Complex(1, -1) *= Complex(3, 6)) == Complex(9, 3)));

	//CHECK((Complex(6, 5) * int(2) == Complex(12, 10)));

	//CHECK(((Complex(6, 5) *= int(2)) == Complex(12, 10)));

	CHECK((Complex(13, 1) / Complex(7, -6) == Complex(1, 1)));
	CHECK_THROWS((Complex(2, 3) / Complex(0, 0)));

	CHECK(((Complex(13, 1) /= Complex(7, -6)) == Complex(1, 1)));
	CHECK_THROWS((Complex(2, 3) /= Complex(0, 0)));

	//CHECK((Complex(30, 10) / int(2) == Complex(15, 5)));

	//CHECK(((Complex(30, 10) /= int(2)) == Complex(15, 5)));
	//CHECK(15.0 / Complex(15, 15) == Complex(0.5, -0.5));
}

TEST_CASE("[complex] - Bool") {
	CHECK((Complex(2, 2) == Complex(2, 2)));
	CHECK((-Complex(2, 2) == Complex(-2, -2)));
	CHECK((Complex(1 / 3, 2) == Complex(2 / 6, 2)));

	CHECK((Complex(2, 2) != Complex(2, 3)));
	CHECK((-Complex(2, 2) != Complex(-2, 2)));
	CHECK((Complex(1 / 3, 2) != Complex(2 / 6, 5)));
}

TEST_CASE("testing complex constructors") {
	CHECK_NOTHROW(Complex(7.1, 3.5));
	CHECK_NOTHROW(Complex(7.2, -3.6));
	CHECK_NOTHROW(Complex(-7.3, 3.7));
	CHECK_NOTHROW(Complex(-7.4, -3.8));
	CHECK_NOTHROW(Complex(4.2));
	CHECK_NOTHROW(Complex(-4.3));
	CHECK_NOTHROW(Complex());
	CHECK_NOTHROW(Complex(Complex(1.3, 2.7)));
}

TEST_CASE("testing complex arithmetics") {
	CHECK(Complex{ 3.4, 7.2 } + Complex{ 2.3, 9.2 } != Complex{ 5.7, 16.4 });
	CHECK(Complex{ -2.3, 9.7 } - Complex{ 6.7, 9.3 } != Complex{ -9, 0.4 });
}

TEST_CASE("testing complex I/O") {
	std::vector<std::stringstream*> correct_inputs{ new std::stringstream("{7.7,3.3}"),
													 new std::stringstream("{-3.7, 1}") };
	std::vector<Complex> inputs_complex{ Complex(7.7, 3.3),
										 Complex(-3.7, 1) };

	for (int64_t i = 0; i < correct_inputs.size(); ++i) {
		Complex input{ 1, 1 };
		*(correct_inputs[i]) >> input;
		CHECK(input == inputs_complex[i]);
	}

	for (auto it : correct_inputs) {
		delete it;
	}
}


