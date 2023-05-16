#include <vector>
#include <iostream>
#include <string.h>
#include "restaurant.h"
using namespace std;

restaurant::restaurant(){
    rest_name = " Tacos";
    cuisine="Mexcian";
}

restaurant::restaurant(string name1, string cuisine_name){
    rest_name = name1;
    cuisine = cuisine_name;
}
restaurant::restaurant(const restaurant& d){
    rest_name = d.rest_name;
    cuisine = d.cuisine;
}
restaurant& restaurant::operator=(const restaurant &d){
    rest_name = d.rest_name;
    cuisine = d.cuisine;
    return *this;
}

bool restaurant ::operator==(const restaurant &t){
    if(rest_name == t.rest_name && cuisine ==t.cuisine){
        return true;
    }
    return false;
}

// getter function:
string restaurant::getrestaurtmentName(){
    return this->rest_name;
}
string restaurant::getCusisnName(){
    return this->cuisine;
}

//setter function:
void restaurant::setResrtaurmentName(string ss){
    rest_name =ss;
}

void restaurant::setCusinName(string ss){
    cuisine =ss;
}

