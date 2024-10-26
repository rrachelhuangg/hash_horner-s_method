#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "MailingAddress.h"
#ifndef MAHASHTABLE_H
#define MAHASHTABLE_H
class MAHashTable{
    public:
        static int M;
        static int R;
        vector<vector<MailingAddress> > table;
        MAHashTable(){
            this->M=97; //are M and R here necessary?
            this->R=31;
            for(int i = 0; i < M; i++){
                vector<MailingAddress> slot;
                table.push_back(slot);
            }
        }
        static long hashInt(int i){
            long hashed_int = i % M;
            return hashed_int;
        }
        static long hashString(string s){
            long string_hash;
            for(int i = 1; i < s.length(); i++){ /*confirm about if the bounds of the summation of the hash function are exclusive or not??*/
                string_hash = (R * string_hash + int(s.at(i))) % M;
            }
            return string_hash;
        }
        static long hashAddress(MailingAddress addr){
            long hash_street = hashString(addr.street);
            long hash_city = hashString(addr.city);
            long hash_state = hashString(addr.state);
            long hash_zipcode = hashInt(addr.zipcode);
            return (((((hash_street*R+hash_city)%M)*R+hash_state)%M)*R+hash_zipcode)%M;
        }
        void insert(MailingAddress addr){
            /*hashAddress(addr) should return a table index value from 0 to M-1*/
            table[hashAddress(addr)].push_back(addr);
        }
        bool contains(MailingAddress addr){
            vector<MailingAddress> slot = table[hashAddress(addr)];
            bool check = false;
            for(int i = 0; i < slot.size(); i++){
                if(slot[i].equals(addr)){
                    check = true;
                }
            }
            return check;
        }
        float getLoadFactor(){
            /* calculate N/M in constant time??*/
            return 0;
        }
        void print(){
            for(int i = 0; i < M; i++){
                string output;
                string elements = "{";
                for(int j = 0; j < table[i].size(); j++){
                    elements = elements + table[i][j].toString() + "; ";
                }
                elements = elements + "}";
                if(elements.length()> 2){
                    output = to_string(i) + "->[" + elements + "]";
                }
                else{
                    output = "[]";
                }
                cout<<output<<endl;
            }
        }

};

#endif