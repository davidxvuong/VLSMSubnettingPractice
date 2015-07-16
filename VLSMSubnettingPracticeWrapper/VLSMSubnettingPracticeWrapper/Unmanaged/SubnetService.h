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
		void solve(list<SubnetInformation*> &list, IPAddress &space, vector <unsigned long int> &requirements);
	public:
		void setClassType(char input);
		list<SubnetInformation*> run(IPAddress &space, vector<unsigned long int> &requirements);
};
