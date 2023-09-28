//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &grid){
        visited[i][j]=true;
        grid[i][j]=0;
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        for(int k = 0;k<4;k++){
            int newx = i+x[k];
            int newy = j+y[k];
            if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[newx].size() && !visited[newx][newy] && grid[newx][newy]==1){
                dfs(newx,newy,visited,grid);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i = 0;i < n;i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(i,0,visited,grid);
            }
            if(!visited[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,visited,grid);
            }
        }
        for(int i = 0;i < m;i++){
            if(!visited[0][i] && grid[0][i]==1){
                dfs(0,i,visited,grid);
            }
            if(!visited[n-1][i] && grid[n-1][i]==1){
                dfs(n-1,i,visited,grid);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(grid[i][j]==1){
                //    cout<<i<<" "<<j<<endl;
                    ans+=1;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends