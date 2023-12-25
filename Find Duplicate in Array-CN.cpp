#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n) {
  // Write your code here.
  /*TC=O(n)*O(n) SC=O(n)
	set<int> s;
	for(int i=0;i<n;i++)
	{
		if(s.find(arr[i])!=s.end())
			return arr[i];
		else
			s.insert(arr[i]);
	}
	*/
  /* Using Sorting: TC=O(nlogn)+O(n) SC=O(1)
  	sort(arr.begin(), arr.end());
  	for (int i = 0; i < n; i++)
    {
		if(arr[i]==arr[i+1])
			return arr[i];
	}
	*/
	/*using frequncy array :Tc=O(n) SC=O(n)
	int a[n]={0};
	for(int i=0;i<n;i++)
	{
		a[arr[i]]++;
		if(a[arr[i]]>1)
			return arr[i];
	}
	*/
	//Using linked list fast and slow pointers TC=O(n) SC=O(1)
	int fast=arr[0];
	int slow=arr[0];
	do{
		slow=arr[slow];
		fast=arr[arr[fast]];
	}while(fast!=slow);
	fast=arr[0];
	while(slow!=fast)
	{
		slow=arr[slow];
		fast=arr[fast];
	}
	return slow;	
}
