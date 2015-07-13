#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include "IPAddress.h"
#include "SubnetMask.h"
#include "SubnetService.h"

int main() {
	try {
		IPAddress address(192, 168, 1, 0);
		SubnetMask subnet_mask(255, 255, 255, 0);
		SubnetService instance;
		vector<int> requirement;

		requirement.push_back(10);
		requirement.push_back(30);
		requirement.push_back(60);
		requirement.push_back(120);

		std::cout << "Address Space: 192.168.1.1" << std::endl << "Subnet Mask: 255.255.255.0" << std::endl << std::endl;

		instance.run(address, subnet_mask, requirement);
		std::cin.get();
	}
	catch (exception& e) {
		std::cout << e.what() << std::endl;
	}
}
