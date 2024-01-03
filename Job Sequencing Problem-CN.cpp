#include<bits/stdc++.h>
struct job{
    int id;
    int deadline;
    int profit;
};
bool static comparator(struct job j1,struct job j2)
{
    return j1.profit>j2.profit;//sorts in Descending order of profit

}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    //TC=O(n*maxdeadline) SC=O(maxdeadline)
    int n=jobs.size();
    struct job j[n];
    int maxdeadline=-1;
    for(int i=0;i<n;i++)
    {
        j[i].id=jobs[i][0];
        j[i].deadline=jobs[i][1];
        j[i].profit=jobs[i][2];
        maxdeadline=max(maxdeadline,jobs[i][1]);
    }
    sort(j,j+n,comparator);
    vector<int> allocation(maxdeadline,-1);
    int profitobtained=0,jobcount=0;
    for(int i=0;i<n;i++)
    {
        int d=j[i].deadline;
        for(int k=d-1;k>=0;k--)
        {
            if(allocation[k]==-1)
            {
                allocation[k]=i;
                jobcount++;
                profitobtained+=j[i].profit;
                break;
            }
        }
    }
    return {jobcount,profitobtained};
    
}
