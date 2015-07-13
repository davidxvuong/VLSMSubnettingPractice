#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include "IPAddress.h"
#include "SubnetMask.h"
#include "SubnetService.h"

int main() {
	try {
		IPAddress address(10, 168, 25, 65);
		SubnetMask* subnet_mask = new SubnetMask(255, 255, 255, 0);
		SubnetService _instance;
		vector<int> requirement;

		requirement.push_back(2000);

		unsigned int* ip = address.getAddress();

		for (int i = 0; i < 4; i++) {
			std::cout << ip[i];
			if (i != 3) {
				std::cout << ".";
			}
		}

		std::cout << std::endl << address.getClassType() << std::endl;

		unsigned int* subnet = subnet_mask->getAddress();

		for (int i = 0; i < 4; i++) {
			std::cout << subnet[i];
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
			std::cout << ip[i];
			if (i != 3) {
				std::cout << ".";
			}
		}

		std::cout << std::endl << address.getClassType() << std::endl;

		std::cout << address.getFirstOctet() << "." << address.getSecondOctet() << "." << address.getThirdOctet() << "." << address.getFourthOctet() << std::endl;

		std::list<std::tuple<IPAddress, IPAddress, IPAddress, IPAddress, SubnetMask>> t = _instance.solve(address, *subnet_mask, requirement);

		std::cin.get();

		//delete address;
		delete subnet_mask;
	}
	catch (exception& e) {
		std::cout << e.what() << std::endl;
	}
}
