#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	//TC=O(min(n,m))+O(nlogn)+O(mlogm) Sc=O(1)
	int i=a.size()-1,j=0;
	while(i>=0&&j<b.size())
	{
		if(a[i]>b[j])
		{
			swap(a[i],b[j]);
			i--;
			j++;
		}
		else
		{
			break;
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
}
