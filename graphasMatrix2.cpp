#include<iostream>

#include<iomanip>

using namespace std;

void printMatrix(int mat[][20],int n)
{
	cout<<"\n ******** Graph as Adjacency Matrix ******* \n \n";
	int i,j;
	cout<<"\n\n"<<setw(4)<<"";
	for(i = 0; i < n; i++)
        cout<<setw(3)<<"("<<i+1<<")";
    cout<<"\n\n";
    for(i = 0; i < n; i++)
    {
        cout<<setw(3)<<"("<<i+1<<")";
        for(j = 0; j < n; j++)
        {
            cout<<setw(4)<<mat[i][j];
        }
        cout<<"\n\n";
    }
}
 




int main()
{
 // clrscr();
  int n;
  cout<<"Enter the number of vertices of the graph : \n" ;
  cin>>n;
  char a;

  int matrix[20][20];

  for(int i=0;i<n;i++)
  {
  	for(int j=i;j<n;j++)
  	{
  		if(i!=j)
  		{
  			cout<<"Is edge "<<i+1<<" connected with edge "<<j+1<<" (y/n) \n";
  			cin>>a;
  			matrix[i][j] = (a=='Y'&&a=='y')?0:1; 

  			matrix[j][i] = matrix[i][j];
  		}
  		else
  		{
  			matrix[i][j]=0;
  		}
  	}
  }

printMatrix(matrix,n);
  

}