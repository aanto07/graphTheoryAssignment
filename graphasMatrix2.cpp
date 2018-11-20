#include<iostream>

#include<iomanip>

using namespace std;

void printMatrix(int mat[][20],int n)
{
	cout<<"\n ******** Graph as Adjacency Matrix ******* \n \n";
	int i,j;
	cout<<"\n\n"<<setw(4)<<"";
	for(i = 1; i <=n; i++)
        cout<<setw(3)<<"("<<i<<")";
    cout<<"\n\n";
    for(i = 1; i <= n; i++)
    {
        cout<<setw(3)<<"("<<i<<")";
        for(j = 1; j <=n; j++)
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

  for(int i=1;i<=n;i++)
  {
  	for(int j=i;j<=n;j++)
  	{
  		if(i!=j)
  		{
  			cout<<"Is edge "<<i<<" connected with edge "<<j<<" (y/n) \n";
  			cin>>a;
  			if(a=='Y'|| a=='y')
        {
          matrix[i][j] =1;
        }
        else
          matrix[i][j] = 0;

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