#pragma once
#include <bitset>
#include "SubnetInformation.h"
#include "SubnetService.h"

//Stores the class Type Associated with the address
void SubnetService::setClassType(char input) {
	classType = input;
}

//Starts the recursive algorithm to solve for the proper addressing scheme and returns the result from the algorithm
list<SubnetInformation*> SubnetService::run(IPAddress &space, vector<unsigned long int> &requirements) {
	list<SubnetInformation*> result;
	solve(result, space, requirements);
	return result;
}

//This function determines the appropriate addressing space from the requirements list, and solves for the network address,
//first usable address, last usable address, broadcast address, and subnet mask of each subnet.
void SubnetService::solve(list<SubnetInformation*> &list, IPAddress &space, vector <unsigned long int> &requirements) {
	if (requirements.size() > 0) {
		//Initialization
		int startExp = 1;
		int subnetSpace;
		int subnetRequirement = requirements.back();
		std::bitset<32> newSubnetMask;
		bool stop = false;

		//Iterate through until we find a proper size that fits the subnet requirement. Turn on all host bits.
		while (!stop) {
			subnetSpace = (int)(pow(2.0, (double)(startExp)));
			newSubnetMask[startExp - 1] = 1;

			if (subnetSpace - 2 >= subnetRequirement)
				stop = true;
			else
				startExp++;
		}

		//Toggle bits to get network bits.
		newSubnetMask.flip();

		//Calculation of the broadcast address, first usable address, last usable address, and the next network address for the next subnet
		unsigned long int nextNetworkAddressInt = space.getAddressAsUnsignedLongInt() + subnetSpace;
		unsigned long int broadcastAddressInt = nextNetworkAddressInt - 1;
		unsigned long int lastUsableAddressInt = broadcastAddressInt - 1;
		unsigned long int firstUsableAddressInt = space.getAddressAsUnsignedLongInt() + 1;

		//Storage of subnet information and push it onto the list
		SubnetInformation* data = new SubnetInformation();
		data->networkAddress = &space;
		data->firstUsableAddress = new IPAddress(firstUsableAddressInt);
		data->lastUsableAddress = new IPAddress(lastUsableAddressInt);
		data->broadcastAddress = new IPAddress(broadcastAddressInt);
		data->subnetMask = new IPAddress(newSubnetMask);

		list.push_back(data);
		requirements.pop_back();

		//Recursivly solve for the rest of the subnet information
		solve(list, *(new IPAddress(nextNetworkAddressInt)), requirements);
	}
	else {
		return;
	}
}
