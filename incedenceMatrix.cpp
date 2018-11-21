#include<iostream>
#include<iomanip>
 
using namespace std;
 

void printMatrix(int mat[][20], int n, int c)
{
	int i, j;
 	cout<<" ******* Incedence Matrix ******* \n \n";
	cout<<"\n\n"<<setw(6)<<"";
	for(i = 0; i < n; i++)
		cout<<setw(6)<<"V("<<i+1<<")";
	cout<<"\n\n";
 
	
	for(i = 0; i < c; i++)
	{
		cout<<setw(6)<<"E("<<i+1<<")";
 
		for(j = 0; j < n; j++)
		{
			cout<<setw(6)<<mat[i][j];
		}
 
		cout<<"\n\n";
	}
}
 
int main()
{
	int  n, k, c = 0, incidentmatrix[100][20];
 
	cout<<"Enter the number of vertexes: ";
	cin>>n;
 	char a;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			cout<<"\nIs the vertex "<<i+1<<" connected to vertex "<<j+1<<" (y/n) \n";
			cin>>a;
			if(a=='Y' || a=='y')
			{
				for(k = 0; k < n; k++)
				{
					if(k == i || k == j)
						{
							incidentmatrix[c][k] = 1;
						}
					else
					   {
							incidentmatrix[c][k] = 0;
					   }
				}
				c++;
				cout<<"\t\tThis is edge E("<<c<<"). \n";
			}
		}
	}
 
	printMatrix(incidentmatrix, n, c);
}