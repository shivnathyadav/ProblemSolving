class Solution {
public:
    int twoEggDrop(int n) {
        int num = sqrt(n*8+1);
        if(num*num==(n*8+1)){
            return num/2;
        }
        cout<<num<<endl;
        num=(num-1)/2;
        num=num+1;
        return num;
    }
};