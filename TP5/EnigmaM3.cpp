#include "EnigmaM3.h"
#include "RotorList.h"
#include "PairSwitchList.h"

EnigmaM3::EnigmaM3(std::array<uint, 3> rotors, std::array<uint, 3> offsets, uint reflector, std::vector<std::string> pair_list) :
	_plugboard(PairSwitch(10, pair_list)) {
	for (int i = 0; i < 3; i++) {
		switch (rotors.at(i)) {
		case 1:
			_rotors.at(i) = Rotor(M1_ROTOR, offsets.at(i), { M1_NOTCHES });
			break;
		case 2:
			_rotors.at(i) = Rotor(M2_ROTOR, offsets.at(i), { M2_NOTCHES });
			break;
		case 3:
			_rotors.at(i) = Rotor(M3_ROTOR, offsets.at(i), { M3_NOTCHES });
			break;
		case 4:
			_rotors.at(i) = Rotor(M4_ROTOR, offsets.at(i), { M4_NOTCHES });
			break;
		case 5:
			_rotors.at(i) = Rotor(M5_ROTOR, offsets.at(i), { M5_NOTCHES });
			break;
		case 6:
			_rotors.at(i) = Rotor(M6_ROTOR, offsets.at(i), { M6_NOTCHES });
			break;
		case 7:
			_rotors.at(i) = Rotor(M7_ROTOR, offsets.at(i), { M7_NOTCHES });
			break;
		case 8:
			_rotors.at(i) = Rotor(M8_ROTOR, offsets.at(i), { M8_NOTCHES });
			break;
		default:
			throw std::string("Invalid rotor number");
		}
	}
	switch (reflector){
	case 1:
		_reflector = PairSwitch(-1, UKW_B_ROTOR);
		break;
	case 2:
		_reflector = PairSwitch(-1, UKW_C_ROTOR);
		break;
	default:
		throw std::string("Invalid reflector number");
		break;
	}
}

EnigmaM3::EnigmaM3(std::array<Rotor, 3> rotors, PairSwitch reflector, PairSwitch plugboard) :
	_rotors(rotors), _reflector(reflector), _plugboard(plugboard) {
}
void EnigmaM3::pass_through(std::string& str) {
	for (char& c : str) if (isalpha(c)) {
		_plugboard.pass_through(c);
		for (int i = 0; i < 3; i++) {
			_rotors.at(i).forward(c);
		}
		_reflector.pass_through(c);
		for (int i = 2; i >= 0; i--) {
			_rotors.at(i).backward(c);
		}
		_plugboard.pass_through(c);
		int i = 0;
		while (i < 3 && _rotors.at(i).rotate()) { i++; }
	}
}

void EnigmaM3::encode(){
	_cipher = _plain;
	pass_through(_cipher);
}
void EnigmaM3::decode() {
	_plain = _cipher;
	pass_through(_plain);
}
void EnigmaM3::setOffsets(std::array<uint, 3> offsets) {
	for (int i = 0; i < 3; i++) {
		_rotors.at(i).setOffset(offsets.at(i));
	}
}