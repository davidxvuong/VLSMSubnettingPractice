#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include "IPAddress.h"
#include "SubnetInformation.h"

using namespace std;

class SubnetService {
	private:
		char classType;
	public:
		void setClassType(char input);
		list<SubnetInformation*> run(IPAddress &space, vector<unsigned long int> &requirements);
		void solve(list<SubnetInformation*> &list, IPAddress &space, vector <unsigned long int> &requirements);
};

void SubnetService::setClassType(char input) {
	classType = input;
}

list<SubnetInformation*> SubnetService::run(IPAddress &space, vector<unsigned long int> &requirements) {
	list<SubnetInformation*> result;
	solve(result, space, requirements);
	return result;
}

void SubnetService::solve(list<SubnetInformation*> &list, IPAddress &space, vector <unsigned long int> &requirements) {
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
		IPAddress* subnet_mask = new IPAddress();
		bool stop = false;

		while (!stop) {
			subnetSpace = (int)(pow(2.0, (double)(startExp)));

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

		SubnetInformation* data = new SubnetInformation();
		data->networkAddress = networkAddress;
		data->firstUsableAddress = firstUsableAddress;
		data->lastUsableAddress = lastUsableAddress;
		data->broadcastAddress = broadcastAddress;
		data->subnetMask = subnet_mask;

		list.push_back(data);
		requirements.pop_back();

		solve(list, *nextNetworkAddress, requirements);
	}
	else {
		return;
	}
}
