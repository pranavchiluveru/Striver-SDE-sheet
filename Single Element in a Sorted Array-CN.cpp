#include<bits/stdc++.h>
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	/*TC=O(n) SC=O(1)
	int n=arr.size();
	if(n==1)return arr[0];
	for(int i=0;i<n;i++)
	{
		if(i==0&&arr[0]!=arr[1])return arr[0];
		if(i==n-1&&arr[n-1]!=arr[n-2])return arr[n-1];
		if(arr[i]!=arr[i-1]&&arr[i]!=arr[i+1])
			return arr[i];
		
	}
	*/
	//Binary Search TC=O(logn) SC=O(1)
	int n=arr.size();
	int low=1,high=n-2;
	if(n==1)return arr[0];
	if(arr[0]!=arr[1])return arr[0];
	if(arr[n-1]!=arr[n-2])return arr[n-1];
	while(low<=high)
	{
		int i=low+(high-low)/2;
		if(arr[i]!=arr[i-1]&&arr[i]!=arr[i+1])
			return arr[i];
		if(i%2==1&&arr[i]==arr[i-1]||i%2==0&&arr[i]==arr[i+1])
			low=i+1;
		else
			high=i-1;

	}
}
