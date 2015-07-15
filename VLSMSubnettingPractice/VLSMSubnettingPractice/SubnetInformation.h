#pragma once
#include "IPAddress.h"

//This structure is used to hold the information of a subnet. 
struct SubnetInformation {
	IPAddress* networkAddress;
	IPAddress* firstUsableAddress;
	IPAddress* lastUsableAddress;
	IPAddress* broadcastAddress;
	IPAddress* subnetMask;
};
