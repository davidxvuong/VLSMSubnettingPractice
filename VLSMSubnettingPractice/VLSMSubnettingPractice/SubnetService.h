#pragma once

#include <iostream>
#include <list>
#include <tuple>
#include <vector>
#include <cmath>
#include "IPAddress.h"
#include "SubnetMask.h"

using namespace std;

class SubnetService {
	public:
		list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> run(IPAddress &space, SubnetMask &mask, vector<int> &requirements);
		void solve(list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> &list, IPAddress &space, SubnetMask &mask, vector<int> &requirements);
};

list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> SubnetService::run(IPAddress &space, SubnetMask &mask, vector<int> &requirements)
{
	//Format of tuple: Network Address, First Usable Address, Last Usable Address, Broadcast Address, Subnet Mask
	list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> result;
	/*IPAddress* networkAddress = &space;
	int subnetRequirement = requirements.back();
	int startingExponent = 1;
	int subnetSpace;
	std::bitset<32> currentNetworkBits = mask.getAddressAsBinary();
	std::bitset<32> newNetworkBits;
	
	bool stop = false;

	while (!stop) {
		subnetSpace = (int)(pow(2, startingExponent));
		if (subnetSpace - 2 > subnetRequirement) {
			stop = true;
		}
		else {
			startingExponent++;
		}
	}

	for (int i = 31; i >= startingExponent; i--) {
		newNetworkBits[i] = 1;
	}

	unsigned long int t = networkAddress->getAddressAsUnsignedLongInt();

	t += subnetSpace;

	networkAddress->setAddressAsUnsignedLongInt(t);

	std::cout << subnetSpace << std::endl;
	std::cout << 32 - startingExponent << std::endl;
	std::cout << currentNetworkBits << std::endl;
	std::cout << newNetworkBits << std::endl;
	std::cout << networkAddress->getFirstOctet() << "." << networkAddress->getSecondOctet() << "." <<
		networkAddress->getThirdOctet() << "." << networkAddress->getFourthOctet() << std::endl;*/

	solve(result, space, mask, requirements);

	return result;
}

void SubnetService::solve(list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> &list, IPAddress &space, SubnetMask &mask, vector<int> &requirements) {
	if (requirements.size() > 0) {
		int startExp = 1;
		int subnetSpace;
		int subnetRequirement = requirements.back();
		std::bitset<32> newSubnetMask;
		IPAddress networkAddress(space);
		IPAddress* nextNetworkAddress = new IPAddress();
		IPAddress* firstUsableAddress = new IPAddress();
		IPAddress* lastUsableAddress = new IPAddress();
		IPAddress* broadcastAddress = new IPAddress();
		SubnetMask* subnet_mask = new SubnetMask();
		bool stop = false;

		while (!stop) {
			subnetSpace = (int)(pow(2, startExp));

			if (subnetSpace - 2 >= subnetRequirement)
				stop = true;
			else
				startExp++;
		}

		for (int i = 31; i > startExp; i--) {
			newSubnetMask[i] = 1;
		}


		unsigned long int nextNetworkAddressInt = space.getAddressAsUnsignedLongInt() + subnetSpace;
		unsigned long int broadcastAddressInt = nextNetworkAddressInt - 1;
		unsigned long int lastUsableAddressInt = broadcastAddressInt - 1;
		unsigned long int firstUsableAddressInt = space.getAddressAsUnsignedLongInt() + 1;

		nextNetworkAddress->setAddressAsUnsignedLongInt(nextNetworkAddressInt);
		firstUsableAddress->setAddressAsUnsignedLongInt(firstUsableAddressInt);
		lastUsableAddress->setAddressAsUnsignedLongInt(lastUsableAddressInt);
		broadcastAddress->setAddressAsUnsignedLongInt(broadcastAddressInt);
		subnet_mask->setAddressAsBinary(newSubnetMask);
		
		std::tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*> subnetData(&networkAddress, firstUsableAddress, lastUsableAddress, broadcastAddress, subnet_mask);
		list.push_back(subnetData);
		requirements.pop_back();

		std::cout << "Network Address for Subnet: ";
		unsigned int* t = space.getAddress();
		for (int i = 0; i < 4; i++) {
			std::cout << t[i];

			if (i != 3){
				std::cout << ".";
			}
		}

		std::cout << std::endl;

		std::cout << "First Usable Address for Subnet: ";

		t = firstUsableAddress->getAddress();
		for (int i = 0; i < 4; i++) {
			std::cout << t[i];

			if (i != 3){
				std::cout << ".";
			}
		}

		std::cout << std::endl;

		std::cout << "Last Usable Address for Subnet: ";

		t = lastUsableAddress->getAddress();
		for (int i = 0; i < 4; i++) {
			std::cout << t[i];

			if (i != 3){
				std::cout << ".";
			}
		}

		std::cout << std::endl;

		std::cout << "Broadcast Address for Subnet: ";

		t = broadcastAddress->getAddress();
		for (int i = 0; i < 4; i++) {
			std::cout << t[i];

			if (i != 3){
				std::cout << ".";
			}
		}

		std::cout << std::endl << std::endl;

		solve(list, *nextNetworkAddress, *subnet_mask, requirements);

	}
	else {
		return;
	}
}