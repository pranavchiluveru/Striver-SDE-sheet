#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int maxdiff=0;
    /*Brute force TC=O(n^2) Sc=O(1)
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(prices[j]-prices[i]>maxdiff)
                maxdiff=prices[j]-prices[i];
        }
    }
    return maxdiff;
    */
    //TC=O(n) Sc=O(1)
    int maxele=INT_MIN,maxprofit=0;
    for(int i=n-1;i>=0;i--)
    {
        if(prices[i]>maxele)
            maxele=prices[i];
        else
            maxprofit=max(maxprofit,maxele-prices[i]);
    }
    return maxprofit;
}
