#pragma once
#ifndef RATIONAL
#define RATIONAL

#include <iostream>
#include <sstream>
//������ ������������� �����

int Nod(int num_1, int num_2);

struct Rational {
public:
	explicit Rational(int numerator = 0, int denomerator = 1);
	~Rational() = default;
	void Fract_simp(Rational fract);

	//��������� ��������� (comparison operators)
	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	
	//��������� ������������ (assignment operators)
	Rational& operator=(const Rational& rhs);
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	//��������� ���������� (arithmetic operators)
	Rational operator+(const Rational& rhs) const;
	Rational operator-(const Rational& rhs) const;
	Rational operator*(const Rational& rhs) const;
	Rational operator/(const Rational& rhs) const;
	Rational operator-() const;

	bool operator>(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;

	//���� / ������ (input / output)
	friend std::ostream& operator<<(std::ostream& ostrm, const Rational& data);
	friend std::istream& operator>>(std::istream& istrm, Rational& data);
private:
	int _num_{ 0 };
	int _denom_{ 1 };
	static const char _separator_{ '/' };
};



//����� ������������� �����

#endif RATIONAL
