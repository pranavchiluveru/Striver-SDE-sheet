#include <bits/stdc++.h> 
//TC=O(n!) SC=O(n)
void find(int ind,string &s,vector<string> &res)
{
    if(ind==s.size())
    {
        res.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++)
    {
        swap(s[i],s[ind]);
        find(ind+1,s,res);
        swap(s[i],s[ind]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> res;
    find(0,s,res);
    return res;
}
