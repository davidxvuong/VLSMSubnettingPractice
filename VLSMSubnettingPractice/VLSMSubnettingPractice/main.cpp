#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include "IPAddress.h"
#include "SubnetMask.h"
#include "SubnetService.h"

int main() {
	try {
		IPAddress address(172, 16, 0, 0);
		SubnetMask subnet_mask(255, 255, 0, 0);
		SubnetService instance;
		vector<int> requirement;

		requirement.push_back(10);
		requirement.push_back(30);
		requirement.push_back(60);
		requirement.push_back(120);
		requirement.push_back(500);
		requirement.push_back(2000);
		requirement.push_back(8100);
		requirement.push_back(15859);

		list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> result = instance.run(address, requirement);

		tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*> data;

		std::cout << "Net. Address\tFirst Usable\tLast Usable\tBroad. Address\tSubnet Mask" << std::endl << std::endl;

		while (result.size() > 0) {
			data = result.front();
			result.pop_front();

			IPAddress* subnetData[] = { std::get<0>(data), std::get<1>(data), std::get<2>(data), std::get<3>(data), std::get<4>(data) };

			for (int i = 0; i < 5; i++) {
				unsigned int* ipAddress = subnetData[i]->getAddress();

				for (int j = 0; j < 4; j++) {
					std::cout << ipAddress[j];
					if (j != 3)
						std::cout << ".";
					else
						std::cout << "\t";
				}

			}

			std::cout << std::endl;
		}
		std::cin.get();
	}
	catch (exception& e) {
		std::cout << e.what() << std::endl;
	}
}
