//
//  Graph.cpp
//  Graph
//
//  Created by Ольга Полевик on 27.08.2021.
//

#include <stdio.h>
#include <iostream>
#include "Graph.h"

using namespace std;

void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount++] = vnumber;
}

void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

void Graph::delVertex(int vnumber)
{
    for(int i = 0; i < vertexCount; i++)
    {
        if (vertexes[i] == vnumber)
        {
            vertexes[i] = 0;
            vertexes[i] = vertexes[i+1];
            vertexCount--;
        }
    }
    for(int i = 0;i < SIZE; i++)
    {
        for(int j = 0; j< SIZE; j++)
    
            {
                if (j == vnumber)
                    {
                        matrix[i][j] = 0;
                        matrix[j][i] = 0;
                    }
            }
    }
}

void Graph::delEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

void Graph::depth(int start)
{
    bool visited[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    depthInner(start, visited);
    
    cout << endl;
}

void Graph::depthInner(int current, bool visited[])
{
    cout << "V" << current << "->";
    visited[current] = true;
    for(int i = 0; i < SIZE; i++)
    {
        if(edgeExists(current, i) && !visited[i])
        {
            depthInner(i, visited);
        }
    }
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] != 0;
}

bool Graph::vertexExists(int vnumber)
{
    for(int i = 0; i < vertexCount; i++)
    {
        if(vertexes[i] == vnumber)
        {
            return true;
        }
    }
    return  false;
}

void Graph::width(int start)
{
    int queue_to_visit[SIZE];
    int queueCount = 0;
    
    bool visited[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    queue_to_visit[queueCount++] = start;
    while(queueCount > 0)
    {
        // взятие из очереди вершины
        int current = queue_to_visit[0];
        queueCount--;
        for(int i = 0; i < queueCount; i++)
        {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;
        
        cout<< "v" << current << " -> ";
        for(int i = 0; i < SIZE; i++)
        {
            bool alreadyAdded = false;
            for(int j = 0; j < queueCount; j++)
            {
                if(queue_to_visit[j] == i)
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if(!alreadyAdded && edgeExists(current, i) && !visited[i])
            {
                queue_to_visit[queueCount++] = i;
            }
        }
    }
    cout << endl;
}

void Graph::findMinDistanceDecstr(int fromVert)
{
    int distances[SIZE]; // массив меток
    for(int i=0; i<SIZE; i++) // инициализация меток
    {
        distances[i] = VERYBIGINT;
    }
    distances[fromVert] = 0;
    
    bool passed[SIZE]; // признак, что вершина окрашена
    for(int i=0; i<SIZE; i++)
    {
        passed[i] = false; // все неокрашены изначально
    }
    // принимаем стартовую вершину за текущую
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while(min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // окрашиваем текущую
        
        for(int i=0; i< SIZE; i++)
        {
            // для смежных ребер пересчитываем метки
            if(edgeExists(currentVertexNum,i)
               && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
                    distances[i] =
                      distances[currentVertexNum] + matrix[currentVertexNum][i];
        }
        min_dist = VERYBIGINT;
        for(int i = 0; i< SIZE; i++)
        {
            // выбираем новую текущую вершину
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist) // выбор новой вершины
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }
    
    for(int i=0; i<vertexCount; i++) // вывод результата
    {
        std::cout << "V" << i << ": " << distances[vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}

void Graph::findMinDistanceFloyd()
{
    int weights[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(i == j)
            {
                weights[i][j] = 0;
            }
            else
            {
                if(!edgeExists(i,j))
                {
                    weights[i][j] = VERYBIGINT;
                }
                else
                {
                    weights[i][j] = matrix[i][j];
                }
            }
        }
    }

    for(int k = 0; k < vertexCount; k++)
    {
        int ck = vertexes[k];
        for(int i = 0; i < vertexCount; i ++)
        {
            if(i == k)
            {
                continue;
            }
            int ci = vertexes[i];
            for(int j = 0; j < vertexCount;j++)
            {
                if(j == k)
                {
                    continue;
                }
                int cj = vertexes[j];
                if(weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
                {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }
    
    for(int i = 0; i < vertexCount ; i++)
    {
        // вывод всех минимальных путей от вершины '0'
        std::cout << "V" << i << ": " << weights[0][vertexes[i]] << ", ";
    }
}
