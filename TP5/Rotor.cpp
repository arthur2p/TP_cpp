#include "Rotor.h"
#include "EncryptHelper.h"

Rotor::Rotor() :
	_key("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), _reverse_key("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), _offset(0), _notches({ 0 }){
}
Rotor::Rotor(std::string key, uint offset, std::vector<uint> notches) :
	_offset(offset % 26) {
	if (isMixAlphabet(key)) {
		_key = key;
		_reverse_key = "";
		for (char c = 'A'; c <= 'Z'; ++c) 
			_reverse_key += (char)('A' + _key.find(c));
		}
	else
		throw std::string("Key must be a mix of the alphabet");
	for (auto notch : notches)
		_notches.push_back(notch % 26);
}
bool Rotor::rotate() {
	++_offset %= 26;
	for (auto notch : _notches)
		if (notch == _offset)
			return true;
	return false;
}
void Rotor::setOffset(uint offset) {
	_offset = offset % 26;
}
void Rotor::forward(char& c) const {
	if (isMinuscule(c)) {
		c = _key.at((c - 'a' + _offset) % 26) - 'A' + 'a';
	}
	else if (isMajuscule(c)) {
		c = _key.at((c - 'A' + _offset) % 26);
	}
}
void Rotor::backward(char& c) const {
	if (isMinuscule(c)) {
		c = (_reverse_key.at(c - 'a') - _offset - 'A');
		c = c < 0 ? c + 26 + 'a' : c + 'a';
	}
	else if (isMajuscule(c)) {
		c = (_reverse_key.at(c - 'A') - _offset - 'A');
		c = c < 0 ? c + 26 + 'A' : c + 'A';
	}
}