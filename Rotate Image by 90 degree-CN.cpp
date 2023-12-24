#include <bits/stdc++.h>

void rotateMatrixby90degree(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    //TC=O(n*n)+O(n*n) SC=O(1)
    //transpose the matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    //reverse each row of matrix
    for(int i=0;i<n;i++)
    {
        reverse(mat[i].begin(),mat[i].end());
    }

}
