#include "iostream"
#include "stdlib.h"

using namespace std;

bool checkEmpty(int arr[], int n){
    int flag = 0;
    
    for(int i = 0; i < n; i++)
    {
        /* code */
        if(arr[i] == 1){
            flag = 1;
            break;
        }
    }

    if(flag)
        return false;
    else
        return true;
    
}

int main(int argc, char const *argv[])
{
    int graph[20][20];
    int V;
    char a;

    int vertices[V],c=1;

    
    for(int i = 0; i < V; i++)
    {
        /* code */
        vertices[i] = 1;
    }
    

    cout<<"Enter the number of vertices";

    
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(i == j){
                graph[i][j] = 0;
                continue;
            }
            cout<<"Is there an edge between "<<i<<" and "<<"j";
            cin>>a;
  			if(a=='Y'|| a=='y')
            {
            graph[i][j] =1;
            }
            else
            graph[i][j] = 0;

            
            graph[j][i] = graph[i][j];

        }
    }
    int start = 0;
    while(true){
        if(checkEmpty(vertices,V))
            break;
        int copy[20][20];

        
        for(int i = 0; i < V; i++)
        {
            
            for(int j = 0; j < V; j++)
            {
                copy[i][j] = graph[i][j];
            }
            
        }
        
    }
    
    return 0;
}
