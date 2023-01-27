#include "PairSwitch.h"
#include "EncryptHelper.h"


PairSwitch::PairSwitch(int pair_number) : 
	_pair_number(_pair_number),
	_key("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
	_check_pair_number();
}


PairSwitch::PairSwitch(int pair_number, std::string key) :
	_pair_number(pair_number), _key(key) {
	_check_pair_number();
	if (isMixAlphabet(_key))
		if (isPairSwitch(pair_number, _key))
			return;
		else
			throw std::string("Key must be an switch of pair");
	throw std::string("Key must be a mix of the alphabet");
}

PairSwitch::PairSwitch(int pair_number, std::vector<std::string> pair_list) :
	_pair_number(pair_number) {
	_check_pair_number();
	if (_pair_number == -1)
		throw std::string("Constructor not available with no pair number set");
	if (pair_list.size() != _pair_number)
		throw std::string("Amount of pair is not right");
	_key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (auto pair : pair_list) {
		if (pair.length() != 2)
			throw std::string("Pair must have two letter");
		if (pair.at(0) == pair.at(1))
			throw std::string("Pair must have different letter");
		if (_key.at(pair.at(0) - 'A') != pair.at(0) || _key.at(pair.at(1) - 'A') != pair.at(1))
			throw std::string("Pairs overlap");
		_key.at(pair.at(0) - 'A') = pair.at(1);
		_key.at(pair.at(1) - 'A') = pair.at(0);
	}
}


void PairSwitch::pass_through(char& c) const{
	if (isMinuscule(c))
		c = _key.at(c - 'a') - 'A' + 'a';
	else if (isMajuscule(c))
		c = _key.at(c - 'A');
		
}

bool PairSwitch::operator=(const PairSwitch& other) {
	return _key == other._key && _pair_number == other._pair_number;
}

void PairSwitch::_check_pair_number() {
	if (_pair_number < -1 || _pair_number > 13)
		throw std::string("Invalide pair number");
}