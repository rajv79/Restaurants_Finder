#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include "user.h"
#include "heap.h"
#include "craving.h"
#include "graph.h"
using namespace std;
unordered_map<string, user> usernames;
int main() {
  

  //  CONTAINNER FOR RESTAURMENT FORM WHICH ALL THE USER CAN REC OR UNCREC FORM IT
  vector  <restaurant> objec_restaurment;


  
  // we have to create directed graph here to connect between user

  ///
  /// <--------------------TESTING FOR CRAVING AND HEAP CLASs----------------------------->
  graph myGraph;
  

  
  string input;
  string name;
  string name1;
  string name2;
  string cuisine;
  string rest_name;
  int points;
  int fdistance;

  unordered_map<string, restaurant> rest_map;

  cout << "CREATE <username>" << endl;
  cout << "SHOW_RES" << endl;
  cout << "REC <username> <restaurant-name>" << endl;  /// testing REC
  cout << "UNREC <username> <restaurat-name>"<<endl;  // TESTING UNREC
  cout << "ADD <restaurant-name> <cuisine>" << endl;
  cout << "Crave <Username> <Cusine> <Point>" <<endl;
  cout << "SHOW_USER_CRAVES <Usernames>"<<endl;  ///---------Testing function
  cout << "SHOW_USER_REC <unsername> "<<endl;  // Testing the REC AND UNREC

  while(cin >> input){
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    if(input == "CREATE"){
      cin >> name;
      if(usernames.find(name) == usernames.end()){
        user newName(name);
        usernames[name] = newName;
        myGraph.createUser1(&usernames[name]);
        //graph.addVertex(newName);
      }
      else{
        cout << "this name already has been used" << endl;
      }
      
    }
    
    if(input == "ADD"){
       cin >> rest_name;
       cin >> cuisine;
       restaurant r1(rest_name, cuisine);
       int flag =0;
       
       for(int i =0; i<objec_restaurment.size();i++){
        if(objec_restaurment[i]== r1){
          cout<<"IT IS ALREADY THERE"<<endl;
          flag++;
        }
        
       }

      if(flag==0){
       objec_restaurment.push_back(r1);
      }

    }
    

    if(input == "SHOW_RES"){
      for(int i =0; i<objec_restaurment.size();i++){
       cout<< "Restaurant name: " <<objec_restaurment[i].getrestaurtmentName() << " Cuisine: "<< objec_restaurment[i].getCusisnName() <<endl;

      }
    }

    // if(input == "SHOW") {
    //    cin >> name;
    //    if(usernames.find(name) != usernames.end()){
    //     user temp = usernames[name];
    //     temp.printUsers();
    //    }
    //    else{
    //     cout <<"failllll" << endl;
    //    }

  
    // }
    // <----------Liam I added from here ------just to check crave method----------------------from vivek-------->
    if(input == "CRAVE"){
      cin>>name;
      cin>>cuisine;
      cin>>points;
      craving s(cuisine,points);
      usernames.at(name).crave(s);
      //some function to get index in heap
      int index = usernames.at(name).getIndexHeap(s);
      usernames.at(name).add_crave_map(cuisine, index);
      cout<<"Craving is add to that user object ccraving"<<endl;
      
    }

    //showing user cravings in max heap order
    if(input=="SHOW_USER_CRAVES"){
      cin>>name; //for useernames
      usernames.at(name).print_out_craving();
    }


    if(input =="REC"){
      cin>>name;
      cin>>rest_name;
      int flag =0;

      for(int i =0; i<objec_restaurment.size();i++){

          if(objec_restaurment[i].getrestaurtmentName()== rest_name){
            usernames.at(name).RecNew(objec_restaurment[i]);
            cout<<"REC is add to that user object RESTAURMENT"<<endl;
            flag++;
      }
    }
    if(flag==0){
      cout<<"Restaurment is not  present in container"<<endl;
    }
    }
    if(input == "FRIEND"){
      
      cin >> name1 >> name2;
      myGraph.addEdge1(&usernames[name1], &usernames[name2]);

    
      
    }
    if(input == "UNFRIEND"){
      cin >> name1>>name2;
  
      myGraph.removeEdge1(&usernames[name1], &usernames[name2]);
    }

    if(input == "PRINT_GRAPH"){
      myGraph.printgraph1();
    }

    if(input == "EAT"){
      cin >> name >> fdistance;
      string cuis = usernames[name].eat();
      string eat = myGraph.bfs(fdistance, cuis, &usernames[name]);
      cout << "Eating at " << eat <<endl;
    }

    if(input =="UNREC"){
      cin>>name;
      cin>> rest_name;
      int flag =0;
      for(int i =0; i<objec_restaurment.size();i++){
        if(objec_restaurment[i].getrestaurtmentName()== rest_name){
          usernames.at(name).UnRecNew(objec_restaurment[i]);
          cout<<"UNREC is REMOVE to that user object to remove restaurment "<<endl;
          flag++;
        }
      }
      if(flag ==0){
        cout<<"The res is not pressnt in user Rec list to unREC"<<endl;
      }

    }

    if( input == "SHOW_USER_REC"){   // SHOWING USERS RECOMENDATION RESAATURMENT
      cin>>name;
      usernames.at(name).SHOW_USER_REC_Restaurment();

    }
    
    if(input == "QUIT" || input == "Q"){
      break;
    }

  cout << endl;
  cout << "CREATE <username>" << endl;
  cout << "REC <username> <restaurant-name>" << endl;  /// testing REC
  cout << "UNREC <username> <restaurat-name>"<<endl;  // TESTING UNREC
  cout << "ADD <restaurant-name> <cuisine>" << endl;
  cout << "CRAVE <Username> <Cusine> <Point>" <<endl;
  cout << "FRIEND <username1> <username2>" <<endl;
  cout << "UNFRIEND <username1> <username2>" <<endl;
  cout << "EAT <username> <friendship-distance>" <<endl;
  cout << "SHOW_RES" << endl;
  cout << "SHOW_USER_CRAVES <Usernames>"<<endl;  ///---------Testing function
  cout << "SHOW_USER_REC <unsername> "<<endl;  // Testing the REC AND UNREC
  cout << endl;
  

  }
  
  

  


}