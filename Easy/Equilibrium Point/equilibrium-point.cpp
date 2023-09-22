//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long int k=0,j=-1,sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        //sum-=a[n-1];
        for(int i=n-1;i>=0;i--){
            k+=a[i];
            sum-=a[i];
     //       cout<<sum<<" "<<k<<endl;
            if(sum-a[i-1]==k){
                j=i;
            }
        }
        if(n==1)
         return 1;
        else if(n==2)
         return -1;
        else if(n>2 && j!=-1)
         return j;
        else
          return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends