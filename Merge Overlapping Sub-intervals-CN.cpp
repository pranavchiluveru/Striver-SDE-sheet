#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	/*my solution 
	vector<vector<int>> res;
	int left,right,j,i;
	for(i=0;i<arr.size();i++)
	{
		left=arr[i][0];
		right=arr[i][1];
		for(j=i+1;j<arr.size();j++)
		{
			if(right>=arr[j][0])
			{
				if(right<arr[j][1])
					right=arr[j][1];
				
			}
			else
			{	
				i=j-1;
				break;
			}
		}
		res.push_back({left,right});
		if(j==arr.size())
			break;
	}
	return res;
	*/
	//striver solution TC=O(N) SC=O(N)
	vector<vector<int>> res;
	for(int i=0;i<arr.size();i++)
	{
		if(res.empty()||arr[i][0]>res.back()[1])
		{
			res.push_back(arr[i]);
		}
		else
		{
			res.back()[1]=max(res.back()[1],arr[i][1]);
		}
	}
	return res;
}
