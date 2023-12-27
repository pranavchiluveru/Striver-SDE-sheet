#include<bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {
	// Write your code here
	//note:max two elements will apppear more than florr(n/3) times
	/*brute force TC=O(n2) SC=O(1)
	int n=v.size();
	vector<int> res;
	for(int i=0;i<n;i++)
	{
		int count=0;
		if(res[0]!=v[i]||res.size()==0)
		{
			for(int j=0;j<n;j++)
			{
				if(v[i]==v[j])
				{
					count++;
				}
			}
			if(count>floor(n/3))
				res.push_back(v[i]);
		}
		if(res.size()==2)
			break;
	}
	return res;
	*/
	/*Better solution TC=O(nlogn) SC=O(n)
	map<int,int> mymap;
	int n=v.size();
	vector<int> res;
	for(int i=0;i<n;i++)
	{
		mymap[v[i]]++;
	}
	for(auto it:mymap)
	{
		if(it.second>floor(n/3))
			res.push_back(it.first);
	}
	return res;
	*/
	//optimal voters algorithm TC=O(n+n) Sc=O(1)
	int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}
