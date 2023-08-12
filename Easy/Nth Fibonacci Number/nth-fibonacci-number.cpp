//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Initial Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        long long int a[n+1];
        a[0]=0,a[1]=1;
        long long int ans;
        for(long long int i=2;i<=n;i++ ){
            a[i]=(a[i-1]+a[i-2])%1000000007;
        }
        ans=a[n]%1000000007;
     //   delete[] a;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends