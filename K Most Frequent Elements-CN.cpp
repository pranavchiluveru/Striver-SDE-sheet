#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    /*Approach 1:TC=O(n)+O(n)+O(nlogn)+O(k) SC=O(n)+O(n)
    vector<int> res;
    unordered_map<int,int> mpp;//store val,count
    for(int i=0;i<arr.size();i++)
    {
        mpp[arr[i]]++;
    }
    vector<pair<int,int>> v;//stores count,val
    for(auto it:mpp)
    {
        v.push_back(make_pair(it.second,it.first));
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());//sorts acc to count in descending order
    for(int i=0;i<k;i++)
    {
        res.push_back(v[i].second);
    }
    return res;
    */
    /*Approach 2: using min heap :TC=O(n)+O(nlogk)+O(k) SC=O(n)+O(n)
    vector<int> res;
    unordered_map<int,int> mpp;//store val,count
    for(int i=0;i<arr.size();i++)
    {
        mpp[arr[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
    for(auto i:mpp)
    {
        min_heap.push({i.second, i.first}); // stores count,val
        if(min_heap.size()>k)//only stores k elements inside min_heap
        {
            min_heap.pop();//if >k it pops out val with smallest count
        }
    }
    while(k--)
    {
        res.push_back(min_heap.top().second);
        min_heap.pop();
    }
    return res;
    */
    //Approcah 3 :using Bucket sort TC=O(n) SC=O(n)
    vector<int> res(k);
    unordered_map<int,int> mpp;//store val,count
    for(int i=0;i<arr.size();i++)
    {
        mpp[arr[i]]++;
    }
    vector<vector<int>> bucket(n+1);
    // Place elements in the corresponding bucket based on their frequency
    for(auto it : mpp)
    {
        bucket[it.second].push_back(it.first);
    }
    int index=0;
    // Traverse the buckets in reverse order to get elements with higher frequency first
    for (int i = n; i >= 0&&k>0 ; i--)
    {
        if(bucket[i].size()==0)continue;
        for(int num:bucket[i])
        {
            res[index++]=num;
            k--;
            if(k==0)
                break;
        }
    }

    return res;


}
