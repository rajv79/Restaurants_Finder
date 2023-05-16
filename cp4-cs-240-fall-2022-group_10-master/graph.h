#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include "user.h"
using namespace std;

class graph
{
    private:
        struct Edge
        {
            user* name;
            Edge* next;
        };
        struct Vertex
        {
            user* users;
            Edge* edges;
            int nodeNum;
        };
        unordered_map<user*, Vertex*> adjList;
        int numVertices;
        int nodeCount = 0;
        int numEdges;
    public:
        //testing1
        void createUser1(user* u);
        void addEdge1(user* u1,user* u2);
        void removeEdge1(user* u1,user* u2);
        void printgraph1();
        ~graph();
        string bfs(int distance, string cuisine, user*u);
        void BSF(user u, int distance);

};