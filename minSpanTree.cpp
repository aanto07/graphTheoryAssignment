#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//Struct to represent an edge between two vertices
struct Edge
{
    int src,dest,weight;    // src -> source edge; dest -> destination edge; weight -> weight of the edge
};

typedef struct Edge Edge;

//Struct to represent an undirected weighted graph
struct Graph
{
    /* data */
    int V, E;   // v -> number of vertices; e -> number of edges
    Edge *edge; // edge -> stores the edges between vertices
};

typedef struct Graph Graph;

//Function to create a new graph instance
Graph * createGraph(int v, int e){
    Graph *g = new Graph;
    g->V = v;
    g->E = e;

    g->edge = new Edge[e];

    return g;
}

//Struct to represent subset used in Union Find Algorithm
struct subset{
    int rank;
    int parent;
};

typedef struct subset subset;


//Find function used for Union Find Algorithm
int find(subset subsets[], int i){
    if(subsets[i].parent != i)
        return find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}


//Union function used for Union Find Algorithm
void Union(subset subsets[], int i, int j){
    int xroot = find(subsets,i);
    int yroot = find(subsets,j);

    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


//function passed to quicksort to compare two edges
int compEdge(const void* a, const void* b){
    Edge* a1  = (Edge*)a;
    Edge* b1 = (Edge*)b;
    
    return a1->weight > b1->weight;
}

void MinSpanTree(Graph* g){
    int V = g->V;
    Edge result[V]; // Store the edges present in MST
    int e = 0;
    int i = 0;
    int x,y;
    Edge curr_edge;

    qsort(g->edge,g->E,sizeof(Edge),compEdge); // function to sort the edges in the graph in ascending order of their weight

    subset *subsets = new subset[V]; // Create V subsets, one for each vertex

    // The subsets are initialized
    for(int v = 0; v < V; v++)
    {
        /* code */
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // To obtain a tree with V vertices we must stop at V-1 edges
    while(e < V-1){
        curr_edge = g->edge[i++];

        //Find the subsets to which the vertices of the current edge belongs to
        x = find(subsets,curr_edge.src);
        y = find(subsets,curr_edge.dest);

        //If both vertices are in different subsets then there is no loop.
        //The edge can be added to the tree.
        //The union of the two subsets will be taken.
        if(x != y){
            result[e++] = curr_edge;

            Union(subsets,x,y);
        }
        //If both vertices belong to the same subset, then the resulting graph will have a cycle
        //Hence that edge is discarded
    }
    printf("Following are the edges in the constructed MST\n"); 
    for (i = 0; i < e; ++i) 
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
                                                 result[i].weight); 
    return; 
}

int main(int argc, char const *argv[])
{   
    /*
    For an example we'll construct a minimum spanning tree for the graph given below
                (1)---8---(2)-----7-----(3)
               / |         | \           | \
              /  |         |  \          |  \
             4   |         2   \         |   9
            /    |         |    \        |    \
           /     |         |     \       |     \
        (0)     11       (8)      4      14    (4)
           \     |      /  |       \     |     /
            \    |     /   |        \    |    /
             8   |    7    6         \   |   10
              \  |   /     |          \  |  /
               \ |  /      |           \ | /
                (7)---1---(6)-----2-----(5)
    */

    int V = 9;  // Number of vertices in graph 
    int E = 14;  // Number of edges in graph 
    struct Graph* graph = createGraph(V, E); 
    
  
    // add edge 0-1 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = 4; 
  
    // add edge 0-7 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 7; 
    graph->edge[1].weight = 8; 
  
    // add edge 1-7 
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 7; 
    graph->edge[2].weight = 11; 
  
    // add edge 1-2 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 2; 
    graph->edge[3].weight = 8; 
  
    // add edge 2-8 
    graph->edge[4].src = 2; 
    graph->edge[4].dest = 8; 
    graph->edge[4].weight = 2;
    
    // add edge 8-6 
    graph->edge[5].src = 8; 
    graph->edge[5].dest = 6; 
    graph->edge[5].weight = 6;

    // add edge 6-7 
    graph->edge[6].src = 6; 
    graph->edge[6].dest = 7; 
    graph->edge[6].weight = 1;

    // add edge 7-8 
    graph->edge[7].src = 7; 
    graph->edge[7].dest = 8; 
    graph->edge[7].weight = 7;

    // add edge 2-3
    graph->edge[8].src = 2; 
    graph->edge[8].dest = 3; 
    graph->edge[8].weight = 7; 

    // add edge 3-5 
    graph->edge[9].src = 3; 
    graph->edge[9].dest = 5; 
    graph->edge[9].weight = 14; 

    // add edge 5-6
    graph->edge[10].src = 5; 
    graph->edge[10].dest = 6; 
    graph->edge[10].weight = 2; 

    // add edge 2-5
    graph->edge[11].src = 2; 
    graph->edge[11].dest = 5; 
    graph->edge[11].weight = 4;

    // add edge 3-4
    graph->edge[12].src = 3; 
    graph->edge[12].dest = 4; 
    graph->edge[12].weight = 9;

    // add edge 4-5
    graph->edge[13].src = 4; 
    graph->edge[13].dest = 5; 
    graph->edge[13].weight = 10;
  
    MinSpanTree(graph); 
   
    return 0;
}

