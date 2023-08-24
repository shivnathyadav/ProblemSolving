class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> vec;
        vec.push_back(1);
        if(n==0){
            return vec;
        }
        else if(n==1){
            vec.push_back(1);
            return vec;
        }
        else{
            
            for(int i=2;i<=n+1;i++){
                vec.insert(vec.begin(),1);
                int j=1;
                for(int j=1;j<vec.size()-1;j++){
                    vec[j]=vec[j]+vec[j+1];
                }
            }
            return vec;
        }
    }
};