class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n+1,0);
        if(n==0){
            return vec;
        }
        vec[1]=1;
        if(n==1){
            return vec;
        }
        for(int i = 2; i <= n; i++){
          int count = 0;
          int num = i;
          while(num>0){
                if(num%2==1){
                   count += 1;   
              }
                 num = num/2;
          }
          vec[i]=count;
        }
        return vec;
    }
};