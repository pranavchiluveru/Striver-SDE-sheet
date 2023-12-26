#include<bits/stdc++.h>
/*better
bool binarysearch(vector<vector<int>>& mat,int row,int target)
{
    int low=0,high=mat[0].size()-1;
    while (low <= high) {
      int mid = (low)+(high-low)/2;
      if (mat[row][mid] == target)
        return 1;
      else if (mat[row][mid] < target)
        low=mid+1;
      else
        high=mid-1;
    }
    return 0;
}
*/
bool binarysearch(int low,int high,vector<vector<int>>& mat,int target)
{
    int cols=mat[0].size();
    while(low<=high)
    {
        int mid=low+(high-low)/2;//index 5 row=1,col=1
        int row=mid/cols;
        int col=mid%cols;
        if (mat[row][col] == target)
            return 1;
        else if (mat[row][col] < target)
            low=mid+1;
        else
            high=mid-1;
    }
    return 0;

}
bool searchMatrix(vector<vector<int>>& mat, int target) {
        /*brute force TC=O(m*n) SC=O(1)
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==target)
                    return 1;
            }
        }
        return 0;
        */
        /*Better Tc=O(m)+O(logn) SC=O(1)
        int col=mat[0].size();
        bool b=0;
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][0]<=target && mat[i][col-1]>=target)
                b=binarysearch(mat,i,target);
            if(b==1)
                return 1;
        }
        return b;
        */
        //optimal TC=(log(nm)) SC=O(1)
        int m=mat.size(),n=mat[0].size();
        int low=0,high=m*n-1;
        return binarysearch(low,high,mat,target);
}
