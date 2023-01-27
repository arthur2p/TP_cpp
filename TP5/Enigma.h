#pragma once
#include <string>
#include "Rotor.h"
#include "Encrypt.h"

class Enigma : public Encrypt
{
public:
	Enigma(std::string key, uint offset = 0, std::vector<uint> notches = { 0 });
	Enigma(Rotor rotor);
	void encode() override;
	void decode() override;
	void setOffset(uint offset);
private:
	Rotor _rotor;
	
};

