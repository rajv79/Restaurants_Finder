#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#pragma once

using namespace std;
//
class restaurant{

    private:
     string rest_name;
     string cuisine;

     public:
     restaurant();
     restaurant(string name , string cuisin_name);
     restaurant(const restaurant& d);
     restaurant& operator=(const restaurant &d);
    //  string getName();
    //  string getCuisine();

     // getter 
     string getrestaurtmentName();
     string getCusisnName();

     //  setter's
     void setResrtaurmentName(string s);
     void setCusinName(string s);
     bool operator==(const restaurant &t);



};