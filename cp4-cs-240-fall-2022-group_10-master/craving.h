#include <vector>
#include <iostream>
#include <string.h>
#pragma once 

using namespace std;
class craving{

  private: 
    string s1; // what you are carving for
    int points; // how much you are carving for
   // int connectionIndex;
  public:
    craving(); //default
    craving(string carving_for, int p); // paramaterized
    bool operator==(const craving &c);

  //getters 
  string getcraving();
  int getpoints();

  //setter's
  void setcraving(string s);
  void setpoints(int s);
  
    
};


