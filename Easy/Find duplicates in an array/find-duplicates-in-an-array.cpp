//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> vec(100001,0);
        int maxi = 0;
        for(int i = 0;i < n; i++){
            maxi = max(maxi , arr[i]);
        }
        for(int i = 0; i < n; i++){
            vec[arr[i]]++;    
        }
        vector<int> ans;
        for(int it=0;it<=maxi;it++){
            if(vec[it] > 1){
                ans.push_back(it);
            }
        }
        if(ans.size()==0){
            ans.push_back(-1);
            return ans;
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends