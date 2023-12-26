#include<bits/stdc++.h>
int majorityElement(vector<int> v) {
	// Write your code here
	/*Brute force TC=O(n2) SC=O(1)
	int n = v.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }
    return -1;
	*/
    /*Better approach TC=O(n*logn)+O(n) SC=O(n)
    int n = v.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
    */

	/*MYApproach :Tc=O(nlogn) SC=O(1)
	sort(v.begin(),v.end());
	int n=v.size()/2;
	return v[n];
    */

    //optimal way : Moore Voting ALgorithm TC=O(n) SC=O(1)
    int c1=0,ele,n=v.size();
    for(int i=0;i<n;i++)
    {
        if(c1==0)
        {
            c1++;
            ele=v[i];
        }
        else if(ele==v[i])c1++;
        else c1--;
    }
    int c2=0;
    for(int i=0;i<n;i++)
    {
        if(ele==v[i])c2++;
    }
    if(c2>(n/2))return ele;
    return -1;


}
