#include <string>
using namespace std;
#ifndef MAILINGADDRESS_H
#define MAILINGADDRESS_H

class MailingAddress{
    public:
        string street;
        string city;
        string state;
        int zipcode;
        MailingAddress(string street, string city, string state, int zipcode){
            this->street = street; /*this is a pointer that points to self. this-> accesses the self's attributes*/
            this->city = city;
            this->state = state;
            this->zipcode = zipcode;
        }
        MailingAddress(){
            this->street = "";
            this->city = "";
            this->state = "";
            this->zipcode = -1;
        }
        bool equals(MailingAddress addr){
            if(addr.street == street && addr.city == city && addr.state == state && addr.zipcode == zipcode){
                return true;
            }
            return false;
        }
        string toString(){
            return "{" + street + ", " + city + ", " + state + ", " + std::to_string(zipcode) + "}";
        }
};

#endif