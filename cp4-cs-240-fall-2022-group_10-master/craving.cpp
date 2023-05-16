#include <vector>
#include <iostream>
#include <string.h>
#include "craving.h"
// #pragma once;

craving::craving(){       // default contrcutor
  s1= " For everything";
  points = 0;
  //connection = -1;
  
  
}
//value base constructor 
craving::craving(string craving_for, int p){ 
  s1= craving_for;
  points =p;
 // connection = -1;
}

// making a copy contrusctor !!!!
bool craving:: operator==(const craving &c){
  if(s1== c.s1 && points== c.points){
    return true;
  }
  return false;
}

// getter function
string craving:: getcraving(){
  return this->s1;

}
int craving::getpoints(){
  return this->points;
}

//setter function
void craving:: setpoints(int s){
  points= s;
}



