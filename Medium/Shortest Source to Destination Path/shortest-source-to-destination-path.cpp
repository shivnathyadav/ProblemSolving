//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool valid(int x, int y, int n,int m){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    int shortestDistance(int n, int m, vector<vector<int>> mat, int dx, int dy) {
        // code here
        queue<pair<int,pair<int,int>>> que;
        que.push({0,{0,0}});
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        vis[0][0]=true;
        int x[4] = {-1,0,1,0};
        int y[4] = {0,1,0,-1};
        
        while(!que.empty()){
            int steps = que.front().first;
            int row = que.front().second.first;
            int col = que.front().second.second;
            que.pop();
            if(row==dx && col==dy){
                return steps;
            }
            for(int i = 0; i < 4; i++){
                int newx = row + x[i];
                int newy = col + y[i];
                if(valid(newx,newy,n,m)){
                    if(!vis[newx][newy] && mat[newx][newy]==1){
                        que.push({steps+1,{newx,newy}});
                        vis[newx][newy]=true;
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends