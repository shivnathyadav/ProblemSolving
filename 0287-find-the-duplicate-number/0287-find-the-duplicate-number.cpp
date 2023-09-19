class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       // take two pointer 
       int doublespeed=nums[0];
       int onexspeed=nums[0];
        do{
            onexspeed=nums[onexspeed];
            doublespeed=nums[nums[doublespeed]];
        }while(doublespeed!=onexspeed);
        // before getting duplicate element where onex and double pointer point same element
    //    cout<<onexspeed<<" "<<doublespeed<<endl;
        doublespeed=nums[0];
    //    cout<<onexspeed<<" "<<doublespeed<<endl;
        while(doublespeed!=onexspeed){
            onexspeed=nums[onexspeed];
            doublespeed=nums[doublespeed];
        }
        return onexspeed;
    }
};
