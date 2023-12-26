double myPow(double x, int n) {
    // Write Your Code Here
    /*brute force TC=O(n) SC=O(1)
    if(n<0)
        nn=(-1)*n;
    double ans = 1.0;
    for (int i = 0; i < nn; i++) {
        ans = ans * x;
    }
    if(n<0)
        return 1/ans;
    return ans;
    */
    //optimal using Binary Exponentation TC=O(logn) sc=O(1)
    int pow;
    double res=1.0;
    if(n<0)
        pow=(-1)*n;
    else    
        pow=n;
    while(pow)
    {
        if(pow%2)
        {
            res=res*x;
            pow--;
        }
        else
        {
            x=x*x;
            pow=pow/2;
        }
    }
    if(n<0)
        return 1/res;
    return res;
 
}
