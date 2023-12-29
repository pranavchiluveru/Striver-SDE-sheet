#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    /*brute force TC=O(n2) Sc=O(1)
    int n=a.size(),count=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum=sum^a[j];
            if(sum==b)
                count++;
        }
    }
    return count;
    */
    //using map Tc=O(n) SC=O(n)
    int n=a.size(),count=0;
    unordered_map<int,int> m;//xor till now ,count
    m[0]=1;
    int xr=0;//xor till now
    for(int i=0;i<n;i++)
    {
        xr^=a[i];
        int req=xr^b;//req is xor of elements before subarray with xor b
        if(m.find(req)!=m.end())
        {
            count+=m[req];
        }
        m[xr]++;
    }
    return count;
}
