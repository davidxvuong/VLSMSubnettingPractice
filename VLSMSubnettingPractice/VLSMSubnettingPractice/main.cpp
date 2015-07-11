#include <iostream>
#include <bitset>
#include <string>
#include "IPAddress.h"
#include "SubnetMask.h"

int main() {
	IPAddress* address = new IPAddress(192, 168, 1, 1);
	SubnetMask* subnet_mask = new SubnetMask(255, 255, 255, 255);

	int* ip = address->getAddress();
	
	for (int i = 0; i < 4; i++) {
		std::cout << std::bitset<8>(ip[i]);
		if (i != 3) {
			std::cout << ".";
		}
	}

	std::cout << std::endl;

	int* subnet = subnet_mask->getAddress();

	for (int i = 0; i < 4; i++) {
		std::cout << std::bitset<8>(subnet[i]);
		if (i != 3) {
			std::cout << ".";
		}
	}

	std::cout << std::endl;

	std::cout << address->getAddressInBinary() << std::endl;

	std::cout << subnet_mask->getAddressInBinary() << std::endl;

	std::cout << address->getAddressInInt() << std::endl;

	std::cout << subnet_mask->getAddressInInt() << std::endl;

	std::cin.get();

	delete address;
	delete subnet_mask;
}
