#include<bits/stdc++.h>
void find(int i,vector<int> &num,int n,vector<int> &res,int sum)
{
	if(i==n)
	{
		res.push_back(sum);
		return;
	}
	find(i+1,num,n,res,sum);
	find(i+1,num,n,res,num[i]+sum);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	//TC=O(2^n) for recursion +O(2^nlog(2^n)) for sorting      SC=O(n)
	vector<int> res;	
	int n=num.size();
	find(0,num,n,res,0);
	sort(res.begin(),res.end());
	return res;
}
