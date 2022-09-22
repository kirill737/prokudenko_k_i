//начало cpp
#include "complex.h"

Complex::Complex(double real, double imaginary)
{
	_real_ = real;
	_imag_ = imaginary;
	return;
}

bool Complex::operator==(const Complex& rhs) const
{
	return ((_real_ == rhs._real_) && (_imag_ == rhs._imag_));
}

bool Complex::operator!=(const Complex& rhs) const
{
	return (!operator==(rhs));
}

Complex& Complex::operator=(const Complex& rhs)
{
	_real_ = rhs._real_;
	_imag_ = rhs._imag_;
	return *this;
}

Complex& Complex::operator+=(const Complex& rhs)
{
	_real_ += rhs._real_;
	_imag_ += rhs._imag_;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	_real_ -= rhs._real_;
	_imag_ -= rhs._imag_;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	Complex lhs{ *this };
	_real_ = lhs._real_ * rhs._real_ - lhs._imag_ * rhs._imag_;
	_imag_ = lhs._real_ * rhs._imag_ + lhs._imag_ * rhs._real_;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	//доделать по-нормальному случай деления на 0
	Complex lhs{ *this };
	if (rhs == Complex{ 0.0, 0.0 })
	{
		
		throw std::string("Can not division by 0");
	}
	_real_ = (lhs._real_ * rhs._real_ + lhs._imag_ * rhs._imag_) / (rhs._real_ * rhs._real_ + rhs._imag_ * rhs._imag_);
	_imag_ = (lhs._imag_ * rhs._real_ - lhs._real_ * rhs._imag_) / (rhs._real_ * rhs._real_ + rhs._imag_ * rhs._imag_);
	return *this;
}

Complex Complex::operator+(const Complex& rhs) const
{
	Complex sum{ *this };
	sum += rhs;
	return sum;
}

Complex Complex::operator-(const Complex& rhs) const
{
	Complex sum{ *this };
	sum -= rhs;
	return sum;
}

Complex Complex::operator*(const Complex& rhs) const
{
	Complex lhs{ *this };
	return lhs *= rhs;
}

Complex Complex::operator/(const Complex& rhs) const
{
	Complex lhs{ *this };
	return lhs /= rhs;
}

Complex Complex::operator-() const {
	return Complex{ -_real_, -_imag_ };
}

//ввод и вывод

std::ostream& operator<<(std::ostream& ostrm, const Complex& info) 
{
	ostrm << info.leftBrace << info._real_ << info.separator << info._imag_ << info.rightBrace;
	return ostrm;
}

std::istream& operator>>(std::istream& istrm, Complex& info)
{
	char leftBrace(0), separator(0), rightBrace(0);
	double real(0.0), imaginary(0.0);
	istrm >> leftBrace >> real >> separator >> imaginary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == separator) 
			&& (Complex::rightBrace == rightBrace)) 
		{
			info._real_ = real;
			info._imag_ = imaginary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}



