// This is the main DLL file.

#include "stdafx.h"

#include <vector>
#include <algorithm>
#include "VLSMSubnettingPracticeWrapper.h"
#include "Unmanaged\SubnetInformation.h"
#include "Unmanaged\IPAddress.h"
#include "Unmanaged\IPAddress.cpp"
#include "Unmanaged\SubnetService.h"
#include "Unmanaged\SubnetService.cpp"

using namespace VLSMSubnettingPracticeWrapper;

IPAddressWrapper::IPAddressWrapper() {
	ipAddressInstance = new IPAddress();
}

IPAddressWrapper::~IPAddressWrapper() {
	delete ipAddressInstance;
}

void IPAddressWrapper::setAddress(int first, int second, int third, int fourth) {
	ipAddressInstance->setAddress(first, second, third, fourth);
}

String^ IPAddressWrapper::getAddress() {
	unsigned int* address = ipAddressInstance->getAddress();
	String^ returnValue;

	for (int i = 0; i < 4; i++) {
		returnValue += address[i].ToString();
		if (i != 3) {
			returnValue += ".";
		}
	}

	return returnValue;
}

int IPAddressWrapper::getFirstOctet() {
	return ipAddressInstance->getFirstOctet();
}

int IPAddressWrapper::getSecondOctet() {
	return ipAddressInstance->getSecondOctet();
}

int IPAddressWrapper::getThirdOctet() {
	return ipAddressInstance->getThirdOctet();
}

int IPAddressWrapper::getFourthOctet() {
	return ipAddressInstance->getFourthOctet();
}

IPAddress* IPAddressWrapper::getNativeIPAddressPointer() {
	return ipAddressInstance;
}

SubnetServiceWrapper::SubnetServiceWrapper() {
	subnetServiceInstance = new SubnetService();
}

SubnetServiceWrapper::~SubnetServiceWrapper() {
	delete subnetServiceInstance;
}

void SubnetServiceWrapper::setClassType(char input) {
	subnetServiceInstance->setClassType(input);
}

List<String^>^ SubnetServiceWrapper::run(IPAddressWrapper space, unsigned long int* requirements, int requirementsLength) {
	List<String^>^ result;
	IPAddress* getPointer = space.getNativeIPAddressPointer();
	vector<unsigned long int> subnetRequirement;

	for (int i = 0; i < requirementsLength; i++) {
		subnetRequirement.push_back(requirements[i]);
	}

	//Temporary - will implement sorting algorithm later
	std::sort(subnetRequirement.begin(), subnetRequirement.end());

	std::list<SubnetInformation*> nativeCppResult = subnetServiceInstance->run(*getPointer, subnetRequirement);
	int size = nativeCppResult.size();
	SubnetInformation* data;
	String^ manipulatedData;

	for (int j = 0; j < size; j++) {
		data = nativeCppResult.front();
		manipulatedData = "";

		manipulatedData += data->networkAddress->getFirstOctet() + "." + data->networkAddress->getSecondOctet() + "." + data->networkAddress->getThirdOctet() + "." + data->networkAddress->getFourthOctet() + ";";
		manipulatedData += data->firstUsableAddress->getFirstOctet() + "." + data->firstUsableAddress->getSecondOctet() + "." + data->firstUsableAddress->getThirdOctet() + "." + data->firstUsableAddress->getFourthOctet() + ";";
		manipulatedData += data->lastUsableAddress->getFirstOctet() + "." + data->lastUsableAddress->getSecondOctet() + "." + data->lastUsableAddress->getThirdOctet() + "." + data->lastUsableAddress->getFourthOctet() + ";";
		manipulatedData += data->broadcastAddress->getFirstOctet() + "." + data->broadcastAddress->getSecondOctet() + "." + data->broadcastAddress->getThirdOctet() + "." + data->broadcastAddress->getFourthOctet() + ";";
		manipulatedData += data->subnetMask->getFirstOctet() + "." + data->subnetMask->getSecondOctet() + "." + data->subnetMask->getThirdOctet() + "." + data->subnetMask->getFourthOctet();

		result->Add(manipulatedData);
	}

	delete data;
	return result;
}
