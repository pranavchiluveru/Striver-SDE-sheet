#include<vector>
#include<bits/stdc++.h>
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	/*brute force TC=O(n2) sc=O(1)
	int n=arr.size(),maxlen=0;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=arr[j];
			if(sum==0)
			{
				maxlen=max(maxlen,j-i+1);
			}
		}
	}
	return maxlen;
	*/
	//using Hashmap TC=O(n) SC=O(n)
	int n=arr.size(),maxlen=0;
	int sum=0;
	unordered_map<int,int> umap;//sum,index
	umap[0]=-1;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(umap.find(sum)==umap.end())
			umap[sum]=i;
		else
		{
			maxlen=max(maxlen,i-umap[sum]);
		}
	}
	return maxlen;
}
