#include <bits/stdc++.h> 
/*Approach 2
vector<int> merge(vector<int> v1,vector<int> v2)
{
    int i=0,j=0;
    vector<int> res;
    while(i<v1.size()&&j<v2.size())
    {
        if(v1[i]<=v2[j])
        {
            res.push_back(v1[i]);
            i++;
        }
        else
        {
            res.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size())
    {
        res.push_back(v1[i]);
        i++;
    }
    while(j<v2.size())
    {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}
*/
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    /*Approach 1 :TC=O(k*n)+O(k*nlog(k*n)) SC=O(k*n) 
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<kArrays[i].size();j++)
        {
            res.push_back(kArrays[i][j]);
        }
    }
    sort(res.begin(),res.end());
    return res;
    */
    /*Approach 2 :TC=O(k*(n*k))
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        res=merge(res,kArrays[i]);
    }
    return res;
    */
    //Approach 3: USing Minheaps TC=O(n*k*log(k)) SC=O(n*k)
    vector<int> result; 
  
    // Create a min heap to store atmost k heap nodes at a time.
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap; 
    for (int i = 0; i < kArrays.size(); i++)
    {
        minHeap.push({kArrays[i][0],{ i,0}}); //element,array number,index
    }
  
    while (!minHeap.empty()) 
    { 
    
        // Remove the minimum element from the heap.
        pair<int,pair<int,int>> curr = minHeap.top(); //takes log(k) time
        minHeap.pop(); 
  
        // i is the array number and j is the index of the removed element in the ith array.
        int i = curr.second.first; 
        int j = curr.second.second; 
    
        // Add the removed element to the output array.
        result.push_back(curr.first); 
  
        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < kArrays[i].size())
        {
            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
        }
    } 
  
    // Return the output array.
    return result;
}
