#include <bits/stdc++.h> 
long long merge(long long *arr, int low,int mid,int high)
{
    int left=low,right=mid+1;
    int cnt=0;
    vector<int> temp;
    while(left<=mid&&right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
            cnt+=mid+1-left;//inversions
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;   
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}
long long mergesort(long long *arr, int low,int high)
{
    int cnt=0;
    if(low>=high)return cnt;
    int mid=(low+high)/2;
    cnt+=mergesort(arr,low,mid);
    cnt+=mergesort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    /*Brute force TC=O(n2) SC=O(1)
    long long count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
                count++;
        }
    }
    return count;
    */
    //using mergesort TC=O(nlogn) SC=O(n)
    return mergesort(arr,0,n-1);
}
