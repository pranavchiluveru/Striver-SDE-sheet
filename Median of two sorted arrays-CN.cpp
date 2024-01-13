double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	/*brute force TC=O(n) SC=O(n)
	int n1=a.size(),n2=b.size(),i=0,j=0;
	int n=n1+n2;
	vector<int> res;
	while(i<n1&&j<n2)
	{
		if(a[i]<b[j])
			res.push_back(a[i++]);
		else	
			res.push_back(b[j++]);
	}
	while(i<n1)
	{
		res.push_back(a[i++]);
	}
	while(j<n2)
	{
		res.push_back(b[j++]);
	}
	if(n%2==1)
		return res[n/2];
	return (double)(res[n/2]+res[n/2-1])/2;
	*/
	/*Better Approach TC=O(N) SC=O(1)
	int n1=a.size(),n2=b.size(),i=0,j=0;
	int n=n1+n2;
	int ind1=n/2,ind2=n/2-1;
	int ind1ele,ind2ele;
	int c=0;
	while(i<n1&&j<n2)
	{
		if(a[i]<b[j])
		{
			if(c==ind1)ind1ele=a[i];
			if(c==ind2)ind2ele=a[i];
			c++;
			i++;
		}
		else	
		{
			if(c==ind1)ind1ele=b[j];
			if(c==ind2)ind2ele=b[j];
			j++;
			c++;
		}
	}
	while(i<n1)
	{
		if(c==ind1)ind1ele=a[i];
		if(c==ind2)ind2ele=a[i];
		c++;
		i++;
	}
	while(j<n2)
	{
		if(c==ind1)ind1ele=b[j];
		if(c==ind2)ind2ele=b[j];
		j++;
		c++;
	}
	if(n%2==1)
		return ind1ele;
	return (double)(ind1ele+ind2ele)/2;
	*/
	//TC=O(log(min(m,n)))
	int m=a.size(),n=b.size();
	if(n>m)
		return median(b,a);
	int num=n+m;
	int k=(num+1)/2;//if there are 5 elements search for 3 element ..if 6 elements we search for 3rd and get  4th also automatically
	int low=max(0,k-n),high=min(m,k);
	while(low<=high)
	{
		int cut1=low+(high-low)/2;
		int cut2=k-cut1;
		int l1=cut1==0?INT_MIN:a[cut1-1];
		int l2=cut2==0?INT_MIN:b[cut2-1];
		int r1=cut1==m?INT_MAX:a[cut1];
		int r2=cut2==n?INT_MAX:b[cut2];
		if(l1<=r2&&l2<=r1)
		{
			if(num%2==1)
				return max(l1,l2);
			else
				return (double)(max(l1,l2)+min(r1,r2))/2;
		}
		else if(l2>r1)
			low=cut1+1;
		else	
			high=cut1-1;
	}
	return 0;
	
}
