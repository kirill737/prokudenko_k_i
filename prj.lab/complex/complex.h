#pragma once
#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <sstream>
//начало заголовочного файла
struct Complex {

	explicit Complex(double real = 0.0, double imaginary = 0.0);
	~Complex() = default;

	//операторы сравнения (comparison operators)
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;
	
	//операторы присваивания (assignment operators)
	Complex& operator=(const Complex& rhs);
	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);

	//операторы арифметики (arithmetic operators)
	Complex operator+(const Complex& rhs) const;
	Complex operator-(const Complex& rhs) const;
	Complex operator*(const Complex& rhs) const;
	Complex operator/(const Complex& rhs) const;
	Complex operator-() const;

	//ввод / ввывод (input / output)
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


//конец заголовочного файла

#endif COMPLEX
