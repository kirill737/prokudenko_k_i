#pragma once
#ifndef RATIONAL
#define RATIONAL

#include <iostream>
#include <sstream>
//начало заголовочного файла

int Nod(int num_1, int num_2);

struct Rational {
public:
	explicit Rational(int numerator = 0, int denomerator = 1);
	~Rational() = default;
	void Fract_simp(Rational fract);

	//операторы сравнения (comparison operators)
	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	
	//операторы присваивания (assignment operators)
	Rational& operator=(const Rational& rhs);
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	//операторы арифметики (arithmetic operators)
	Rational operator+(const Rational& rhs) const;
	Rational operator-(const Rational& rhs) const;
	Rational operator*(const Rational& rhs) const;
	Rational operator/(const Rational& rhs) const;
	Rational operator-() const;

	bool operator>(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;

	//ввод / ввывод (input / output)
	friend std::ostream& operator<<(std::ostream& ostrm, const Rational& data);
	friend std::istream& operator>>(std::istream& istrm, Rational& data);
private:
	int _num_{ 0 };
	int _denom_{ 1 };
	static const char _separator_{ '/' };
};



//конец заголовочного файла

#endif RATIONAL
