#include<bits/stdc++.h> 
using namespace std; 
  
int minEdgeBFS(vector <int> roads[], int u, 
                              int v, int n) 
{ 
    // visited[n] for keeping track of visited 
    vector<bool> visited(n, 0); 
  
    // Initialize distances as 0 
    vector<int> distance(n, 0); 
  
    // queue to do BFS. 
    queue <int> Q; 
    distance[u] = 0; 
  
    Q.push(u); 
    visited[u] = true; 
    while (!Q.empty()) 
    { 
        int x = Q.front(); 
        Q.pop(); 
  
        for (int i=0; i<roads[x].size(); i++) 
        { 
            if (visited[roads[x][i]]) 
                continue; 
  
            // update distance for i 
            distance[roads[x][i]] = distance[x] + 1; 
            Q.push(roads[x][i]); 
            visited[roads[x][i]] = 1; 
        } 
    } 
    return distance[v]; 
} 
  
// function for addition of roads 
void addRoad(vector <int> roads[], int u, int v) 
{ 
   roads[u].push_back(v); 
   roads[v].push_back(u); 
} 
  

int main() 
{ 
    // To store adjacency list of graph 
    int n = 9; 
    vector <int> roads[9]; 

    //vertices are different mail boxes.
    //Each road is connects different mail boxes
    /*
        0-----1-----2-------3
         \   /      |\     / \
           7        | \   5---4
                    5  8  |  
                        \ |  
                          6

    */

    addRoad(roads, 0, 1); 
    addRoad(roads, 0, 7); 
    addRoad(roads, 1, 7); 
    addRoad(roads, 1, 2); 
    addRoad(roads, 2, 3); 
    addRoad(roads, 2, 5); 
    addRoad(roads, 2, 8); 
    addRoad(roads, 3, 4); 
    addRoad(roads, 3, 5); 
    addRoad(roads, 4, 5); 
    addRoad(roads, 5, 6); 
    addRoad(roads, 6, 8); 

    int source; 
    int destination; 
    cout<<"\nEnter Starting mail box: ";
    cin>>source;
    cout<<"\nEnter destination delivery location: ";
    cin>>destination;
    cout<<"Minimum distance to travel : ";
    cout << minEdgeBFS(roads, source, destination, n); 
    return 0; 
} 