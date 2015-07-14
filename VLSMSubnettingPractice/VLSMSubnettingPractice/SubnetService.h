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
		list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> run(IPAddress &space, vector<int> &requirements);
		void solve(list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> &list, IPAddress &space, vector<int> &requirements);
};

list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> SubnetService::run(IPAddress &space, vector<int> &requirements)
{
	//Format of tuple: Network Address, First Usable Address, Last Usable Address, Broadcast Address, Subnet Mask
	list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> result;
	
	solve(result, space, requirements);

	return result;
}

void SubnetService::solve(list<tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*>> &list, IPAddress &space, vector<int> &requirements) {
	if (requirements.size() > 0) {
		int startExp = 1;
		int subnetSpace;
		int subnetRequirement = requirements.back();
		std::bitset<32> newSubnetMask;
		IPAddress* networkAddress(&space);
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

		for (int i = 31; i >= startExp; i--) {
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
		
		std::tuple<IPAddress*, IPAddress*, IPAddress*, IPAddress*, SubnetMask*> subnetData(networkAddress, firstUsableAddress, lastUsableAddress, broadcastAddress, subnet_mask);
		list.push_back(subnetData);
		requirements.pop_back();

		solve(list, *nextNetworkAddress, requirements);

	}
	else {
		return;
	}
}