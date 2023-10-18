//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool check_cycle(int node,vector<int> &vis,vector<int> &pathvisited,vector<int> adj[],vector<int> &check){
        vis[node] = 1;
        pathvisited[node]=1;
        check[node]=0;
        
        for(auto num : adj[node]){
            if(!vis[num]){
                if(check_cycle(num,vis,pathvisited,adj,check)==true){
                    return true;
                }
            }
            //if that any node in the current path is already is visited it means there is cycle
            else if(pathvisited[num]){
                return true;
            }
        }
        //if only there is no cycle from node then only execution will come down so mark check[node]=1
        check[node]=1;
        //set that path back to 0
       
        pathvisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> vis(V,0);
        vector<int> pathvisited(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                check_cycle(i,vis,pathvisited,adj,check);
                
            }    
        }
        for(int i =0;i < V; i++){
            if(check[i]==1){
                ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends