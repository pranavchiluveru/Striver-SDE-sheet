#include<bits/stdc++.h>
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    /*Brute Force TC=O(n2) SC=O(1)
    long long msum=0;
    for(int i=0;i<n;i++)
    {
        long long sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum>msum)
                msum=sum;
        }

    }
    return msum;
    */
    //kadanes Algorithm TC=O(n) SC=O(1)
    long long msum=0,sum=0;
    int startindex=-1,endindex=-1,start=-1;
    for (int i = 0; i < n; i++) {
      if(sum==0) start=i;
      sum += arr[i];
      if (sum <= 0)
        sum = 0;
      if (msum < sum) {
        msum = sum;
        startindex = start;
        endindex = i;
      }
    }
    return msum;
}
