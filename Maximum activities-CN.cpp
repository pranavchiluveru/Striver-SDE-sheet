#include<bits/stdc++.h>
struct time
{
    int s;
    int e;
};
bool static comparator(struct time a,struct time b)
{
    if(a.e<b.e)return true;
    else if(a.e>b.e)return false;
    else if(a.s<b.s)return true;
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    //TC=O(n)+O(nlogn)+O(n) SC=O(n)
    int n=start.size();
    struct time t[n];
    for(int i=0;i<n;i++)
    {
        t[i].s=start[i];
        t[i].e=finish[i];
    }
    sort(t,t+n,comparator);
    int count=1;
    int endlimit=t[0].e;
    for(int i=1;i<n;i++)
    {
        if(endlimit<=t[i].s)
        {
            endlimit=t[i].e;
            count++;
        }
    }
    return count;

}
