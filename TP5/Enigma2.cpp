#include "Enigma2.h"
#include "EncryptHelper.h"

Enigma2::Enigma2(std::array<std::string, 2> keys, std::array<uint, 2> offsets, std::array<std::vector<uint>, 2> notches):
	_rotors({ Rotor(keys.at(0), offsets.at(0), notches.at(0)),Rotor(keys.at(1), offsets.at(1), notches.at(1)) }) {
}
Enigma2::Enigma2(std::array<Rotor, 2> rotors) :
	_rotors(rotors) {
}
void Enigma2::encode() {
	_cipher = _plain;
	for (char& c : _cipher) {
		_rotors.at(0).forward(c);
		_rotors.at(1).forward(c);
		if (_rotors.at(0).rotate())
			_rotors.at(1).rotate();
	}
}

void Enigma2::decode() {
	_plain = _cipher;
	for (char& c : _plain) {
		_rotors.at(1).backward(c);
		_rotors.at(0).backward(c);
		if (_rotors.at(0).rotate())
			_rotors.at(1).rotate();
	}
}

void Enigma2::setOffsets(std::array<uint,2> offsets) {
	_rotors.at(0).setOffset(offsets.at(0));
	_rotors.at(1).setOffset(offsets.at(1));
}