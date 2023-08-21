//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int dx[8] = {-1,-1,-1,1,1,1,0,0};
        int dy[8] = {-1,0,1,-1,0,1,1,-1};
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        for(int  i = 0; i < n; i++){
            
            for(int j = 0; j < matrix[i].size(); j++){
                int cnt = 0;
                if(matrix[i][j]==1){
                    for(int k = 0; k < 8; k++){
                        int row = i + dx[k];
                        int col = j + dy[k];
                        if(valid(row,col,n,m)){
                            if(matrix[row][col]==0){
                                cnt += 1;
                            }
                        }
                    }
                }
                if(cnt%2==0 && cnt>0){
                    count += 1;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends