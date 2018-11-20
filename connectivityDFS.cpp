#include<iostream> 
#include <list> 
using namespace std; 
  
class Graph 
{ 
    int V;    // No. of vertices 
    int count; // No of components
  
    // Pointer to an array containing adjacency lists 
    list<int> *adj; 
  
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w); 
    void connectedComponents();
    void displayComponentNumber();
}; 
  
 //method to calculate the number of connected components
void Graph::connectedComponents() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            // print all reachable vertices 
            // from v 
            count = count+1;
            DFSUtil(v, visited); 
  
            cout << "\n"; 
        } 
    } 
} 

// method to implement the DFS Algorithm
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Repeat for all vertices adjacent to current vertex
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 

// method to intialize an instance of the graph  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
    count = 0;
} 

// method to display the total number of components
void Graph::displayComponentNumber(){
    cout<<"\nNumber of Components in the graph: "<<count<<"\n";
}
  
// method to add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  
// Drive program to test above 
int main() 
{ 
    int edge_num, vertex_num,vert1,vert2; 
    cout<<"\nEnter the number of vertices: ";
    cin>>vertex_num;
    cout<<"\nEnter the number of edges: ";
    cin>>edge_num;
    Graph g(vertex_num);  //Creating the graph
    for(int i=0;i<edge_num;i++){  //Entering the edges (vertices begin from 0)
        cout<<"\nEnter edge "<<i<<":";
        cin>>vert1>>vert2;
        g.addEdge(vert1,vert2);
    }
  
    cout << "Following are connected components \n"; 
    g.connectedComponents(); 
    g.displayComponentNumber();
  
    return 0; 
} 