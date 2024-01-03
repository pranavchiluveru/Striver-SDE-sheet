#include<bits/stdc++.h>
struct meet
{
    int start;
    int end;
    int pos;
};
//sort based on end time ....if same end time sort on position
bool static comparator(struct meet m1,struct meet m2)
{
    if(m1.end<m2.end)return true;
    else if(m1.end>m2.end)return false;
    else if(m1.pos<m2.pos)return true;
    return false;
}
int maximumMeetings(vector<int> &s, vector<int> &e)
{
    // Write your code here.TC=O(n)+O(nlogn)+O(n) SC=O(n)
    int n=s.size();
    struct meet m[n];
    for(int i=0;i<n;i++)
    {
        m[i].start=s[i];
        m[i].end=e[i];
        m[i].pos=i;
    }
    sort(m,m+n,comparator);
    int res=1;
    int endtime=m[0].end;
    for(int i=1;i<n;i++)
    {
        if(m[i].start>endtime)
        {
            res++;
            endtime=m[i].end;
        }
    }
    return res;

}
