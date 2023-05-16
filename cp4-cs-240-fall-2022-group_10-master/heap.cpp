#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "heap.h"

using namespace std;



heap::heap()
{
    vector<craving> crave;
}
// finding index functon
string heap::getCraveMax(){
    return c[0].getcraving();
}
int heap::index_retunr(craving cr){
    int index =0;

    for(int i =0; i<c.size();i++){
        if(c[i]==cr){
            index = i;
            return index;
        }
    }
    return -1;
}


// for returing the postion of parent
craving heap::parent(craving pos){
   int  index = index_retunr(pos);
   return c[((index-1)/2)];

}

// returning the left child
 int heap :: leftchild(craving pos){
    int index = index_retunr(pos);
        return (2*index)+1;

 }

// // returing the right child
 int heap:: rightchild(craving pos){

    int index = index_retunr(pos);
    return (2*index)+2;

 }

// mehtod to return if it is leaf or not
bool heap:: isLeaf(craving pos){
    int index = index_retunr(pos);
    if(index > (c.size()/2) && index <= c.size()){
        return true;
    }
    return false;
   
}




void heap::add(craving name){
     // first insert at the end
     for(int i = 0; i < c.size();i++){
        if(name.getcraving()== c[i].getcraving()){
            name.setpoints(name.getpoints()+c[i].getpoints());
        }
    }

     
    c.push_back(name);
    craveMap[name.getcraving()] = c.size() - 1;
    // now let's fix up the heap
    // point i at the last element size()-1
    int i = c.size()-1;
    // setup a swap var
    craving swap;
    // to make it easy to readn
    int parent;
    while (i > 0) {
        parent = (i-1)/2; // finding the parent node  
       
        if (c[i].getpoints() > c[parent].getpoints()){
            swap = c[i];
            c[i] = c[parent];
            c[parent] = swap;
            editMap(i, parent);
        }

       
        
         else break;
         i = parent;
        //  editMap(i, parent);
    }
}

void heap::shiftdown(craving cc){

    int index = index_retunr(cc);
    if(index>=c.size()) return;

    int sawpId = index;

    if((leftchild(cc)<c.size())&& (c[index].getpoints()<c[leftchild(cc)].getpoints())){
        int swapId =leftchild(cc);
    }
    if(rightchild(cc)<c.size() && c[sawpId].getpoints()<c[rightchild(cc)].getpoints()){
       int  swapId= rightchild(cc);
    }
       if( sawpId!=index){
            swap(c[index],c[sawpId]);
            shiftdown(cc);
        }
}
void heap::heapfy(vector<craving> s, int index){
    int largest =index;
    int l = 2*index+1;
    int r = 2*index+2;
    if((l<c.size()) && (c[l].getpoints()>c[largest].getpoints())){
        largest =l;
    }
    if((r<c.size())&&(c[r].getpoints()>c[largest].getpoints())){

        largest = r;
    }
    if(largest != index) {
        std::swap(c[index],c[largest]);
        
        editMap(index, largest);
        heapfy(s,largest);
    }

}    
void heap::deleteRoot(){
    int n = c.size();  
    craving cc = c[n-1];  // getting last element 
    c[0]= cc;    // reaplcing from root--->last node
    c.pop_back();
    n =n-1; // decreasing the size of heap by 1
    c.push_back(cc); 
    //heapify function
    heapfy(c,0);
    editMap(0, n);
}
int heap::getSizeHeap(){
    return c.size();
}
void heap::print_max_heap(){

    for(int i =0; i<c.size();i++){
        //cout<<c[i].getpoints() <<" the craving --> " <<c[i].getcraving()<<endl;
        cout<<" craving is ---> "<< c[i].getcraving()<<" the points is "<<c[i].getpoints()<<endl;
        
    }
}
void heap::add_crave_map(int s, craving obj){

  if(craveMap.find(obj.getcraving())==craveMap.end()){
    craveMap[obj.getcraving()]= s;

  }
 }

void heap::editMap(int oldIndex, int newIndex) {
    cout << "Edit Map Called" << endl;
    string oldString = this->c.at(oldIndex).getcraving();
    string newString = this->c.at(newIndex).getcraving();

    cout << oldString << endl;
    cout << newString << endl;

    unordered_map<string, int>::const_iterator parentPair = craveMap.find(newString);
    unordered_map<string, int>::const_iterator childPair = craveMap.find(oldString);

    cout << parentPair->first << " " << parentPair->second << endl;
    cout << childPair->first << " " << childPair->second << endl;

    int tempParentIndex = parentPair->second;
    craveMap.at(newString) = childPair->second;
    craveMap.at(oldString) = tempParentIndex;
}