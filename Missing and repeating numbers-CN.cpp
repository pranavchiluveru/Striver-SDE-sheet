#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	// Write your code here 
	/*Brute force Tc=O(n2) SC=O(1)
	int miss=-1,rep=-1;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(arr[j]==i)
				cnt++;
		}
		if(cnt==0)
			miss=i;
		if(cnt>1)
			rep=i;
		if(miss!=-1&&rep!=-1)
			break;

	}
	return {miss,rep};
	*/
	/*using frequency array TC=O(n) SC=O(n)
	int freq[n+1]={0};
	int miss,rep;
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
		if(freq[arr[i]]>1)
			rep=arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(freq[i]==0)
		{
			miss=i;
			return {miss,rep};
		}
	}
	*/
	//Using maths TC=O(n) SC=O(1)
	long long sn=(n*(n+1))/2;
	long long s2n=(n*(n+1)*(2*n+1))/6;
	long long s=0,s2=0;
	for(int i=0;i<n;i++)
	{
		s+=arr[i];
		s2+=(long long)arr[i]*(long long)arr[i];
	}
	//s-sn=rep-miss; s2-s2n=rep2-miss2
	long long var1=s-sn;
	long long var2=s2-s2n;
	var2=var2/var1;//rep+miss
	long long rep=(var1+var2)/2;
	long long miss=rep-var1;
	return {(int)miss,(int)rep};
}
