//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int level = 0;
	    queue<pair<int,int>> que;
	    vector<bool> vis(V,false);
	    que.push({0,0});
	    vis[0]=true;
	    while(!que.empty()){
	        int sz = que.size();
	        for(int i = 0;i<sz;i++){
	            int curr = que.front().first;
	            int level = que.front().second;
	            que.pop();
	            if(curr == X){
	                return level;
	            }
	            for(auto it:adj[curr]){
	                if(!vis[it]){
	                    que.push({it,level+1});
	                    vis[it]=true;
	                }
	                
	            }
	        }
	        level += 1;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends