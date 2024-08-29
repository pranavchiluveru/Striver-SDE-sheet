vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n1=A.size();
    int n2=B.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int> res;
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> st;
    pq.push({A[n1-1]+B[n2-1],{n1-1,n2-1}});
    st.insert({n1-1,n2-1});
    while(C--)
    {
        int sum=pq.top().first;
        int idx1=pq.top().second.first;
        int idx2=pq.top().second.second;
        pq.pop();
        res.push_back(sum);
        if(idx1-1>=0&&st.find({idx1-1,idx2})==st.end())
        {
            pq.push({A[idx1-1]+B[idx2],{idx1-1,idx2}});
            st.insert({idx1-1,idx2});
        }
        if(idx2-1>=0&&st.find({idx1,idx2-1})==st.end())
        {
            pq.push({A[idx1]+B[idx2-1],{idx1,idx2-1}});
            st.insert({idx1,idx2-1});
        }
        
    }
    
    return res;
}
