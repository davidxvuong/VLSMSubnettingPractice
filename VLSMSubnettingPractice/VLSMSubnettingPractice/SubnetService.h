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
		list<tuple<IPAddress, IPAddress, IPAddress, IPAddress, SubnetMask>> solve(IPAddress &space, SubnetMask &mask, vector<int> &requirements);
};

list<tuple<IPAddress, IPAddress, IPAddress, IPAddress, SubnetMask>> SubnetService::solve(IPAddress &space, SubnetMask &mask, vector<int> &requirements)
{
	//Format of tuple: Network Address, First Usable Address, Last Usable Address, Broadcast Address, Subnet Mask
	list<tuple<IPAddress, IPAddress, IPAddress, IPAddress, SubnetMask>> result;
	IPAddress* networkAddress = &space;
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

	std::cout << subnetSpace << std::endl;
	std::cout << 32 - startingExponent << std::endl;
	std::cout << currentNetworkBits << std::endl;
	std::cout << newNetworkBits << std::endl;

	return result;
}