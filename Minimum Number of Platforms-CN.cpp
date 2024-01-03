
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    //optimal approach
    sort(at,at+n);
    sort(dt,dt+n);
    int pt=1,ans=1;
    int i=0,j=1;
    while(i<n&&j<n)
    {
       if(at[j]<=dt[i])
       {
           pt++;
           j++;
       }
       else
       {
           i++;
           pt--;
       }
       ans=max(ans,pt);
    }
    return ans;
    
}
