#include<bits/stdc++.h>
vector<int> MinimumCoins(int n)
{
    // Write your code here
    //Tc=O(n) SC=O(1)
    vector<int> values={1,2,5,10,20,50,100,500,1000};
    vector<int> ans;
    int num=values.size();
    for(int i=num-1;i>=0;i--)
    {
        while(n>=values[i])
        {
            n=n-values[i];
            ans.push_back(values[i]);
        }
        
        if(n==0)break;
    }
    return ans;
}
