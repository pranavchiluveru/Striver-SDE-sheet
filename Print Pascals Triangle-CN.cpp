#include<bits/stdc++.h>
//TC=O(n*n) sc=O(1)
vector<vector<int>> pascalTriangle(int n) {
    // Write your code here.
    vector<vector<int>> res(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        res[i].resize(i + 1, 1);
        for(int j=1;j<i;j++)
        {
             res[i][j]=res[i-1][j]+res[i-1][j-1];
        }
    }
    return res;
}
