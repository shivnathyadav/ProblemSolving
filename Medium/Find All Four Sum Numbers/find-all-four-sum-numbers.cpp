//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;

        set<vector<int>> vec;
        int n = arr.size();
        for(int i = 0; i < n;i++){
            for(int j = i+1;j<n; j++){
                int st = j+1,end = n-1;
                while(st<end){
                    if(arr[i]+arr[j]+arr[st]+arr[end]==k){
                        vec.insert({arr[i],arr[j],arr[st],arr[end]});
                        st+=1;
                        end-=1;
                    }
                    else if(arr[i]+arr[j]+arr[st]+arr[end]<k){
                        st+=1;
                    }
                    else{
                        end-=1;
                    }
                }
            }
        }
        for(auto i:vec)
        {
            ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends