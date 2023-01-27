#pragma once
#include <string>

class Encrypt {
public:
	virtual void encode() = 0; // encode the plain text to cipher text
	virtual void decode() = 0; // decode the cipher text to plain text
	std::string plain() const; // return the plain text
	std::string cipher() const; // return the cipher text
	void read(std::string filename, char plain_or_cipher = 'p'); // p for plain, c for cipher
	void write(std::string filename, char plain_or_cipher = 'c'); // p for plain, c for cipher

protected:
	std::string _plain;
	std::string _cipher;
};