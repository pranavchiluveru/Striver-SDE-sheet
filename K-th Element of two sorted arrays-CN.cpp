#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    /*TC=O(k) SC=O(1)
    int i=0,j=0,plates=0;
    while(i<m&&j<n)
    {
        if(row1[i]<=row2[j])
        {
            plates++;
            if(plates==k)
                return row1[i];
            i++;
        }
        else
        {
            plates++;
            if(plates==k)
                return row2[j];
            j++;
        }
    }
    while(i<m)
    {
            plates++;
            if(plates==k)
                return row1[i];
            i++;
    }
    while(j<n)
    {
            plates++;
            if(plates==k)
                return row2[j];
            j++;
    }
    */
    //TC=O(log(min(m,n))), sc=O(1)
    if(m>n)
        return ninjaAndLadoos(row2,row1,n,m,k);//we perform binary seach on min length array
    int low=max(0,k-n),high=min(k,m);
    while(low<=high)
    {
        int cut1=low+(high-low)/2;
        int cut2=k-cut1;
        int l1=(cut1==0)?INT_MIN:row1[cut1-1];
        int l2=(cut2==0)?INT_MIN:row2[cut2-1];
        int r1=(cut1==m)?INT_MAX:row1[cut1];
        int r2=(cut2==n)?INT_MAX:row2[cut2];
        if(l1<=r2&&l2<=r1)
            return max(l1,l2);
        else if(l1>r2)
            high=cut1-1; 
        else
            low=cut1+1;
    }
    return 1;
    
}
