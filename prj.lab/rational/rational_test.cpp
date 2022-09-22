#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.h>

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
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
		std::cout << "	Correct \n\n";
	}
	else
	{
		std::cout << "	Incorrect \n\n";
	}
}

void Is_same(Rational exp, Rational rec)
{
	if (exp == rec)
	{
		std::cout << "	Correct \n\n";
	}
	else
	{
		std::cout << " exp: " << exp << " rec: " << rec << "|||" << (exp == rec) << "|||" " Incorrect \n\n";
	}
}

bool Equality_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	std::string result = "";
	if (lhs == rhs)
		result = "true";
	else
		result = "false";

	std::cout <<"Test #" << Test_Num << ": " << lhs << " == " << rhs << "	-->	" << result << "\n";
	return lhs == rhs;
}

bool Inequality_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	std::string result = "";
	if (lhs != rhs)
		result = "true";
	else
		result = "false";

	std::cout << "Test #" << Test_Num << ": " << lhs << " != " << rhs << "	-->	" << result << "\n";
	return lhs != rhs;
}

bool More_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	std::string result = "";
	if (lhs > rhs)
		result = "true";
	else
		result = "false";

	std::cout << "Test #" << Test_Num << ": " << lhs << " > " << rhs << "	-->	" << result << "\n";
	return lhs > rhs;
}

bool More_eq_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	std::string result = "";
	if (lhs >= rhs)
		result = "true";
	else
		result = "false";

	std::cout << "Test #" << Test_Num << ": " << lhs << " >= " << rhs << "	-->	" << result << "\n";
	return lhs >= rhs;
}

bool Less_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	std::string result = "";
	if (lhs < rhs)
		result = "true";
	else
		result = "false";

	std::cout << "Test #" << Test_Num << ": " << lhs << " < " << rhs << "	-->	" << result << "\n";
	return lhs < rhs;
}

bool Less_eq_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	std::string result = "";
	if (lhs <= rhs)
		result = "true";
	else
		result = "false";

	std::cout << "Test #" << Test_Num << ": " << lhs << " <= " << rhs << "	-->	" << result << "\n";
	return lhs <= rhs;
}




Rational Sum_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	Rational result = lhs + rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs << " + " << rhs << "	-->	" << result <<"\n";
	return result;
}

Rational Sub_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	Rational result = lhs - rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs << " - " << rhs << "	-->	" << result << "\n";
	return result;
}

Rational Mul_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	Rational result = lhs * rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs << " * " << rhs << "	-->	" << result << "\n";
	return result;
}

Rational Div_test(const Rational lhs, const Rational rhs, int Test_Num)
{
	Rational result = lhs / rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs << " / " << rhs << "	-->	" << result << "\n";
	return result;
}

Rational Sum_eq_test(Rational lhs, const Rational rhs, int Test_Num)
{
	Rational lhs_prev = lhs;
	lhs += rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs_prev << " += " << rhs << "	-->	" << lhs << "\n";
	return lhs;
}

Rational Sub_eq_test(Rational lhs, const Rational rhs, int Test_Num)
{
	Rational lhs_prev = lhs;
	lhs -= rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs_prev << " -= " << rhs << "	-->	" << lhs << "\n";
	return lhs;
}

Rational Mul_eq_test(Rational lhs, const Rational rhs, int Test_Num)
{
	Rational lhs_prev = lhs;
	lhs *= rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs_prev << " *= " << rhs << "	-->	" << lhs << "\n";
	return lhs;
}

Rational Div_eq_test(Rational lhs, const Rational rhs, int Test_Num)
{
	Rational lhs_prev = lhs;
	lhs /= rhs;
	std::cout << "Test #" << Test_Num << ": " << lhs_prev << " /= " << rhs << "	-->	" << lhs << "\n";
	return lhs;
}


TEST_CASE("[rational] - Comparison operators tests") {

	// == 
	std::cout << "\t\t\tTesting operation '==': \n\n";

	CHECK(Equality_test(Rational{ 3, 4 }, Rational{ 3, 4 }, 1));
	CHECK(Equality_test(Rational{ 3, 4 }, Rational{ 3, -4 }, 2) == false);
	CHECK(Equality_test(Rational{ 6, -8 }, Rational{ -3, 4 }, 3));
	CHECK(Equality_test(Rational{ -3, 4 }, Rational{ 3, -4 }, 4));
	std::cout << "\n\n\n";


	//!= 
	std::cout << "\t\t\tTesting operation '!=': \n\n";

	CHECK(Inequality_test(Rational{ 1, 5 }, Rational{ 50, 21 }, 1));
	CHECK(Inequality_test(Rational{ 8, 12 }, Rational{ -2, 3 }, 2));
	CHECK(Inequality_test(Rational{ -3, 4 }, Rational{ 3, 4 }, 3));
	CHECK(Inequality_test(Rational{ -4, 4 }, Rational{ -3, 3 }, 4) == false);
	CHECK(Inequality_test(Rational{ -4, 12 }, Rational{ 5, -15 }, 5) == false);
	std::cout << "\n\n\n";

	//>
	std::cout << "\t\t\tTesting operation '>': \n\n";

	CHECK(More_test(Rational{ 2, 5 }, Rational{ 3, 7 }, 1) == false);
	CHECK(More_test(Rational{ -1, 5 }, Rational{ 1, 6 }, 2) == false);
	CHECK(More_test(Rational{ 2, 10 }, Rational{ 1, 5 }, 3) == false);
	CHECK(More_test(Rational{0, 7}, Rational{}, 4) == false);

	//>=
	std::cout << "\t\t\tTesting operation '>=': \n\n";

	CHECK(More_eq_test(Rational{ 2, 5 }, Rational{ 3, 7 }, 1) == false);
	CHECK(More_eq_test(Rational{ -1, 5 }, Rational{ 1, 6 }, 2) == false);
	CHECK(More_eq_test(Rational{ 2, 10 }, Rational{ 1, 5 }, 3));
	CHECK(More_eq_test(Rational{ 0, 7 }, Rational{}, 4));

	//>
	std::cout << "\t\t\tTesting operation '<': \n\n";

	CHECK(Less_test(Rational{ 2, 5 }, Rational{ 3, 7 }, 1));
	CHECK(Less_test(Rational{ -1, 5 }, Rational{ 1, -6 }, 2));
	CHECK(Less_test(Rational{ 2, 10 }, Rational{ 1, 5 }, 3) == false);
	CHECK(Less_test(Rational{ 0, 7 }, Rational{}, 4) == false);

	//>=
	std::cout << "\t\t\tTesting operation '<=': \n\n";

	CHECK(Less_eq_test(Rational{ 2, 5 }, Rational{ 3, 7 }, 1));
	CHECK(Less_eq_test(Rational{ -1, 5 }, Rational{ 1, 6 }, 2));
	CHECK(Less_eq_test(Rational{ 2, 10 }, Rational{ 1, 5 }, 3));
	CHECK(Less_eq_test(Rational{ 0, 7 }, Rational{}, 4));

}

TEST_CASE("[rational] - Assignment operators tests") {
	//	+=
	std::cout << "				Testing operation '+=': \n\n";

	CHECK(Sum_eq_test(Rational{ 1, 5 }, Rational{ 3, -5 }, 1) == Rational{ -2, 5 });
	CHECK(Sum_eq_test(Rational{ -8, 3 }, Rational{ 3, 1 }, 2) == Rational{ 1, 3 });
	std::cout << "\n\n\n";



	//	-=
	std::cout << "				Testing operation '-=': \n\n";

	CHECK(Sub_eq_test(Rational{ 1, 5 }, Rational{ 3, 5 }, 1) == Rational{ -2, 5 });
	CHECK(Sub_eq_test(Rational{ 1, 3 }, Rational{ 1, 3 }, 2) == Rational{ 0, 1 });
	std::cout << "\n\n\n";



	//	*=
	std::cout << "				Testing operation '*=': \n\n";

	CHECK(Mul_eq_test(Rational{ 3, 2 }, Rational{ 2, 3 }, 1) == Rational{ 1, 1 });
	CHECK(Mul_eq_test(Rational{ -3, 6 }, Rational{ 9, -3 }, 2) == Rational{ 3, 2 });
	std::cout << "\n\n\n";



	//	/=
	std::cout << "				Testing operation '/=': \n\n";

	CHECK(Div_eq_test(Rational{ 3, 6 }, Rational{ 4, 3 }, 1) == Rational{ 3, 8 });
	CHECK(Div_eq_test(Rational{ -1, 1 }, Rational{ 1, -1 }, 2) == Rational{ 1, 1 });
	CHECK(Div_eq_test(Rational{ 6 }, Rational{ 2, 3 }, 3) == Rational{ 9 });

	CHECK_THROWS(Is_same(Div_eq_test(Rational{ 5, 2 }, Rational{}, 1), Rational{}));
	CHECK_THROWS(Is_same(Div_eq_test(Rational{ 5, 0 }, Rational{1}, 2), Rational{}));
	std::cout << "\n\n\n";
}

TEST_CASE("[rational] - Arithmetic operators tests") {
	//	+
	std::cout << "				Testing operation '+': \n\n";

	CHECK(Sum_test(Rational{ 1, 5 }, Rational{ 3, -5 }, 1) == Rational{ -2, 5 });
	CHECK(Sum_test(Rational{ -8, 3 }, Rational{ 3, 1 }, 2) == Rational{ 1, 3 });
	std::cout << "\n\n\n";


	//	-
	std::cout << "				Testing operation '-': \n\n";
	CHECK(Sub_test(Rational{ 1, 5 }, Rational{ 3, 5 }, 1) == Rational{ -2, 5 });
	CHECK(Sub_test(Rational{ 1, 3 }, Rational{ 1, 3 }, 2) == Rational{ 0, 1 });
	std::cout << "\n\n\n";


	//	*
	std::cout << "				Testing operation '*': \n\n";
	CHECK(Mul_test(Rational{ 3, 2 }, Rational{ 2, 3 }, 1) == Rational{ 1, 1 });
	CHECK(Mul_test(Rational{ -3, 6 }, Rational{ 9, -3 }, 2) == Rational{ 3, 2 });
	std::cout << "\n\n\n";


	//	/
	std::cout << "				Testing operation '/': \n\n";

	CHECK(Div_test(Rational{ 3, 6 }, Rational{ 4, 3 }, 1) ==  Rational{ 3, 8 });
	CHECK(Div_test(Rational{ -1, 1 }, Rational{ 1, -1 }, 2) == Rational{ 1, 1 });
	CHECK(Div_test(Rational{ 6 }, Rational{ 2, 3 }, 3) == Rational{ 9 });

	CHECK_THROWS(Is_same(Div_test(Rational{ 5, 2 }, Rational(), 1), Rational()));
	std::cout << "\n\n\n";

	CHECK(Rational{ 2, 5 } < Rational{ 3, 7 });
}

TEST_CASE("[ratinal] - Output tests") {
	std::stringstream stream;
	std::string test_string;
	Rational fraction = Rational(-4, 12);
	stream << fraction;
	stream >> test_string;
	CHECK(test_string == "-1/3");
}



void Comparison_operators_test()
{
	try {
		// == 
		std::cout << "\t\t\tTesting operation '==': \n\n";

		Is_same(Equality_test(Rational{ 3, 4 }, Rational{ 3, 4 }, 1), true);
		Is_same(Equality_test(Rational{ 3, 4 }, Rational{ 3, -4 }, 2), false);
		Is_same(Equality_test(Rational{ 6, -8 }, Rational{ -3, 4 }, 3), true);
		Is_same(Equality_test(Rational{ -3, 4 }, Rational{ 3, -4 }, 4), true);
		std::cout << "\n\n\n";


		//!= 
		std::cout << "\t\t\tTesting operation '!=': \n\n";

		Is_same(Inequality_test(Rational{ 3, 4 }, Rational{ 7, 4 }, 1), true);
		Is_same(Inequality_test(Rational{ 8, 12 }, Rational{ -2, 3 }, 2), true);
		Is_same(Inequality_test(Rational{ -3, 4 }, Rational{ 3, 4 }, 3), true);
		Is_same(Inequality_test(Rational{ -4, 4 }, Rational{ -3, 3 }, 4), false);
		Is_same(Inequality_test(Rational{ -4, 12 }, Rational{ 5, -15 }, 5), false);
		std::cout << "\n\n\n";
	}
	catch (std::string error)
	{
		std::cout << "Input exception: " << error << "\n\n";
	}
}

void Assignment_operators_test()
{
	

	

	try {

		////	=
		//std::cout << "				Testing operation '=': \n\n";

		//Is_same(Sum_eq_test(Rational{ 1, 5 }, Rational{ 3, -5 }, 1), Rational{ -2, 5 });

		//Is_same(Sum_eq_test(Rational{ -8, 3 }, Rational{ 3, 1 }, 2), Rational{ 1, 3 });

		//Is_same(Sum_eq_test(Rational{ 1, 5 }, Rational{ 3, -5 }, 1), Rational{ -2, 5 });

		//Is_same(Sum_eq_test(Rational{ -8, 3 }, Rational{ 3, 1 }, 2), Rational{ 1, 3 });
		//
		//std::cout << "\n\n\n";

		//	+=
		std::cout << "\t\t\tTesting operation '+=': \n\n";

		Is_same(Sum_eq_test(Rational{ 1, 5 }, Rational{ 3, -5 }, 1), Rational{ -2, 5 });
		Is_same(Sum_eq_test(Rational{ -8, 3 }, Rational{ 3, 1 }, 2), Rational{ 1, 3 });
		std::cout << "\n\n\n";



		//	-=
		std::cout << "\t\t\tTesting operation '-=': \n\n";

		Is_same(Sub_eq_test(Rational{ 1, 5 }, Rational{ 3, 5 }, 1), Rational{ -2, 5 });
		Is_same(Sub_eq_test(Rational{ 1, 3 }, Rational{ 1, 3 }, 2), Rational{ 0, 1 });
		std::cout << "\n\n\n";



		//	*=
		std::cout << "\t\t\tTesting operation '*=': \n\n";

		Is_same(Mul_eq_test(Rational{ 3, 2 }, Rational{ 2, 3 }, 1), Rational{ 1, 1 });
		Is_same(Mul_eq_test(Rational{ -3, 6 }, Rational{ 9, -3 }, 2), Rational{ 3, 2 });
		std::cout << "\n\n\n";



		//	/=
		std::cout << "\t\t\tTesting operation '/=': \n\n";

		Is_same(Div_eq_test(Rational{ 3, 6 }, Rational{ 4, 3 }, 1), Rational{ 3, 8 });
		Is_same(Div_eq_test(Rational{ -1, 1 }, Rational{ 1, -1 }, 2), Rational{ 1, 1 });
		Is_same(Div_eq_test(Rational{ 6 }, Rational{ 2, 3 }, 3), Rational{ 9 });
		Is_same(Div_eq_test(Rational{ 5, 2 }, Rational(), 4), Rational());
		std::cout << "\n\n\n";
	}
	catch (std::string error)
	{
		std::cout << "Error: " << error << "\n\n";
	}

}

void Arithmetic_operators_test()
{
	try {
		//	+
		std::cout << "\t\t\tTesting operation '+': \n\n";

		Is_same(Sum_test(Rational{ 1, 5 }, Rational{ 3, -5 }, 1), Rational{ -2, 5 });
		Is_same(Sum_test(Rational{ -8, 3 }, Rational{ 3, 1 }, 2), Rational{ 1, 3 });

		std::cout << "\n\n\n";



		//	-
		std::cout << "\t\t\tTesting operation '-': \n\n";

		Is_same(Sub_test(Rational{ 1, 5 }, Rational{ 3, 5 }, 1), Rational{ -2, 5 });
		Is_same(Sub_test(Rational{ 1, 3 }, Rational{ 1, 3 }, 2), Rational{ 0, 1 });

		std::cout << "\n\n\n";



		//	*
		std::cout << "\t\t\tTesting operation '*': \n\n";

		Is_same(Mul_test(Rational{ 3, 2 }, Rational{ 2, 3 }, 1), Rational{ 1, 1 });
		Is_same(Mul_test(Rational{ -3, 6 }, Rational{ 9, -3 }, 2), Rational{ 3, 2 });

		std::cout << "\n\n\n";



		//	/
		std::cout << "\t\t\tTesting operation '/': \n\n";

		Is_same(Div_test(Rational{ 3, 6 }, Rational{ 4, 3 }, 1), Rational{ 3, 8 });
		Is_same(Div_test(Rational{ -1, 1 }, Rational{ 1, -1 }, 2), Rational{ 1, 1 });
		Is_same(Div_test(Rational{ 6 }, Rational{ 2, 3 }, 3), Rational{ 9 });
		Is_same(Div_test(Rational{ 5, 2 }, Rational(), 4), Rational());

		std::cout << "\n\n\n";
	}
	catch (std::string error)
	{
		std::cout << "Error: " << error << "\n\n";
	}
	
}



//int main()
//{
//	/*Comparison_operators_test();
//	Assignment_operators_test();
//	Arithmetic_operators_test();*/
//	int t;
//	std::cin >> t;
//	return 0;
//}

TEST_CASE("[rational] - Comparison operators") {
	CHECK((Rational() == Rational(0, 1)));
	CHECK((Rational(3) == Rational(3, 1)));
	CHECK((Rational(1, 5) != Rational(50, 21)));
	CHECK((Rational(-2, 4) == Rational(-1, 2)));
	CHECK((Rational(2, -4) == Rational(-1, 2)));
	CHECK((Rational(-2, -4) == Rational(1, 2)));
	CHECK((Rational(2, 4) == Rational(1, 2)));
	CHECK((Rational(1, 2) > Rational(1, 3)));
	CHECK((Rational(1, 2) >= Rational(1, 2)));
	CHECK((Rational(-1, 2) >= Rational(-80, 90)));
	CHECK((Rational(1, 2) < Rational(4, 3)));
	CHECK((Rational(1, 2) <= Rational(1, 2)));
	CHECK((Rational(-1, 2) <= Rational(5, 3)));
	CHECK((-(Rational(1, 5)) == Rational(1, -5)));
	CHECK((-(Rational(1, -5)) == Rational(1, 5)));
	CHECK(((Rational(2, 10)) == Rational(3, 15)));
	CHECK(!((Rational(2, -2)) != Rational(-3, 3)));
	CHECK(((Rational(2, -2)) == Rational(-3, 3)));
	//CHECK((-Rational(1, 10) / 10) == -Rational(1, 100));
	CHECK(-Rational(10, 14) <= Rational(50, 7));
	CHECK_THROWS((Rational(10, 5) / Rational(0, 1)));
	//CHECK_THROWS(Rational(50, 1222) / 0);
	CHECK_THROWS(Rational(10, 40) / -Rational(0, 1));
	CHECK_THROWS(Rational(50, 1222) / Rational(0, 0));
	CHECK_THROWS((Rational(1, 0)));
	Rational a;
	std::string input_correct = "1/4\n5/6\n10/5\n-1/100\n-1/69\n5/90\n-180/1\n";
	std::string input_bad = "1/-0\n5 /2\n0-)5\n1+;100\n-169/-4\n5=90\n10/-50\n";
	std::vector<Rational> answers{ Rational(1, 4), Rational(5, 6), Rational(2, 1), Rational(-1, 100), Rational(-1, 69), Rational(5, 90), Rational(-180) };
	std::stringstream input;
	input << input_bad;
	for (int i = 0; i < 7; i++) {
		input >> a;
		CHECK(!input.good());
		if (input.good())
			std::cout << a;
		input.clear();
	}
	input.str("");
	input.clear();
	input << input_correct;
	for (int i = 0; i < answers.size(); i++) {
		input >> a;
		CHECK(a == answers[i]);
	}
}

TEST_CASE("[rational] - Equality operators") {
	CHECK((Rational(6) == Rational(6, 1)));
	CHECK((Rational(8, 15) == Rational(8, 15)));
	CHECK((Rational(2, 4) == Rational(1, 2)));
	CHECK((Rational(1, -2) == Rational(-1, 2)));
	CHECK((Rational(2, -4) == Rational(-1, 2)));
	CHECK((Rational(0, 7) == Rational(0, 1)));
}
TEST_CASE("[rational] - Unequality operators") {
	CHECK((Rational(2, 3) != Rational(2, 4)));
	CHECK(!(Rational(0, 3) != Rational(0, 4)));
}

TEST_CASE("[rational] - Arithmetic operators") {
	CHECK((Rational(1, 2) + Rational(1, 3) == Rational(5, 6)));
	CHECK((Rational(1, 2) + Rational(1, 2) == Rational(1, 1)));
	CHECK((Rational(1, 6) + Rational(3, 6) == Rational(2, 3)));
	CHECK((-Rational(1, 5) + Rational(6, 5) == Rational(1)));

	CHECK(((Rational(1, 2) += Rational(1, 3)) == Rational(5, 6)));
	CHECK(((Rational(1, 2) += Rational(1, 2)) == Rational(1, 1)));
	CHECK(((Rational(1, 6) += Rational(3, 6)) == Rational(2, 3)));
	CHECK(((-Rational(1, 5) += Rational(6, 5)) == Rational(1)));

	CHECK((Rational(5, 6) - Rational(4, 6) == Rational(1, 6)));
	CHECK((Rational(5, 6) - Rational(1, 6) == Rational(2, 3)));
	CHECK((Rational(1, 3) - Rational(1, 2) == Rational(-1, 6)));
	CHECK((Rational(5, -6) - Rational(3, -6) == Rational(-1, 3)));

	CHECK(((Rational(5, 6) -= Rational(4, 6)) == Rational(1, 6)));
	CHECK(((Rational(5, 6) -= Rational(1, 6)) == Rational(2, 3)));
	CHECK(((Rational(1, 3) -= Rational(1, 2)) == Rational(-1, 6)));
	CHECK(((Rational(5, -6) -= Rational(3, -6)) == Rational(-1, 3)));

	CHECK((Rational(1, 4) * Rational(2, 1) == Rational(1, 2)));
	CHECK((Rational(1, 6) * Rational(5, -6) == Rational(-5, 36)));
	CHECK((Rational(-1, 6) * Rational(5, -6) == Rational(5, 36)));
	CHECK((Rational(1, -6) * Rational(5, -6) == Rational(5, 36)));

	CHECK(((Rational(1, 4) *= Rational(2, 1)) == Rational(1, 2)));
	CHECK(((Rational(1, 6) *= Rational(5, -6)) == Rational(-5, 36)));
	CHECK(((Rational(-1, 6) *= Rational(5, -6)) == Rational(5, 36)));
	CHECK(((Rational(1, -6) *= Rational(5, -6)) == Rational(5, 36)));

	CHECK((Rational(1, 6) / Rational(1, 6) == Rational(1, 1)));
	CHECK((Rational(1, 20) / Rational(3, -2) == Rational(-1, 30)));
	CHECK((Rational(-1, 20) / Rational(3, -2) == Rational(1, 30)));
	CHECK((Rational(1, -20) / Rational(3, -2) == Rational(1, 30)));

	CHECK(((Rational(1, 6) /= Rational(1, 6)) == Rational(1, 1)));
	CHECK(((Rational(1, 20) /= Rational(3, -2)) == Rational(-1, 30)));
	CHECK(((Rational(-1, 20) /= Rational(3, -2)) == Rational(1, 30)));
	CHECK(((Rational(1, -20) /= Rational(3, -2)) == Rational(1, 30)));

	CHECK((-Rational(1, 2) == Rational(-1, 2)));
	CHECK((-Rational(-2, 4) == Rational(1, 2)));

	//CHECK((-Rational(-2, 3) == (Rational(-2, 3) * (-1))));
}

TEST_CASE("[rational] - Bool operators") {
	CHECK((Rational(1, 2) > Rational(1, 3)));
	CHECK(!(Rational(1, 3) > Rational(1, 2)));

	CHECK((Rational(1, 3) < Rational(1, 2)));
	CHECK(!(Rational(1, 2) < Rational(1, 3)));

	CHECK((Rational(1, 2) >= Rational(1, 3)));
	CHECK(!(Rational(1, 3) >= Rational(1, 2)));
	CHECK((Rational(1, 3) >= Rational(1, 3)));

	CHECK((Rational(1, 3) <= Rational(1, 2)));
	CHECK(!(Rational(1, 2) <= Rational(1, 3)));
	CHECK((Rational(1, 3) <= Rational(1, 3)));
}

TEST_CASE("[rational] - Exceptions") {
	CHECK_THROWS(Rational(1, 0));
	CHECK_THROWS(Rational(1, 2) / Rational(0, 2));
}

TEST_CASE("[rational] - In / Out") {
	std::stringstream correct_Str("-2/6  1/2  2/1  0/7  -8/12");
	Rational correct_Rational[] = { Rational(-2, 6), Rational(1, 2), Rational(2, 1), Rational(0, 7), Rational(-8, 12) };
	Rational io_Test(1, 1);
	for (int i = 0; i < 5; i++) {
		correct_Str >> io_Test;
		CHECK((io_Test == correct_Rational[i]));
	}
	
	std::stringstream out_Test;

	out_Test << correct_Rational[0];
	CHECK((out_Test.str() == "-1/3"));
	out_Test.str("");

	out_Test << correct_Rational[1];
	CHECK((out_Test.str() == "1/2"));
	out_Test.str("");

	out_Test << correct_Rational[2];
	CHECK((out_Test.str() == "2/1"));
	out_Test.str("");

	out_Test << correct_Rational[3];
	CHECK((out_Test.str() == "0/1"));
	out_Test.str("");

	out_Test << correct_Rational[4];
	CHECK((out_Test.str() == "-2/3"));
	out_Test.str("");
}


