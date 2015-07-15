// This is the main DLL file.

#include "stdafx.h"
#include "IPAddress.h"
#include "IPAddress.cpp"
#include "SubnetInformation.h"
#include "SubnetService.h"
#include "SubnetService.cpp"

#include "VLSMSubnettingPracticeWrapper.h"

using namespace VLSMSubnettingPracticeWrapper;

SubnetServiceWrapper::SubnetServiceWrapper() {
	subnetServiceInstance = new SubnetService();
}

SubnetServiceWrapper::~SubnetServiceWrapper() {
	delete subnetServiceInstance;
}

IPAddressWrapper::IPAddressWrapper() {
	ipAddressInstance = new IPAddress();
}

IPAddressWrapper::IPAddressWrapper(unsigned long int address) {
	ipAddressInstance = new IPAddress(address);
}

IPAddressWrapper::IPAddressWrapper(std::bitset<32> address) {
	ipAddressInstance = new IPAddress(address);
}

IPAddressWrapper::~IPAddressWrapper() {
	delete ipAddressInstance;
}

void IPAddressWrapper::setAddress(int first, int second, int third, int fourth) {
	ipAddressInstance->setAddress(first, second, third, fourth);
}

void IPAddressWrapper::setClassType(int first) {
	ipAddressInstance->setClassType(first);
}

char IPAddressWrapper::getClassType() {
	return ipAddressInstance->getClassType();
}

unsigned int IPAddressWrapper::getAddress() {
	return *(ipAddressInstance->getAddress());
}

std::bitset<32> IPAddressWrapper::getAddressAsBinary() {
	return ipAddressInstance->getAddressAsBinary();
}

unsigned long int IPAddressWrapper::getAddressAsUnsignedLongInt() {
	return ipAddressInstance->getAddressAsUnsignedLongInt();
}

void IPAddressWrapper::setAddressAsBinary(std::bitset<32> ip_address) {
	ipAddressInstance->setAddressAsBinary(ip_address);
}
//continue here