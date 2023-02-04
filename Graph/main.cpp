//
//  main.cpp
//  Graph
//
//  Created by Ольга Полевик on 24.08.2021.
//

#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Graph g;
       
       // добавляем вершины
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    //g.addVertex(6);
    //g.addVertex(7);
    //g.addVertex(8);



       // добавляем ребра
    g.addEdge(0,2,13);
    g.addEdge(0,4,21);
    g.addEdge(0,5,27);
    g.addEdge(2,3,82);
    g.addEdge(2,4,77);
    g.addEdge(4,1,43);
    g.addEdge(4,5,11);
    g.addEdge(5,1,38);
     
    g.depth(0);
    cout << endl;
    g.width(3);
    cout << endl;
    g.findMinDistanceDecstr(0);
    cout << endl;
    g.findMinDistanceFloyd();
    // удаляем вершину и ребро
    //g.delEdge(0,3);
    //g.delVertex(3);

    return 0;
}
