#include <iostream>
#include "Enigma.h"
#include "Enigma2.h"

int main() {

	std::string default_key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string key = "AQWXSZEDCVFRTGBNHYUJKIOLMP";
	Enigma clear(default_key);
	Enigma cipher(key);
	Enigma2 enigma2({ default_key, key });
	
	std::cout << "default : " << std::endl;
	clear.read("plain.txt", 'p');
	clear.encode();
	clear.write("cipher_default.txt", 'c');
	std::cout << clear.plain() << std::endl << "-----" << std::endl << clear.cipher() << std::endl;
	std::cout << "----------" << std::endl;
	clear.setOffset(0);
	clear.read("cipher_default.txt", 'c');
	clear.decode();
	clear.write("plain_default.txt", 'p');
	std::cout << clear.plain() << std::endl << "-----" << std::endl << clear.cipher() << std::endl;
	std::cout << "----------" << std::endl;
	
	std::cout << "cipher : " << std::endl;
	cipher.read("plain.txt", 'p');
	cipher.encode();
	cipher.write("cipher_cipher.txt", 'c');
	std::cout << cipher.plain() << std::endl << "-----" << std::endl << cipher.cipher() << std::endl;
	std::cout << "----------" << std::endl;
	cipher.setOffset(0);
	cipher.read("cipher_cipher.txt", 'c');
	cipher.decode();
	cipher.write("plain_cipher.txt", 'p');
	std::cout << cipher.plain() << std::endl << "-----" << std::endl << cipher.cipher() << std::endl;
	std::cout << "----------" << std::endl;

	std::cout << "enigma2 : " << std::endl;
	enigma2.read("plain.txt", 'p');
	enigma2.encode();
	enigma2.write("cipher_enigma2.txt", 'c');
	std::cout << enigma2.plain() << std::endl << "-----" << std::endl << enigma2.cipher() << std::endl;
	std::cout << "----------" << std::endl;
	enigma2.setOffsets({ 0, 0 });
	enigma2.read("cipher_enigma2.txt", 'c');
	enigma2.decode();
	enigma2.write("plain_enigma2.txt", 'p');
	std::cout << enigma2.plain() << std::endl << "-----" << std::endl << enigma2.cipher() << std::endl;
	
	return 0;
}