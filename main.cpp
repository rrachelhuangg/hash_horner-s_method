#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
#include "MailingAddress.h"
#include "MAHashTable.h"

int MAHashTable::M = 97;
int MAHashTable::R = 31;

vector<string> splitString(string line, char delimiter){
    vector<string> split_string;
    istringstream stream(line);
    string segment;
    while(getline(stream, segment, delimiter)){
        split_string.push_back(segment);
    }
    return split_string;
}

int main(){
    ifstream address_file ("addresses.txt");
    vector<MailingAddress> addresses;
    string line;
    string delimiter = ",";
    if(address_file.is_open()){
        while(getline(address_file, line)){
            vector<string> parsed_address = splitString(line, ',');
            MailingAddress address(parsed_address[0], parsed_address[1], parsed_address[2], stoi(parsed_address[3]));
            addresses.push_back(address);
        }
    }
    MAHashTable hash_table;
    for(int i = 0; i < addresses.size(); i++){
        hash_table.insert(addresses[i]);
    }
    hash_table.print();

    MailingAddress addr_one("450 Highland Ave","Salem","MA",1970);
    bool check_one = hash_table.contains(addr_one);
    cout<<"Check one: " + to_string(check_one)<<endl;


    MailingAddress addr_two("450 Highland Avenue","Salem","MA",1970);
    bool check_two = hash_table.contains(addr_two);
    cout<<"Check two: " + to_string(check_two)<<endl;
    return 0;
}