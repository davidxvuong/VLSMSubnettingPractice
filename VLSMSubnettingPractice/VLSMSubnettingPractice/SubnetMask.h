#pragma once

#include "IPAddress.h"

//Derived Class
class SubnetMask : public IPAddress {
public:
	SubnetMask(int first, int second, int third, int fourth) :IPAddress(first, second, third, fourth) {};
	SubnetMask() :IPAddress(){};
};