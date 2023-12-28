#include<bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    /*brute force TC=O(n2) SC=O(1)
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(book[i]+book[j]==target)
            {
                return "YES";
            }
        }
    }
    return "NO";
    */
    /*better approach TC=O(nlogn)+O(n) SC=O(1)
    sort(book.begin(),book.end());
    int s=0,e=n-1;
    while(s<=e)
    {
        if(book[s]+book[e]==target)
            return "YES";
        else if(book[s]+book[e]>target)
            e--;
        else    
            s++;
    }
    return "NO";
    */
    //optimal approach TC=O(n) SC=O(n)
    unordered_map<int, int> umap; //find takes O(1) whereas in map it takes O(logn)
    for(int i=0;i<n;i++)
    {
        int need=target-book[i];
        if(umap.find(need)!=umap.end())
            return "YES";
        umap[book[i]]=i;

    }
    return "NO";
}
