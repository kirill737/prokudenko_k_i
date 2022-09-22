//начало cpp
#include "rational.h"



int Nod(int num1, int num2)
{
	int num_1 = abs(num1), num_2 = abs(num2);
	while (num_1 > 0 && num_2 > 0)

		if (num_1 > num_2){
			num_1 %= num_2;
		}
		else {
			num_2 %= num_1;
		}
	if ((num_1 + num_2) == 0)
		return 1;
	return num_1 + num_2;
}

void Rational::Fract_simp(Rational fract) {
	int nod = Nod(fract._num_, fract._denom_);
	fract._num_ /= nod;
	fract._denom_ /= nod;
}


Rational::Rational(int numerator, int denomerator)
{
	if (denomerator == 0)
	{
		throw std::string("Invalid denominator in conctructor: 0");
	}

	if (denomerator < 0) {
		numerator = -numerator;
		denomerator = -denomerator;
	}
	_num_ = numerator;
	_denom_ = denomerator;
	return;
}

//Rational Rational::operator++(int);
//Rational Rational::operator--(int);
//
//Rational& Rational::operator++();
//Rational& Rational::operator--();


bool Rational::operator==(const Rational& rhs) const
{
	if ((this->_num_ == 0) && (rhs._num_ == 0))
	{
		return true;
	}
	if ((this->_num_ * rhs._num_ == 0) && ((this->_num_ + rhs._num_) != 0))
	{
		return false;
	}

	return (this->_num_* rhs._denom_ == this->_denom_ * rhs._num_);
}

bool Rational::operator!=(const Rational& rhs) const
{
	return(!operator==(rhs));
}

Rational& Rational::operator=(const Rational& rhs)
{
	_num_ = rhs._num_;
	_denom_ = rhs._denom_;
	return *this;
}

Rational& Rational::operator+=(const Rational& rhs)
{
	_num_ = this->_num_ * rhs._denom_ + this->_denom_ * rhs._num_;
	_denom_ = rhs._denom_ * this->_denom_;
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	_num_ = this->_num_ * rhs._denom_ - this->_denom_ * rhs._num_;
	_denom_ = rhs._denom_ * this->_denom_;
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	Rational lhs{ *this };
	_num_ = lhs._num_ * rhs._num_;
	_denom_ = lhs._denom_ * rhs._denom_;
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	Rational lhs{ *this };
	if (rhs == Rational{ 0, 1 })
	{
		std::cout << rhs;
		throw std::string("Can not division by 0");
	}
	_num_ = lhs._num_ * rhs._denom_;
	_denom_ = lhs._denom_ * rhs._num_;
	return *this;
}

Rational Rational::operator+(const Rational& rhs) const
{
	Rational sum{ *this };
	sum += rhs;
	return sum;
}

Rational Rational::operator-(const Rational& rhs) const
{
	Rational sum{ *this };
	sum -= rhs;
	return sum;
}

Rational Rational::operator*(const Rational& rhs) const
{
	Rational lhs{ *this };
	return lhs *= rhs;
}

Rational Rational::operator/(const Rational& rhs) const
{
	Rational lhs{ *this };
	return lhs /= rhs;
}

Rational Rational::operator-() const {
	return Rational{ -_num_, _denom_ };
}

bool Rational::operator>(const Rational& rhs) const
{
	if (this->_num_ * rhs._denom_ > this->_denom_ * rhs._num_)
		return true;
	else
		return false;
}

bool Rational::operator>=(const Rational& rhs) const
{
	if ((*this > rhs) || (*this == rhs))
		return true;
	else
		return false;
}

bool Rational::operator<(const Rational& rhs) const
{
	if (this->_num_ * rhs._denom_ < this->_denom_ * rhs._num_)
		return true;
	else
		return false;
}

bool Rational::operator<=(const Rational& rhs) const
{
	if ((*this < rhs) || (*this == rhs))
		return true;
	else
		return false;
}

//ввод и вывод

std::ostream& operator<<(std::ostream& ostrm, const Rational& data)
{
	int nod = Nod(data._num_, data._denom_);
	if (data._num_ < 0 && data._denom_ < 0)
	{
		ostrm <<  -data._num_ / nod << data._separator_ << -data._denom_ / nod;
	}
	else
	{
		ostrm << data._num_ / nod << data._separator_ << data._denom_ / nod;
	}
	return ostrm;
}

std::istream& operator>>(std::istream& istrm, Rational& data) {
	int numerator(0);
	char separator(0);
	int denominator(0);

	istrm >> numerator;
	istrm.get(separator);
	if (!std::isdigit(istrm.peek())) {
		istrm >> denominator;
		istrm.setstate(std::ios_base::failbit);
	}
	else {
		istrm >> denominator;
	}
	if (!istrm.bad()) {
		if (separator == Rational::_separator_) {
			data._num_ = numerator;
			data._denom_ = denominator;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}







//конец cpp