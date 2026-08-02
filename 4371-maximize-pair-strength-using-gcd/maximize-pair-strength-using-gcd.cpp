class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0 ;j<n;j++){
                if(i!=j){
                    long long x = ((1LL *nums[i]*nums[j])/(1LL *gcd(nums[i],nums[j])*gcd(nums[i],nums[j])));
                    ans = max(ans,x);
                }
            }
        }
        return ans;
    }
};