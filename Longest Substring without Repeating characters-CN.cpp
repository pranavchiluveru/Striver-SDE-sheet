#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    //slinding window TC=O(2n) SC=O(n)
    int n=input.length(),maxlen=0,count=0;
    unordered_set<char> a;
    int l=0,r=0;
    while(r<n)
    {
        while (a.find(input[r]) != a.end()) 
        {
            a.erase(input[l]);
            l++;
        }
        a.insert(input[r]);
        maxlen=max(maxlen,r-l+1);
        r++;
        
    }
    return maxlen;
}
