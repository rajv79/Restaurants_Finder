#include <vector>
#include <iostream>
#include <unordered_map>
#include "restaurant.h"
#include "heap.h"
#pragma once

using namespace std;
class user{
  private:
    string name;
    string res_name;
    //vector<string> restaurants;
    vector <restaurant> restVec;
    unordered_map<string, string>restMap;

    unordered_map<int, craving>craveMap;
    heap hp; // Maxheap for each user to  keep there craving   
//can we use heap library
  public:
    user();
    user(string name1);
    ~user();
    user(const user& d);
    user& operator=(const user &d);    
    void printUsers();
    void rec(string &newRest,string &newCuisine);
    string getUsername();
    void setUsername(string s);
    string eat();
    void delRoot();
    //void addRestHelp(string newRest, string cuisine);
    //void add(restaurant restName);

    //<<-----------protoype for adding thing in user max heap ------------------------->>>

    void crave (craving c);
    void RecNew(restaurant r);  // recomending the restauyemnt of the user
    void UnRecNew(restaurant r); // unrecomendind the restaurment for the user

    void SHOW_USER_REC_Restaurment();
    void print_out_craving();
    string restSearch(string cuisineType);
    void add_crave_map(string cuisine, int index);
     void editMap(int old, int update);
     int getIndexHeap(craving s);
};