bool find(vector<int> &stalls,int mid,int k,int n)
{
    int cows=1,position=0;
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-stalls[position]>=mid)
        {
            position=i;
            cows++;
            if(cows==k)
                return true;
        }
        
    }
    return false;
    
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    //TC=O(nlogn)+O(log(high-low)*n) SC=O(1)
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int low=1,high=stalls[n-1]-stalls[0];
    int ans;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        //check if we can maintain a min. distance of atleast mid b/w cows
        if(find(stalls,mid,k,n))
        {
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
