//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll> vec;
        vec.push_back(1);
        if(n==1){
            return vec;
        }
        else if(n==2){
            vec.push_back(1);
            return vec;
        }
        else{
            
            for(int i=2;i<=n;i++){
                vec.insert(vec.begin(),1);
                int j=1;
                for(int j=1;j<vec.size()-1;j++){
                    vec[j]=(vec[j]%1000000007+vec[j+1]%1000000007)%1000000007;
                }
            }
            return vec;
        }
              
        
        
    }
};



//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends