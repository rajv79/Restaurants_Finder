#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <unordered_map>
#include"craving.h"
#pragma once


using namespace std;

class heap{

        private:

        vector<craving>c;
        unordered_map<string, int>craveMap;

        craving parent(craving pos);
        int leftchild(craving pos);
        int rightchild(craving pos);
        bool isLeaf(craving pos);
        void maxheapify(craving pos);
        void shiftdown(craving pso);
         
         
        


        public:
        heap(); //default constructor
        void heapfy(vector<craving> ,int index);
        void add(craving c);
        int index_retunr(craving c); // to get the index for craving in the vector
        //craving extractMax();
        void print_max_heap();
        //void remove(craving cc);
        //void extract();
         void deleteRoot();
         string getCraveMax();
         int getSizeHeap();
         void add_crave_map(int s , craving obj);
         void editMap(int old, int update);



        
        


};