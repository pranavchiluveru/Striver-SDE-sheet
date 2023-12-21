#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
  /*Approach 1
    next_permutation(permutation.begin(),permutation.end());
    return permutation;
  */
    //  Write your code here.
    int f=0,ind=-1;
   // Step 1: Find the break point:
    for(int i=n-2;i>=0;i--)
    {
        if(permutation[i]<permutation[i+1])
        {
            ind=i;
            break;
        }
    }
  //If break point is not found reverse ;ex:4 3 2 1 ans is 1 2 3 4
    if(ind==-1)
    {
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
  //If break point is found find the next greater ele and swap it with ind ;ex :1 3 2 we get 2 3 1
    for(int i=n-1;i>ind;i--)
    {
        if(permutation[i]>permutation[ind])
        {
            swap(permutation[ind],permutation[i]);
            break;
        }
    }  
    //reverse the right half to ind ; 3 1 we get 1 3 
    reverse(permutation.begin()+ind+1,permutation.end());
    return permutation; //return 2 1 3
    
}
