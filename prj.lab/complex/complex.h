#pragma once
#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <sstream>
//������ ������������� �����
struct Complex {

	explicit Complex(double real = 0.0, double imaginary = 0.0);
	~Complex() = default;

	//��������� ��������� (comparison operators)
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;
	
	//��������� ������������ (assignment operators)
	Complex& operator=(const Complex& rhs);
	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);

	//��������� ���������� (arithmetic operators)
	Complex operator+(const Complex& rhs) const;
	Complex operator-(const Complex& rhs) const;
	Complex operator*(const Complex& rhs) const;
	Complex operator/(const Complex& rhs) const;
	Complex operator-() const;

	//���� / ������ (input / output)
	/*std::ostream& write(std::ostream& ostrm) const;
	std::istream& read(std::istream& istrm);*/

	double _real_{ 0.0 };
	double _imag_{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

std::istream& operator>>(std::istream& istream, Complex& info); //second argument - data-collecting variable
std::ostream& operator<<(std::ostream& istream, const Complex& info);
//inline std::ostream& operator<<(std::ostream& ostrm, const Complex& infa)
//{
//	return infa.write(ostrm);
//}
//
//inline std::istream& operator>>(std::istream& istrm, Complex& infa)
//{
//	return infa.read(istrm);
//}


//����� ������������� �����

#endif COMPLEX
