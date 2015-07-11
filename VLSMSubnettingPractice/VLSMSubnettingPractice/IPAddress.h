#pragma once

//Base Class
class IPAddress {
	private:
		int* address;
		std::bitset<32> binary_address;
	public:
		IPAddress(int first, int second, int third, int fourth);
		~IPAddress();
		int* getAddress() const;
		std::bitset<32> getAddressInBinary() const;
		unsigned long int getAddressInInt() const;
		int getFirstOctet() const;
		int getSecondOctet() const;
		int getThirdOctet() const;
		int getFourthOctet() const;
};

IPAddress::IPAddress(int first, int second, int third, int fourth) {
	address = new int[4];

	address[0] = first;
	address[1] = second;
	address[2] = third;
	address[3] = fourth;

	int jump = 24;

	for (int i = 0; i < 4; i++) {
		std::bitset<8> t(address[i]);
		for (int j = 7; j >= 0; j--) {
			binary_address[jump + j] = t[j];
		}
		jump -= 8;
	}

	
}

IPAddress::~IPAddress() {
	delete[] address;
}

int* IPAddress::getAddress() const {
	return address;
}

std::bitset<32> IPAddress::getAddressInBinary() const {
	return binary_address;
}

unsigned long int IPAddress::getAddressInInt() const
{
	return binary_address.to_ulong();
}

int IPAddress::getFirstOctet() const {
	return address[0];
}

int IPAddress::getSecondOctet() const {
	return address[1];
}

int IPAddress::getThirdOctet() const {
	return address[2];
}

int IPAddress::getFourthOctet() const {
	return address[3];
}


//Derived Class
class SubnetMask : public IPAddress {
	public:
		SubnetMask(int first, int second, int third, int fourth) :IPAddress(first, second, third, fourth) {};
};