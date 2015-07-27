#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <bitset>

class IPAddress {
    private:
        unsigned int *address;
        std::bitset<32> binary_address;
        char classType;
    public:
        IPAddress();
        IPAddress(unsigned long int addressInInt);
        IPAddress(std::bitset<32> addressInBinary);
        IPAddress(const IPAddress &obj);
        ~IPAddress();

        void setAddress(int first, int second, int third, int fourth);
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

#endif // IPADDRESS_H
