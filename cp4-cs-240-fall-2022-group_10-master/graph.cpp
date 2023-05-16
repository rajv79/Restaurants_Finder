#include <iostream>
#include "user.h"
#include "graph.h"
#include <queue>
using namespace std;


/*testing for new user parameters*/
void graph::createUser1(user* u)
{
Vertex* v = new Vertex;
v->users = u;
v->edges = nullptr;
v->nodeNum = nodeCount;
adjList.insert(make_pair(u, v));
numVertices++;
nodeCount++;   
}

void graph::addEdge1(user* u1,user* u2)
{
Vertex* v1 = adjList[u1];
Vertex* v2 = adjList[u2];
Edge* e1 = new Edge;
e1->name = u2;
e1->next = v1->edges;
v1->edges = e1;
numEdges++;
}

void graph::removeEdge1(user* u1,user* u2)
{
Vertex* v1 = adjList[u1];
Vertex* v2 = adjList[u2];
Edge* prev1 = nullptr;
Edge* prev2 = nullptr;
Edge* current1 = v1->edges;
while (current1 != nullptr && current1->name != u2) {
 prev1 = current1;
 current1 = current1->next;
}
if (current1 != nullptr) {
 if (prev1 == nullptr) {
  v1->edges = current1->next;
 }
 else {
  prev1->next = current1->next;
 }
 delete current1;
}
numEdges--;
}

void graph::printgraph1()
{
    for (auto it : adjList) 
    {
    cout << it.first->getUsername() << "-> ";
    Edge* currentEdge = it.second->edges;
    while (currentEdge != nullptr)
        {
        cout << currentEdge->name->getUsername() << ", ";
        currentEdge = currentEdge->next;
        }
    cout <<endl;
    }
    
}

string graph::bfs(int distance, string cuisine, user* u){   
    
        Edge* myEdges = adjList[u]->edges;
        queue<Vertex*> q;
        for(int i=0; i < distance; i++){
                while(myEdges != nullptr){
                    q.push(adjList[myEdges->name]);
                    string eat = myEdges->name->restSearch(cuisine);
                    if(eat != "error"){
                        //delete myEdges;
                        u->delRoot();
                        return eat;
                }
                myEdges = myEdges->next;

                }
                for(int i=0; i < q.size(); i++){
        
                    Edge* current = q.front()->edges;
                    q.pop();
                    while(current != nullptr){
                    q.push(adjList[current->name]);
                    string eat1 = current->name->restSearch(cuisine);
                        if(eat1 != "error"){
                            u->delRoot();
                            //delete current;-----//this was  causing the doble free erroe
                            delete myEdges;
                            return eat1;
                        }
                         current = current->next;
                    }
                   

           
            }
    
    
    
    }
    return "Error no restaurants serve that cuisine";
}
graph::~graph(){
    for (auto it : adjList){

        Edge *current = it.second->edges;
        while (current!=nullptr)
        {
            Edge*temp = current;
            current = current->next;
            delete temp;
        }
    }
    for(auto it : adjList){
        delete it.second;
}
}