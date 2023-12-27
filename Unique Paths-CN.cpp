#include<bits/stdc++.h>
/*recursion TC=O(2^m*n) SC=O(m*n)
int find(int i,int j,int m,int n)
{
	if(i==m-1&&j==n-1)return 1;
	if(i>=m||j>=n)return 0;
	return find(i+1,j,m,n)+find(i,j+1,m,n);
	 
}
*/
/*Memoization TC=O(m*n) SC=O(m*n)
int find(int i,int j,int m,int n,vector<vector<int>> &dp)
{
	if(i==m-1&&j==n-1)return 1;
	if(i>=m||j>=n)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	return dp[i][j]=find(i+1,j,m,n,dp)+find(i,j+1,m,n,dp);
	 
}
*/
int uniquePaths(int m, int n) {
  // Write your code here.
  //vector<vector<int>> dp(m,vector<int>(n,-1));
  //return find(0,0,m,n,dp);
  
  /*Tabulation TC=O(n*m) SC=O(n*m)
  vector<vector<int>> dp(m,vector<int>(n,0));
  for(int i=0;i<m;i++)
  {
	  dp[i][n-1]=1;
  }
  for(int j=0;j<n;j++)
  {
	  dp[m-1][j]=1;
  }
  for(int i=m-2;i>=0;i--)
  {
	  for(int j=n-2;j>=0;j--)
	  {
		  dp[i][j]=dp[i+1][j]+dp[i][j+1];
	  }
  }
  return dp[0][0];
  */
  //space optimization TC=O(m*n) SC=O(n)
  vector<int> next(n,1);
  vector<int> dp(n,1);
  for(int i=m-2;i>=0;i--)
  {
	  for(int j=n-2;j>=0;j--)
	  {
		  dp[j]=next[j]+dp[j+1];
	  }
	  next=dp;
  }
  return next[0];
}
