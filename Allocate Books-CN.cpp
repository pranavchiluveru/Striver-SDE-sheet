bool find(vector<int>& arr, int mid,int n,int m)
{
   
    int students=1,student_pages=0;
    for(int i=0;i<n;i++)
    {
        student_pages+=arr[i];
        if(student_pages>mid)
        {
            students++;
            student_pages=arr[i];
        }
        if(students>m)
            return false;
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    //TC=O(log(sum(arr)-max(arr))*n) SC=O(1)
    if(m>n)return -1;//no of students greater than books
    int low=-1,high=0;;
    for(int i=0;i<n;i++)
    {
        low=max(low,arr[i]);
        high+=arr[i];
    }
    int ans;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(find(arr,mid,n,m))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;

}
