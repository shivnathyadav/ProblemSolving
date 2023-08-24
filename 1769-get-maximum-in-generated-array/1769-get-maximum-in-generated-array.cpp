class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1,0);
        int maxi = 0;
        if(n>=1){
            nums[1] = 1;
            maxi = 1;
        }
                
        for(int i = 2;i <= n; i++){
            if(i%2==0){
                nums[i]=nums[i/2];
            }
            else{
                nums[i]=nums[i/2]+nums[(i/2)+1];
            }
            maxi = max(maxi,nums[i]);
            cout<<i<<" "<<nums[i]<<endl;
        }
        return maxi;
    }
};