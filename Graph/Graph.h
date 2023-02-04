//
//  Graph.h
//  Graph
//
//  Created by Ольга Полевик on 27.08.2021.
//

#ifndef Graph_h
#define Graph_h
#define SIZE 10
#define VERYBIGINT 1000000000 // очень большое число

class Graph__
{
  struct Edge
    {
        int v1;
        int v2;
        int weight;
    };
    Graph__()
    {
        edgeCount = 0;
    };
private:
    Edge edges[SIZE*SIZE];
    int edgeCount;    
};

class Graph_
{
    struct Edge
    {
        int vertexWhere;
        int weight;
        Edge()
        {
            
        }
        Edge(int vw, int w) : vertexWhere(vw), weight(w)
        {
            
        }
    };
    
    struct Vertex
    {
        int number;
        Edge adj_vertexes[SIZE];
        int edgeCount;
    };
public:
    Graph_()
    {
        vertexCount = 0;
    }
private:
    Vertex vertexes[SIZE];
    int vertexCount;
};

class Graph
{
public:
    Graph()
    {
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                matrix[i][j] = 0;
            }
            vertexCount = 0;
        }
    }
    
    void addVertex(int vnumber);
    void addEdge(int v1, int v2, int weight);
    void delVertex(int number);
    void delEdge(int v1, int v2);
    void depth(int start);
    void width(int start);
    void findMinDistanceDecstr(int fromVert);
    void findMinDistanceFloyd();
    
private:
    int matrix[SIZE][SIZE];
    int vertexes[SIZE];
    int vertexCount;
    
    void depthInner(int current, bool visited[]);
    bool edgeExists(int v1, int v2);
    bool vertexExists(int number);
};



#endif /* Graph_h */
