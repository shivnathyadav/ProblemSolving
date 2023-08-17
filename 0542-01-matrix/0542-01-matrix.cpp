class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vec(n , vector<int> (m,0));
        vector<vector<int>> vis(n , vector<int> (m,0));
        queue<pair<pair<int,int>,int>> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    que.push({{i,j},0});
                    vis[i][j]=1;
                    vec[i][j]=0;
                }
            }
        }
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,-1,1};
        while(!que.empty()){
            int row = que.front().first.first;
            int col = que.front().first.second;
            int dis = que.front().second;
            que.pop();
            vec[row][col]=dis;

            for(int ind = 0; ind < 4; ind++){
                int newx = row + x[ind];
                int newy = col + y[ind];
                if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy]){
                    que.push({{newx,newy},dis+1});
                    vis[newx][newy]=1;
                }
            }
        }
        return vec;
    }
};