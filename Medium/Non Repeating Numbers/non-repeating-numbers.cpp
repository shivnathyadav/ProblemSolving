//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xo = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            xo = xo ^ nums[i];
        }
        //first set bit position in xor of all number
        int pos = 0;
        while(xo){
            int rem = xo % 2;
            if(rem & 1){
                break;
            }
            xo = xo/2;
            pos += 1;
        }
        vector<int> vec(2,0);
        for(auto it : nums){
            if(it >> pos & 1){
                vec[0]^=it;
            }
            else{
                vec[1] ^=it;
            }
        }
        sort(vec.begin(),vec.end());
        return vec;
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends