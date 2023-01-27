#pragma once
#include <string>
#include <vector>
#include "EncryptHelper.h"

class PairSwitch //pair number at -1 for reflector, 10 for plugboard
{
public:
	PairSwitch(int pair_number = 0);
	PairSwitch(int pair_number, std::string key);
	PairSwitch(int pair_number, std::vector<std::string> pair_list);
	void pass_through(char& c) const;
	bool operator=(const PairSwitch& other);
private:
	void _check_pair_number();
	std::string _key;
	int _pair_number;
};

