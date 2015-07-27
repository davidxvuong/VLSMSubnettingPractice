#include "ipaddress.h"

//Constructors
IPAddress::IPAddress() {
    address = new unsigned int[4];
}

IPAddress::IPAddress(unsigned long int addressAsInt) {
    address = new unsigned int[4];
    setAddressAsUnsignedLongInt(addressAsInt);
}

IPAddress::IPAddress(std::bitset<32> addressInBinary) {
    address = new unsigned int[4];
    setAddressAsBinary(addressInBinary);
}

IPAddress::IPAddress(const IPAddress &obj) {
    address = new unsigned int[4];

    for (int i = 0; i < 4; i++) {
        address[i] = obj.address[i];
    }

    classType = obj.classType;
    binary_address = obj.binary_address;
}

//Deallocate address space when done
IPAddress::~IPAddress() {
    delete[] address;
}

//Sets the IP address based on the octets passed in
void IPAddress::setAddress(int first, int second, int third, int fourth) {
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

//This function stores the class type based on the first octet of the IP Address
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

//Returns class type of the address
char IPAddress::getClassType() const {
    return classType;
}

//Retrieves the address array
unsigned int* IPAddress::getAddress() const {
    return address;
}

//Retrieves the address in binary format
std::bitset<32> IPAddress::getAddressAsBinary() const {
    return binary_address;
}

//Retrieves the address in a long integer format
unsigned long int IPAddress::getAddressAsUnsignedLongInt() const
{
    return binary_address.to_ulong();
}

//Sets address in the binary form
void IPAddress::setAddressAsBinary(std::bitset<32> ip_address)
{
    unsigned long int value = ip_address.to_ulong();
    setAddressAsUnsignedLongInt(value);
}

//Sets address in the long integer form
void IPAddress::setAddressAsUnsignedLongInt(unsigned long int &ip_address)
{
    unsigned long int sweeper = 255;

    for (int i = 3; i >= 0; i--) {
        unsigned int t = ip_address & sweeper;
        address[i] = static_cast<unsigned int>(t);
        sweeper = sweeper << 8;
    }

    address[0] = address[0] >> 24;
    address[1] = address[1] >> 16;
    address[2] = address[2] >> 8;


    int jump = 24;

    for (int i = 0; i < 4; i++) {
        std::bitset<8> t(address[i]);
        for (int j = 7; j >= 0; j--) {
            binary_address[jump + j] = t[j];
        }
        jump -= 8;
    }
    setClassType(address[0]);

}

//Retrieves the first octet of the IP address
int IPAddress::getFirstOctet() const {
    return address[0];
}

//Retrieves the second octet of the IP address
int IPAddress::getSecondOctet() const {
    return address[1];
}

//Retrieves the third octet of the IP address
int IPAddress::getThirdOctet() const {
    return address[2];
}

//Retrieves the fourth octet of the IP address
int IPAddress::getFourthOctet() const {
    return address[3];
}

