#pragma once

#include <iostream>
#include <list>
#include <tuple>
#include "IPAddress.h"
#include "SubnetMask.h"

using namespace std;

class SubnetService {
	private:
		IPAddress* addressSpace;
		SubnetMask* mask;
		int* subnetRequirements;
		int numOfSubnets;

	public:
		~SubnetService();
		void setAddressSpace(IPAddress* address);
		void setSubnetMask(SubnetMask* subnet_mask);
		void setSubnetRequirements(int* req);
		void setNumOfSubnets(int val);
		list<tuple<IPAddress, IPAddress>> solve();
};

SubnetService::~SubnetService()
{
	delete addressSpace;
	delete mask;
	delete[] subnetRequirements;
}

void SubnetService::setAddressSpace(IPAddress * address)
{
	addressSpace = address;
}

void SubnetService::setSubnetMask(SubnetMask * subnet_mask)
{
	mask = subnet_mask;
}

void SubnetService::setSubnetRequirements(int * req)
{
	subnetRequirements = req;
}

void SubnetService::setNumOfSubnets(int val)
{
	numOfSubnets = val;
}

list<tuple<IPAddress, IPAddress>> SubnetService::solve()
{
	return list<tuple<IPAddress, IPAddress>>();
}