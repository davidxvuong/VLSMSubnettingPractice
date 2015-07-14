#include "IPAddress.h"

struct SubnetInformation {
	IPAddress* networkAddress;
	IPAddress* firstUsableAddress;
	IPAddress* lastUsableAddress;
	IPAddress* broadcastAddress;
	IPAddress* subnetMask;
};
