
#include <iostream>
#include <cstdlib>

using namespace std;

struct AdjListNode
{
    int data;
    struct AdjListNode* next;
};
 
 
struct AdjList
{
    struct AdjListNode *head;
};
 
 
class Graph
{
    private:
        int val;
        AdjList* array; 
    public:
        Graph(int val)
        {
            this->val = val;
            array = new AdjList [val];		 
            for (int i = 0; i < val; ++i)
                array[i].head = NULL;  		
        }

        void addEdge(int src, int dest)
        {	
        
        	AdjListNode* newNode = new AdjListNode;  
            newNode->data = dest;					
            newNode->next = NULL;		
            									
            newNode->next = array[src].head;		
            array[src].head = newNode;				
            
			 
			newNode = new AdjListNode; 				 
            newNode->data = src;				
            newNode->next = NULL;				

            newNode->next = array[dest].head;	
            array[dest].head = newNode;			
        }
        
        void printGraph()
        {
            int v;
            for (v = 0; v < val; ++v)
            {
                AdjListNode* tmp = array[v].head;	
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (tmp)
                {
                    cout<<"-> "<<tmp->data;
                    tmp = tmp->next;
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
};
 

int main()
{
    int n;
    cout<<"Enter the number of edges of the graph : \n";
    cin>>n;
    int a,b;
    Graph obj(n);
    cout<<" Enter the edge pairs :";
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        obj.addEdge(a,b);
    }
    obj.printGraph();
 
    return 0;
}