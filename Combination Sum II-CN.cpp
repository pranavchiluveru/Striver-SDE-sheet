#include<bits/stdc++.h>
/*
void find(int i,vector<int> &arr, int n, int target,set<vector<int>> &s,vector<int> temp)
{
	if(target==0)
	{
		s.insert(temp);
		return;
	}
	if(i==n)return;
	find(i+1,arr,n,target,s,temp);
	temp.push_back(arr[i]);
	find(i+1,arr,n,target-arr[i],s,temp);
}
*/
void find(int i,vector<int> &arr, int n, int target,vector<vector<int>> &res,vector<int> temp)
{
	if(target==0)
	{
		res.push_back(temp);
		return;
	}
	for(int ind=i;ind<n;ind++)
	{
		if(ind!=i&&arr[ind]==arr[ind-1])continue;
		if(arr[ind]>target)break;
		temp.push_back(arr[ind]);
		find(ind+1,arr,n,target-arr[ind],res,temp);
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	/*solution 1 :using set TC=(2^n*logn) SC=O(2^n)
	set<vector<int>> s;
	vector<int> temp;
	sort(arr.begin(),arr.end());
	find(0,arr,n,target,s,temp);
	vector<vector<int>> res(s.begin(),s.end());
	return res;
	*/
	//Solution 2 : using no extra space TC=O(nlogn)+O(2^n) SC=O(n) for recursion
	vector<int> temp;
	vector<vector<int>> res;
	sort(arr.begin(),arr.end());
	find(0,arr,n,target,res,temp);
	return res;
	
}
