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
            int k = log2(i);
            if(pow(2,k)==i){
                vec[i] = 1 ;
                cout<<i<<" a "<<vec[i]<<endl;
            }
            else{  
          //          cout<<pow(2,(int)log2(i))<<" c "<<(i-pow(2,(int)log2(i)))<<endl;
                    vec[i] += vec[pow(2,(int)log2(i))]+vec[i-pow(2,(int)log2(i))];
                    
             cout<<i<<" b "<<vec[i]<<endl;    
            }

        }
        return vec;
    }
};