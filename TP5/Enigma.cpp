#include "Enigma.h"
#include "EncryptHelper.h"


Enigma::Enigma(std::string key, uint offset, std::vector<uint> notches) :
	_rotor(key, offset, notches) {
}
Enigma::Enigma(Rotor rotor) :
	_rotor(rotor) {
}
void Enigma::encode() {
	_cipher = _plain;
	for (char& c : _cipher) {
		_rotor.forward(c);
		_rotor.rotate();
	}
}
void Enigma::decode() {
	_plain = _cipher;
	for (char& c : _plain) {
		_rotor.backward(c);
		_rotor.rotate();
	}
}

void Enigma::setOffset(uint offset) {
	_rotor.setOffset(offset);
}