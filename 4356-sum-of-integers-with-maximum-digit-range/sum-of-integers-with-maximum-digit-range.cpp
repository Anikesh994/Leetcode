class Solution {

int solve(int n){
    int ma1 =0  ;
    int mi1 = 9;
    while(n>0){
        ma1=max(ma1 , n%10);
        mi1=min(mi1 , n%10);
        n/=10;
    }
    return (ma1-mi1);
}

public:
    int maxDigitRange(vector<int>& nums) {
        long long ans=0;
        int l=-1;
        for(int i=0;i<nums.size();i++){
            int x= solve(nums[i]);
            if(x>l){
                l=x;
                ans=nums[i];
            }
            else if(x==l){
                ans+=nums[i];
            }
        }
        return ans;
    }
};