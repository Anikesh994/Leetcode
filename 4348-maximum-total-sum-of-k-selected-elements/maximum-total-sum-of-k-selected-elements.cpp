class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end() , greater<int>());
        int n =nums.size();
        long long ans=0;
        for(int i=0;i<k;i++){
            if(mul>0){
                ans+=(1LL *mul*nums[i]);
                mul--;
            }
            else{
                ans+=(nums[i]);
            }
        }
        return ans;
    }
};