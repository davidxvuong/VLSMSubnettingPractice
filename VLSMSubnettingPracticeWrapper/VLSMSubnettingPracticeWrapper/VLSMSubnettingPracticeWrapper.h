// VLSMSubnettingPracticeWrapper.h

#pragma once
#include "IPAddress.h"
#include "IPAddress.cpp"
#include "SubnetInformation.h"
#include "SubnetService.h"
#include "SubnetService.cpp"

using namespace System;

namespace VLSMSubnettingPracticeWrapper {

	public ref class SubnetServiceWrapper
	{
		public:
			SubnetServiceWrapper();
			~SubnetServiceWrapper();
		private:
			SubnetService* subnetServiceInstance;
	};

	public ref class IPAddressWrapper
	{
		public:
			IPAddressWrapper();
			IPAddressWrapper(unsigned long int address);
			IPAddressWrapper(std::bitset<32> address);
			~IPAddressWrapper();

			void setAddress(int first, int second, int third, int fourth);
			void setAddressAsBinary(std::bitset<32> ip_address);
			void setAddressAsUnsignedLongInt(unsigned long int &ip_address);
			void setClassType(int firstOctet);

			char getClassType();
			unsigned int getAddress();
			std::bitset<32> getAddressAsBinary();
			unsigned long int getAddressAsUnsignedLongInt();
			int getFirstOctet();
			int getSecondOctet();
			int getThirdOctet();
			int getFourthOctet();
		private:
			IPAddress* ipAddressInstance;
	};
}
