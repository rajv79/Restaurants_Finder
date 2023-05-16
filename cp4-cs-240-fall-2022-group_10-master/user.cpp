#include "user.h"
#include <unordered_map>
#include <vector>
#include <algorithm>

// default constrcutor
user::user() {
  name = " group4";
}
user::~user(){
}

user::user(string name1){
  name = name1;
  
}
// user::user(string name1, string res_Name1) {
//   name = name1;
//   res_name = res_Name1;
//   restaurants.push_back(res_Name1);
// }
user::user(const user& d){
  name = d.name;
  res_name = d.res_name;
}

user& user::operator=(const user &d){
  name = d.name;
  res_name = d.res_name;
  // for(auto i: restMap){
    restMap = d.restMap;
  // }
  return *this;
}

void user::printUsers(){
  for(auto i = restMap.begin(); i != restMap.end(); ++i){
    cout << i->first << ", " <<endl; 
    }
}

void user::rec(string &newRest, string &newCuisine){
  //add code to check the cuisine type for restaurant
  //probaby gonna need a restaurant helper function
  
  cout << newRest << " rest-name" << newCuisine << " cuisine" << endl;
  if(restMap.find(newRest) == restMap.end()){
    restMap[newRest] = newCuisine;
    //cout <<"test" <<endl;
  }
  else{cout << newRest <<" was already recommended." << endl;}
  if (restMap.empty() == true)
    cout << "map empty " << endl;
}



// void user::addRec(restaurant restName){
//   if(restMap.find(restNam))
//   restVec.push_back(restName);

// }
// void user::addRestHelp(string newRest, string cuisine){
//   restaurant restTemp(newRest, cuisine);
//   addRec(restTemp);
// }


 //<<-----------protoype for adding thing in user max heap ------------------------->>>
 void user::crave(craving cc){
  // Why is there no check to see if this user is already craving something?
  // crave raj spicy 10
  // crave raj spicy 5

  // Now we have two spicy cravings :()
  hp.add(cc);
}

 void user::print_out_craving(){
  hp.print_max_heap();

 }

 // adding the user favourtate recommendation restaurament
 void user::RecNew(restaurant s){   // adding restuarment object to users

   if(find(restVec.begin(),restVec.end(),s)!=restVec.end()){
    cout<< "restaurament with this name is already present in the user List of Rec"<<endl;
      
   }else{
    restVec.push_back(s);
     
   }
  
  
  //     restVec.push_back(s);
  
 

 }

 //removing the user recommendation restaurment 

 void user::UnRecNew(restaurant s){
   
   if(find(restVec.begin(),restVec.end(),s)!=restVec.end()){
    restVec.erase(find(restVec.begin(),restVec.end(),s));
   }else{
    cout<<"USER DONT HAVE THIS RESTAURTMENT TO UNRECOMEND THAT!!!!"<<endl;
   }
 }

 // Method for Priting User Recommendation Restaurment

 void user::SHOW_USER_REC_Restaurment(){
  for(int i =0; i<restVec.size();i++){
    cout<<" The Restaurment Name : "<<restVec[i].getrestaurtmentName() <<" ,Cusine is : "<<restVec[i].getCusisnName()<<endl;

  }
 }
 
 string user::eat(){
    string cuisineCrave = hp.getCraveMax();
    return cuisineCrave;
 }
 void user::delRoot(){
  hp.deleteRoot();
 }
 string user::restSearch(string cuisineType){
  for(int i=0;i < restVec.size(); i++){
    cout << "restaurant at index " << i << " is " << restVec[i].getrestaurtmentName()<< " and cuisine = " << restVec[i].getCusisnName() << endl;
    if(restVec[i].getCusisnName() == cuisineType){
      return restVec[i].getrestaurtmentName();
    }
    
  }
  return "error";
 }
 
 string user::getUsername(){
  return this->name;
 }
 void user::setUsername(string s){
  name = s;
 }

 void user::add_crave_map(string cravingName, int index){

 }
//  void user::editMap(int old, int update){
//     craving temp = craveMap[update];
//     craveMap[update] = craveMap[old];
//     craveMap[old] = temp;
    
//  }
 int user::getIndexHeap(craving s){
  return hp.index_retunr(s);
 }
