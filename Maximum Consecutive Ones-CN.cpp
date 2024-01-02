#include<bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    //Using sliding window TC=O(n) SC=O(1)
    //make sure your window contains always atmax k zeros
    int i=0,j=0,zerocount=0,len=INT_MIN;
    while(j<n)
    {
        if (arr[j] == 0)zerocount++;
        while (zerocount > k) 
        {
            if (arr[i] == 0)
                zerocount--;
            i++;
        }
       
        len=max(len,j-i+1);
        j++;
    }
    return len;
}
