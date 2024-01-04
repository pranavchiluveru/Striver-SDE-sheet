#include <bits/stdc++.h> 
struct xyz
{
    double ratio;
    int index;
};
bool static comparator(struct xyz a,struct xyz b)
{
    if(a.ratio>b.ratio)return true;
    else return false;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    struct xyz a[n];
    for(int i=0;i<n;i++)
    {
        a[i].ratio=(double)items[i].second/(double)items[i].first;
        a[i].index=i;
    }
    sort(a,a+n,comparator);
    int i=0;
    double ans=0;
    while(i<n)
    {
        int ind=a[i].index;
        int weight=items[ind].first;
        int profit=items[ind].second;
        if(w-weight>=0)
        {
            w=w-weight;
            ans+=profit;
        }
        else
        {
            ans+=(double)(profit*w)/(weight);
            w=0;
            break;
        }
        i++;
    }
    return ans;
}
