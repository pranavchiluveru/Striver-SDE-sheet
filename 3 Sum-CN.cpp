#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    /*TC=O(n3*logn) SC=O(n)
    
    set<vector<int>> s;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==0)
                {
                    vector<int> trip={arr[i],arr[j],arr[k]};
                    sort(trip.begin(),trip.end());
                    s.insert(trip);//takes logn time   
                }
            }
        }
    }
    vector<vector<int>> res(s.begin(),s.end());
    return res;
    */
    /*TC=O(n2*logn) SC=O(n)
    set<vector<int>> s;
    for(int i=0;i<n;i++)
    {
        set<int> hashset;
        for(int j=i+1;j<n;j++)
        {
            int target=-(arr[i]+arr[j]);
            if(hashset.find(target)!=hashset.end())
            {
                    vector<int> trip={arr[i],arr[j],target};
                    sort(trip.begin(),trip.end());
                    s.insert(trip);
                    
            }
            else
            {
                hashset.insert(arr[j]);
            }
        }
    }
    vector<vector<int>> res(s.begin(),s.end());
    return res;
    */
    //TC=O(nlogn)+O(n2) sc=o(1)
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        if(i!=0&&arr[i]==arr[i-1])continue;
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0)
                j++;
            else if(sum>0)
                k--;
            else
            {
                vector<int> trip = {arr[i], arr[j], arr[k]};
                res.push_back(trip);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                  j++; // removing duplicates
                while (j < k && arr[k] == arr[k + 1])
                  k--;
            }
        }
    }
    return res;
}   
