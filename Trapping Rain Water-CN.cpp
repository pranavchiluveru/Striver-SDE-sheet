#include<bits/stdc++.h>
long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    /*Brute Force TC=O(n2) SC=O(1)
    long long maxeletoleft=arr[0];
    long long sum=0;
    for(int i=1;i<n-1;i++)
    {
        long long maxeletoright=arr[n-1];
        int ele=arr[i];
        if(ele>maxeletoleft)maxeletoleft=ele;
        for(int j=i;j<n-1;j++)
            if(arr[j]>maxeletoright)
                maxeletoright=arr[j];
        sum=sum+min(maxeletoright,maxeletoleft)-arr[i];
    }
    return sum;
    */
    /*Better solution TC=O(3n) SC=O(n)
    vector<long long> maxleft(n);
    vector<long long> maxright(n);
    long long maxl=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxl) 
            maxl=arr[i];
        maxleft[i]=maxl;
    }
    long long maxr=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>maxr) 
            maxr=arr[i];
        maxright[i]=maxr;
    }
    long long sum=0;
    for(int i=1;i<n-1;i++)
    {
        sum+=min(maxleft[i],maxright[i])-arr[i];
    }
    return sum;
    */
    //optimal approach using Two pointers
    //TC=O(n) SC=O(1)
    long long maxl=0,maxr=0;
    int l=0,r=n-1;
    long long res=0;
    while(l<=r)
    {
        if(arr[l]<=arr[r])
        {
            if(arr[l]>=maxl)
                maxl=arr[l];
            else
                res+=maxl-arr[l];
            l++;
        }
        else
        {
            if(arr[r]>=maxr)
                maxr=arr[r];
            else
                res+=maxr-arr[r];
            r--;
        }
    }
    return res;
}
