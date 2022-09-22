#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#pragma once
#ifndef BITSET
#define BITSET
class Bitset {
public:
	typedef uint8_t container_type;
	class BitHolder {
	public:
		friend class Bitset;
		BitHolder() {};
		~BitHolder() = default;
		BitHolder(const BitHolder& copy) = default;
		BitHolder& operator=(const bool rhs);
		BitHolder& operator=(const BitHolder& rhs);
		operator bool() const; // to use BitHolder object as a bool
		
	private:
		Bitset* bitset_ = nullptr;
		uint64_t container_number_ = 0, bit_number_ = 0;
		BitHolder(Bitset* bitset, const uint64_t position);
	};

	~Bitset() = default;
	Bitset(const std::string & input);
	Bitset(int64_t size = 0, const bool filler = false);
	Bitset(const Bitset & copy);

	bool operator==(const Bitset& rhs) const;
	bool operator!=(const Bitset& rhs) const;
	bool operator[](const int64_t position) const;

	Bitset& operator&=(const Bitset& rhs);
	Bitset& operator|=(const Bitset& rhs);
	Bitset& operator^=(const Bitset& rhs); //XOR
	Bitset& operator<<=(const int64_t shift);
	Bitset& operator>>=(const int64_t shift);
	Bitset& operator=(const Bitset& rhs);
	

	Bitset operator~() const;

	BitHolder operator[](const int64_t position);

	/*std::ostream& WriteTo(std::ostream & ostrm) const;
	std::istream& ReadFrom(std::istream & istrm);*/

	void Fill(const bool filler);
	void resize(const int64_t size, const bool filler = false);

	bool CheckSize(const Bitset & rhs) const;

	int64_t size() const;

private:
	int64_t size_ = 0;
	uint8_t container_size = (sizeof(uint8_t) * 8);
	std::vector<container_type> masks;
	std::vector<container_type> arr;
	void SetMasks();
};
Bitset operator&(const Bitset& lhs, const Bitset& rhs);
Bitset operator|(const Bitset& lhs, const Bitset& rhs);
Bitset operator^(const Bitset& lhs, const Bitset& rhs);
Bitset operator<<(const Bitset& lhs, const int64_t rhs);
Bitset operator>>(const Bitset& lhs, const int64_t rhs);

std::istream& operator>>(std::istream& istrm, Bitset& rhs);
std::ostream& operator<<(std::ostream& ostrm, const Bitset& rhs);

#endif