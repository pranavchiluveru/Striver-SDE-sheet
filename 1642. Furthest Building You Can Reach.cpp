class Solution {
public:
    /*DP-TC=O(n^3) SC=O(n^3)
    int find(int ind,vector<int>& heights, int bricks, int ladders,vector<vector<vector<int>>> &dp)
    {
        if(ind==heights.size()-1)
            return 0;
        if(heights[ind+1]>heights[ind]&& bricks<heights[ind+1]-heights[ind]&&ladders==0)
            return 0;
        if(dp[ind][bricks][ladders]!=-1) return dp[ind][bricks][ladders];
        if(heights[ind+1]<=heights[ind])
            return dp[ind][bricks][ladders]=1+find(ind+1,heights,bricks,ladders,dp);
        else
        {
            int withbricks=0,withlad=0;
            if(bricks>=heights[ind+1]-heights[ind])
            {
                withbricks=find(ind+1,heights,bricks-heights[ind+1]+heights[ind],ladders,dp);
            }
            if(ladders>0)
            {
                withlad=find(ind+1,heights,bricks,ladders-1,dp);
            }
            return dp[ind][bricks][ladders]=1+max(withbricks,withlad);
        }
    }
    */
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //vector<vector<vector<int>>> dp(heights.size()+1, vector<vector<int>>(bricks+1, vector<int>(ladders+1, -1)));
        //return find(0,heights,bricks,ladders,dp);

        //Greedy Approach :Using ladders for highest_diff and bricks for smallest_diff TC=O(n*log(ladders)) SC=O(ladders)
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) {
                pq.push(diff);
                
                if (pq.size() > ladders) {
                    int smallest_diff = pq.top();
                    pq.pop();
                    bricks -= smallest_diff;
                    
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        
        return heights.size() - 1;
    }
};
