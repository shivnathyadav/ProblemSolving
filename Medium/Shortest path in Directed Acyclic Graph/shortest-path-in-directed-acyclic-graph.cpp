//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void topoSort(int node,vector<bool> &vis,stack<int> &st,vector<pair<int,int>> adj[]){
         vis[node] = true;
         for(auto it : adj[node]){
             if(!vis[it.first])
                 topoSort(it.first,vis,st,adj);
         }
         st.push(node);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int> st;
        vector<bool> vis(n,false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                topoSort(i,vis,st,adj);
            }
        }
        vector<int> dist(n,1e9);
        dist[0]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                if(dist[node] + weight < dist[adjNode]){
                    dist[adjNode] = dist[node] + weight ;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dist[i]>=1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends