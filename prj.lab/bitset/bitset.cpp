#include <iostream>
#include <sstream>
#include <string>
#include "bitset/bitset.h"

//<------------ CONSTRUCTORS ------------->
// //pon
Bitset::Bitset(const std::string& data)
{
	size_ = data.size();
	arr.resize((size_ + container_size - 1) / container_size);

	for (uint64_t i = 0; i < data.size(); i++)
	{
		if (data[i] != '0' && data[i] != '1')
		{
			throw std::invalid_argument("Bitset error: 0 or 1 expected");
		}
		arr[(size_ - i - 1) / container_size] |= ((data[i] - '0') << ((size_ - i - 1) % container_size));
	}
	SetMasks();
}

//pon
Bitset::Bitset(const Bitset& copy)
{
	size_ = copy.size_;
	arr.resize(copy.arr.size());

	for (int i = 0; i < copy.arr.size(); i++) // copy constructor (copies 
	{                                           // an array)
		arr[i] = copy.arr[i];
	}
	SetMasks();
}


//pon
Bitset::Bitset(const int64_t size, const bool filler) {
	if (size < 0) {
		throw std::invalid_argument("Bitset error: Bitset size can not be negative");
	}
	size_ = size;
	arr.resize(size / container_size + 1);
	if (filler)
		for (int i = 0; i < size; i++) {
			arr[i / container_size] |= (1 << ((i) % container_size));
		}
	else
		for (int i = 0; i < size; i++) {
			arr[i / container_size] = 0;
		}
	SetMasks();
}


//------------ SIZES ------------->

//pon
int64_t Bitset::size() const {
	return size_;
}

//pon
bool Bitset::CheckSize(const Bitset& rhs) const
{
	return size_ == rhs.size_;
}

//vrode pon
void Bitset::resize(const int64_t size, const bool filler) {
	int64_t pred_size = int64_t((*this).size());
	int64_t new_size_of_arr = (size + container_size - 1) / container_size;
	arr.resize(new_size_of_arr);
	size_ = size;
	if (pred_size < size) {
		for (int64_t i = pred_size; i < size; ++i) {
			(*this)[i] = bool(filler);
		}
	}
}


//<------------ MASKS ------------->
//pon
void Bitset::SetMasks() {
	masks.resize(container_size);
	container_type mask = 1;
	for (int i = 0; i < masks.size(); i++) {
		masks[i] = mask;
		mask <<= 1;
	}
}


//pon
void Bitset::Fill(const bool filler)
{
	if (filler == 1) {
		for (int i = 0; i < size_; i++) {
			arr[i / container_size] |= (1 << ((i) % container_size));
		}
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = 0;
		}
	}
}

//<------------ BITHOLDER ------------->
//ne pon
Bitset::BitHolder::BitHolder(Bitset* bitset, const uint64_t position) :bitset_(bitset)
{
	container_number_ = position / bitset_->container_size;
	bit_number_ = position % bitset_->container_size;
}

//pon
Bitset::BitHolder Bitset::operator[](const int64_t position)
{
	if (position < 0 || position >= size_)
	{
		throw std::invalid_argument("Bitset error: index out of range");
	}
	return Bitset::BitHolder(this, position);
}

Bitset::BitHolder::operator bool() const
{
	return bool(bitset_->arr[container_number_] & bitset_->masks[bit_number_]);
}

Bitset::BitHolder& Bitset::BitHolder::operator=(const Bitset::BitHolder& rhs)
{
	if (rhs.bitset_->arr[rhs.container_number_] & rhs.bitset_->masks[rhs.bit_number_])
	{
		bitset_->arr[container_number_] |= bitset_->masks[bit_number_];
	}
	else
	{
		bitset_->arr[container_number_] &= ~(bitset_->masks[bit_number_]);
	}

	return *this;
}

Bitset::BitHolder& Bitset::BitHolder::operator=(const bool rhs)
{
	if (rhs)
	{
		bitset_->arr[container_number_] |= bitset_->masks[bit_number_];
	}
	else
	{
		bitset_->arr[container_number_] &= ~(bitset_->masks[bit_number_]);
	}

	return *this;
}

//<---------------- ONE SIDE OPERATOR ------------>
Bitset& Bitset::operator=(const Bitset& rhs) {
	size_ = rhs.size_;
	arr.resize(rhs.arr.size());

	for (int i = 0; i < rhs.arr.size(); i++)
	{
		arr[i] = rhs.arr[i];
	}
	SetMasks();
	return *this;
}

Bitset& Bitset::operator&=(const Bitset& rhs) {
	if (!CheckSize(rhs)) {
		throw std::invalid_argument("Bitset error: sizes of operands do not match");
	}
	for (int i = 0; i < arr.size(); i++) {
		arr[i] &= rhs.arr[i];
	}
	return *this;
}

Bitset& Bitset::operator|=(const Bitset& rhs) {
	if (!CheckSize(rhs)) {
		throw std::invalid_argument("Bitset error: sizes of operands do not match");
	}
	for (int i = 0; i < arr.size(); i++) {
		arr[i] |= rhs.arr[i];
	}
	return *this;
}

Bitset& Bitset::operator^=(const Bitset& rhs)
{
	if (!CheckSize(rhs))
	{
		throw std::invalid_argument("Bitset error: sizes of operands do not match");
	}

	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] ^= rhs.arr[i];
	}
	return *this;
}

Bitset& Bitset::operator<<=(const int64_t shift) {
	if (shift < 0) {
		throw std::invalid_argument("Bitset error : bitwise shift by negative count is undefined");
	}
	for (int64_t i = size_ - 1; i >= shift; i--) {
		(*this)[i] = (*this)[i - shift];
	}
	for (int64_t i = shift - 1; i >= 0; i--) {
		(*this)[i] = false;                     
	}
	return *this;
}

Bitset& Bitset::operator>>=(const int64_t shift)
{
	if (shift < 0)
	{
		throw std::invalid_argument("Bitset error : bitwise shift by negative count is undefined");
	}

	for (int64_t i = 0; i < size_ - shift; i++)
	{
		(*this)[i] = (*this)[i + shift];
	}

	for (int64_t i = size_ - shift; i < size_; i++) {
		(*this)[i] = false;                             
	}
	return *this;
}


//<---------------- TWO SIDES OPERATORS ------------>
Bitset operator&(const Bitset& lhs, const Bitset& rhs) {
	return Bitset(lhs) &= rhs;
}

Bitset operator|(const Bitset& lhs, const Bitset& rhs) {
	return Bitset(lhs) |= rhs;
}

Bitset operator^(const Bitset& lhs, const Bitset& rhs) {	
	return Bitset(lhs) ^= rhs;
}

Bitset operator<<(const Bitset& lhs, const int64_t shift) {
	Bitset copy = Bitset(lhs);
	copy <<= shift;
	return copy;
}

Bitset operator>>(const Bitset& lhs, const int64_t shift) {
	Bitset copy = Bitset(lhs);
	copy >>= shift;
	return copy;
}

Bitset Bitset::operator~() const {
	Bitset ncopy = Bitset(*this);

	for (int i = 0; i < ncopy.size_; i++)
	{
		ncopy[i] = !(ncopy[i]);
	}
	return ncopy;
}

//<------------------------ COMPARING ------------------------->
bool Bitset::operator==(const Bitset& rhs) const {
	if (size_ != rhs.size_) {
		return false;
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] != rhs.arr[i]) {
				return false;
			}
		}
		return true;
	}
}

bool Bitset::operator!=(const Bitset& rhs) const {
	return !(operator==(rhs));
}

bool Bitset::operator[](const int64_t pos) const {
	if ((pos < 0) || (pos >= size_)) {
		throw std::invalid_argument("Bitset error: index out of range");
	}
	return bool(arr[pos / container_size] & masks[pos & container_size]);
}
//<------------------------ iN / OUT ------------------------->
std::istream& operator>>(std::istream& in_place, Bitset& copy) {
	std::string data = "";
	while (in_place.peek() == '0' || in_place.peek() == '1') {
		data.push_back(in_place.get());
	}
	if (data.size() > 0) {
		copy = Bitset(data);
	}
	else {
		in_place.setstate(std::ios_base::failbit);
	}
	return in_place;
}

std::ostream& operator<<(std::ostream& out_place, const Bitset& copy) {
	for (int64_t i = copy.size() - 1; i > 0; i--) {
		out_place << copy[i];
	}
	return out_place;
}

Bitset const operator>>(const Bitset& lhs, const uint64_t rhs) {
	Bitset temp = Bitset(lhs);
	temp >>= rhs;
	return temp;
}
Bitset const operator<<(const Bitset& lhs, const uint64_t rhs) {
	Bitset temp = Bitset(lhs);
	temp <<= rhs;
	return temp;
}