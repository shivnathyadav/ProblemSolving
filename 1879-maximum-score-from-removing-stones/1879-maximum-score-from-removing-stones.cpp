class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        while((a!=0 && b!=0 && c==0)||(a!=0 && b==0 && c!=0)||(a==0 && b!=0 && c!=0)
        ||(a!=0 && b!=0 && c!=0)){
            if(a>=b && a>=c){
                if(b>=c){
                    ans +=1;
                    b-=1;
                    a-=1;
                }
                else{
                    ans +=1;
                    a-=1;
                    c-=1;
                }
            }
            else if(c>=b && c>=a){
                if(b>=a){
                    ans +=1;
                    c-=1;
                    b-=1;
                }
                else{
                    ans +=1;
                    c-=1;
                    a-=1;
                }
            }
            else{
                if(a>=c){
                    ans +=1;
                    b-=1;
                    a-=1;
                }
                else{
                    ans +=1;
                    b-=1;
                    c-=1;
                }
            }
        }
        return ans;
    }
};