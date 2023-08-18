class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int,int>> st;
        vector<int> vec[n];
        int m = roads.size();
        for(int i = 0; i < m; i++){
            st.insert({roads[i][0],roads[i][1]});
            st.insert({roads[i][1],roads[i][0]});
            vec[roads[i][0]].push_back(roads[i][1]);
            vec[roads[i][1]].push_back(roads[i][0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int num ;
                if(st.find({i,j})!=st.end()){
                    num = vec[i].size() + vec[j].size() - 1;
                }
                else
                    num = vec[i].size() + vec[j].size();
                ans = max( ans , num );
            }
        }
        return ans;
    }
};