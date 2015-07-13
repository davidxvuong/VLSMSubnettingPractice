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
	int subnet = requirements.back();
	int startingExponent = 1;
	int subnetRequirement;
	bool stop = false;

	while (!stop) {
		subnetRequirement = (int)(pow(2, startingExponent) - 2);
		if (subnetRequirement > subnet) {
			stop = true;
		}
		else {
			startingExponent++;
		}
	}

	std::cout << subnetRequirement << std::endl;

	return result;
}