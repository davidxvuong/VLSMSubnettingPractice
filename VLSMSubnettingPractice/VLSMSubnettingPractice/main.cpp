#include <iostream>
#include <bitset>
#include <string>
#include "IPAddress.h"
#include "SubnetMask.h"
#include "SubnetService.h"

int main() {
	IPAddress address(172, 16, 25, 65);
	SubnetMask* subnet_mask = new SubnetMask(255, 255, 255, 255);

	int* ip = address.getAddress();
	
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

	std::cout << address.getAddressAsBinary() << std::endl;

	std::cout << subnet_mask->getAddressAsBinary() << std::endl;

	std::cout << address.getAddressAsUnsignedLongInt() << std::endl;

	std::cout << subnet_mask->getAddressAsUnsignedLongInt() << std::endl;

	address.setAddressAsBinary(std::bitset<32>(2886736193));

	ip = address.getAddress();

	for (int i = 0; i < 4; i++) {
		std::cout << std::bitset<8>(ip[i]);
		if (i != 3) {
			std::cout << ".";
		}
	}

	std::cin.get();

	//delete address;
	delete subnet_mask;
}
