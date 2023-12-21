#include <bits/stdc++.h> 
/*Brute force
void setzeros(int i,int j,vector<vector<int>> &matrix,int n,int m)
{
	for(int i1=0;i1<n;i1++)
	{
		if(matrix[i1][j]!=0)
			matrix[i1][j]=-1;
	}
	for(int j1=0;j1<m;j1++)
	{
		if(matrix[i][j1]!=0)
			matrix[i][j1]=-1;
	}
}
*/

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	/* Brute Force Approach :TC=O(n*m)*o(n+m)+o(n*m)  sc=O(1)
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				setzeros(i,j,matrix,n,m);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==-1)
			{
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
	*/

	/*Approach 2 : TC=O(2*(n*m)) SC=O(n+m)
	vector<int> rowmatrix(n,0);
	vector<int> colmatrix(m,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				rowmatrix[i]=1;
				colmatrix[j]=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(rowmatrix[i]==1||colmatrix[j]==1)
			{
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
	*/
	//Approah 3 :Optimal TC=O(2*n*m) SC=o(1)
	int col0=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				matrix[i][0]=0;
				if(j==0)
					col0=0;
				else
					matrix[0][j]=0;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(matrix[i][0]==0||matrix[0][j]==0)
			{
				matrix[i][j]=0;
			}
		}
	}
	if(matrix[0][0]==0)
	{
		for(int j=1;j<m;j++)
		{
			matrix[0][j]=0;
		}
	}
	if(col0==0)
	{
		for(int i=0;i<n;i++)
		{
			matrix[i][0]=0;
		}
	}
	return matrix;
}
