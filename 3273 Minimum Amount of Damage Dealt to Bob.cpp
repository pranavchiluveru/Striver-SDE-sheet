class Solution {
public:
     struct CustomComparator {
        public:
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            double dps1 = double(p1.first)/p1.second;
            double dps2 = double(p2.first)/p2.second;
            if(dps1==dps2)
                return p1.first<p2.first;
            return dps1<dps2;
        }
    };


    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n=damage.size();
        long long dp=0;
        long long ans=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomComparator> pq;
        for(int i=0;i<n;i++)
        {
            dp+=damage[i];
            int t=ceil(double(health[i])/power);
            pq.push({damage[i],t});
        }
        while(!pq.empty())
        {
            int d=pq.top().first;
            int t=pq.top().second;
            pq.pop();
            ans+=t*dp;
            dp-=d;

        }
       

        return ans;
    }
};
