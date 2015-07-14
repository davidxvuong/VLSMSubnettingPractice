#include <iostream>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include "IPAddress.h"
#include "SubnetService.h"

#define MAX_CLASS_A_ADDRESS 16777216
#define MAX_CLASS_B_ADDRESS 65536
#define MAX_CLASS_C_ADDRESS 256
#define CLASS_A_LIMIT 20
#define CLASS_B_LIMIT 15
#define CLASS_C_LIMIT 5


int main() {
	//Object Initialization
	IPAddress* addressSpace = new IPAddress();
	SubnetService* instance = new SubnetService();
	vector <unsigned long int> requirements;
	bool repeat = true;
	system("Color 0a");
	while (repeat) {
		std::cout << "VLSM Subnetting Practice" << std::endl << std::endl;
		std::cout << "I would like to practice (select one of the following):\n\tA) Class A Subnetting\n\tB) Class B Subnetting\n\tC) Class C Subnetting\n";

		bool stop = false;
		char input;
		unsigned long int maxAddressSpace, spaceToSubnet;
		int maxSubnetGenerated;
		int count = 0;

		while (!stop) {
			std::cout << "Enter your choice here: ";

			std::cin >> input;

			input = toupper(input);

			if (input != 'A' && input != 'B' && input != 'C')
				std::cout << std::endl << input << " is not a valid option!" << std::endl;
			else {
				instance->setClassType(input);
				std::cout << "\nYou selected Class " << input << " subnetting.\n" << std::endl;
				stop = true;
			}
		}

		if (input == 'A'){
			addressSpace->setAddress(10, 0, 0, 0);
			maxAddressSpace = MAX_CLASS_A_ADDRESS;
			spaceToSubnet = MAX_CLASS_A_ADDRESS;
			maxSubnetGenerated = CLASS_A_LIMIT;
			std::cout << "Given an IP Address 10.0.0.0 with subnet mask 255.0.0.0 and the following subnet requirements:\n\n";
		}
		else if (input == 'B'){
			addressSpace->setAddress(172, 16, 0, 0);
			maxAddressSpace = MAX_CLASS_B_ADDRESS;
			spaceToSubnet = MAX_CLASS_B_ADDRESS;
			maxSubnetGenerated = CLASS_B_LIMIT;
			std::cout << "Given an IP Address 172.16.0.0 with subnet mask 255.255.0.0 and the following subnet requirements:\n\n";
		}
		else{
			addressSpace->setAddress(192, 168, 1, 0);
			maxAddressSpace = MAX_CLASS_C_ADDRESS;
			spaceToSubnet = MAX_CLASS_C_ADDRESS;
			maxSubnetGenerated = CLASS_C_LIMIT;
			std::cout << "Given an IP Address 192.168.1.0 with subnet mask 255.255.255.0 and the following subnet requirements:\n\n";
		}


		srand(time(NULL));

		while (spaceToSubnet > 2) {
			unsigned long int value = rand() % (spaceToSubnet / 2) + 2;
			std::cout << value << std::endl;
			requirements.push_back(value);

			bool stop = false;
			int startExp = 1;
			int subnetSpace = 0;

			while (!stop) {
				subnetSpace = (int)(pow(2, startExp));

				if (subnetSpace - 2 >= value)
					stop = true;
				else
					startExp++;
			}

			spaceToSubnet -= subnetSpace;

			if (count == maxSubnetGenerated) {
				break;
			}
			else {
				count++;
			}
		}
		std::sort(requirements.begin(), requirements.end());
		std::cout << "Find the most optimal addressing scheme for these subnets.\n" << std::endl;

		system("pause");

		list<SubnetInformation*> result = instance->run(*addressSpace, requirements);
		SubnetInformation* data = new SubnetInformation();
		std::cout << "\nSolution\n\nNet. Address\tFirst Usable\tLast Usable\tBroad. Address\tSubnet Mask" << std::endl << std::endl;

		while (result.size() > 0) {
			data = result.front();
			result.pop_front();

			IPAddress* subnetData[] = { data->networkAddress, data->firstUsableAddress, data->lastUsableAddress, data->broadcastAddress, data->subnetMask };

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
		}
		
		bool check = true;
		while (check) {
			std::cout << "\nRestart (Y/N)?";
			std::cin >> input;

			if (toupper(input) == 'N') {
				repeat = false;
				check = false;
			}
			else if (toupper(input) == 'Y') {
				break;
			}

		}
	}

	delete addressSpace;
	delete instance;
}
