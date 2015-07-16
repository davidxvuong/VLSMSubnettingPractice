// VLSMSubnettingPracticeWrapper.h

#pragma once
#include "Unmanaged\SubnetInformation.h"
#include "Unmanaged\IPAddress.h"
#include "Unmanaged\IPAddress.cpp"
#include "Unmanaged\SubnetService.h"
#include "Unmanaged\SubnetService.cpp"

using namespace System;
using namespace System::Collections::Generic;

namespace VLSMSubnettingPracticeWrapper {

	public ref class IPAddressWrapper
	{
		public:
			IPAddressWrapper();
			~IPAddressWrapper();
			void setAddress(int first, int second, int third, int fourth);
			String^ getAddress();
			int getFirstOctet();
			int getSecondOctet();
			int getThirdOctet();
			int getFourthOctet();
			IPAddress* getNativeIPAddressPointer();

		private:
			IPAddress* ipAddressInstance;
	};

	public ref class SubnetServiceWrapper {
		public:
			SubnetServiceWrapper();
			~SubnetServiceWrapper();
			void setClassType(char input);
			List<String^>^ run(IPAddressWrapper space, unsigned long int* requirements, int requirementsLength);
		private:
			SubnetService* subnetServiceInstance;
	};
}
