#pragma once
#include <string>
#include <vector>

typedef unsigned int uint;
class Rotor
{
public:
	Rotor();
	Rotor(std::string key, uint offset, std::vector<uint> notches);
	bool rotate();
	void setOffset(uint offset);
	void forward(char& c) const;
	void backward(char& c) const;
private:
	std::string _key;
	std::string _reverse_key;
	uint _offset;
	std::vector<uint> _notches;
};




