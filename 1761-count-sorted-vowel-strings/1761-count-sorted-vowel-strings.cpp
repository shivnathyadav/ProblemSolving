class Solution {
public:
    int countVowelStrings(int n) {
        vector<long long> sum(5,0);
        if(n==1){
            return 5;
        }
        else{
            int ans = 15;
            sum[0]=5,sum[1]=4,sum[2]=3,sum[3]=2,sum[4]=1;
            for(int i = 2;i <n; i++){
                int cum = 0;
                int maxi = ans;
                for(int i = 0; i < 5; i++){
                    if(i==0){
                        cum+=sum[i];
                        sum[i]=maxi;
                    }
                    else{
                        int num = maxi-cum;
                        ans += num;
                        cum += sum[i];
                        sum[i]=num;
                    }
                    cout<<sum[i]<<" ";

                }
                cout<<endl;

            }
        return ans;
        }
        
    }
};