#include "EncryptHelper.h"

bool isMixAlphabet(std::string str) {
	uint32_t check = 0x03ffffff;
	if (str.length() != 26) return false;
	if (str.at(0) >= 'A' && str.at(0) <= 'Z') {
		for (char c : str) {
			if (c < 'A' || c > 'Z') {
				return false;
			}
			else {
				check &= ~(1 << (c - 'A'));
			}
		}
		return check == 0;
	}
	else {
		return false;
	}
}


bool isPairSwitch(int pair_number, std::string str) {
	if (str.length() != 26) return false;
	if (isMajuscule(str.at(0))) {
		int pair_number = 0;
		for (char c : str) {
			if (!isMajuscule(c)) {
				return false;
			}
			else {
				if (str.at(c - 'A') == c);
				else if (str.at(str.at(c - 'A') - 'A') != c) ++pair_number;
				else if (str.at(str.at(c - 'A') - 'A') != c) return false;
			}
		}
		if (pair_number == pair_number ||pair_number == -1) return true;
		else return false;
	}
	else {
		return false;
	}
}

bool isMinuscule(char c) {
	if (c >= 'a' && c <= 'z') return true;
	return false;
}
bool isMajuscule(char c) {
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}
