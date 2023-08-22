class Solution {
public:
    vector<int> checkDivisor(int n){
        vector<int> vec;
        vec.push_back(1);
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0){
                vec.push_back(i);
                if(i!=(n/i)){
                    vec.push_back(n/i);
                }
            }
        }
        return vec;
    }
    bool game(int n,int ch){
        if(n <= 1 && ch == 0){
            return false;
        }
        else if(n <= 1 && ch == 1){
            return true;
        } 
        else if(n==2 && ch == 0){
            return true;
        }
        else if(n==2 && ch == 1){
            return false;
        } 
        vector<int> divisor = checkDivisor(n);
        for(int  i = 0; i < divisor.size(); i++){
            if(ch == 0){
                if(game(n-divisor[i],1)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(game(n-divisor[i],0)){
                    return true;
                }
                else{
                    return false;
                }
            }    
        }
        return false;
    }
    bool divisorGame(int n) {
        return game(n,0);
    }
};