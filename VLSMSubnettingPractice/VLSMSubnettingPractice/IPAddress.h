#pragma once

#include <memory>

//Base Class
class IPAddress {
	private:
		unsigned int *address;
		std::bitset<32> binary_address;
		char classType;
	public:
		IPAddress();
		IPAddress(const IPAddress &obj);
		IPAddress(int first, int second, int third, int fourth);
		~IPAddress();
		void setAddressAsBinary(std::bitset<32> ip_address);
		void setAddressAsUnsignedLongInt(unsigned long int &ip_address);
		void setClassType(int firstOctet);

		char getClassType() const;
		unsigned int* getAddress() const;
		std::bitset<32> getAddressAsBinary() const;
		unsigned long int getAddressAsUnsignedLongInt() const;
		int getFirstOctet() const;
		int getSecondOctet() const;
		int getThirdOctet() const;
		int getFourthOctet() const;
};

IPAddress::IPAddress() {
	address = new unsigned int[4];
	//Empty default onstructor
}

IPAddress::IPAddress(const IPAddress &obj) {
	address = new unsigned int[4];

	for (int i = 0; i < 4; i++) {
		address[i] = obj.address[i];
	}

	classType = obj.classType;
	binary_address = obj.binary_address;
}

IPAddress::IPAddress(int first, int second, int third, int fourth) {
	address = new unsigned int[4];

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

	setClassType(first);
}

IPAddress::~IPAddress() {
	delete[] address;
}

void IPAddress::setClassType(int first) {
	if (first >= 1 && first <= 126)
		classType = 'A';
	else if (first >= 128 && first <= 191)
		classType = 'B';
	else if (first >= 192 && first <= 223)
		classType = 'C';
	else if (first >= 224 && first <= 239)
		classType = 'D';
	else if (first >= 240 && first < 254)
		classType = 'E';
	else
		classType = 'N';		//Loopback address
}

char IPAddress::getClassType() const {
	return classType;
}

unsigned int* IPAddress::getAddress() const {
	return address;
}

std::bitset<32> IPAddress::getAddressAsBinary() const {
	return binary_address;
}

unsigned long int IPAddress::getAddressAsUnsignedLongInt() const
{
	return binary_address.to_ulong();
}

void IPAddress::setAddressAsBinary(std::bitset<32> ip_address)
{
	unsigned long int value = ip_address.to_ulong();
	setAddressAsUnsignedLongInt(value);
}

void IPAddress::setAddressAsUnsignedLongInt(unsigned long int &ip_address)
{
	unsigned long int sweeper = 255;

	for (int i = 3; i >= 0; i--) {
		address[i] = static_cast<int>(ip_address & sweeper);
		sweeper = sweeper << 8;
	}

	int jump = 24;

	for (int i = 0; i < 4; i++) {
		std::bitset<8> t(address[i]);
		for (int j = 7; j >= 0; j--) {
			binary_address[jump + j] = t[j];
		}
		jump -= 8;
	}

	address[0] = address[0] >> 24;
	address[1] = address[1] >> 16;
	address[2] = address[2] >> 8;

	setClassType(address[0]);
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
