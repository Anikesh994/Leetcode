class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int>temp(n,0);
        int q=INT_MIN;
        for(int i=n-1;i>=0;i--){
            q = max(q,nums[i]);
            temp[i] =q;
        }
        int ans=0;
        for(int i=0;i<n-k;i++){
            ans=max(ans , (nums[i]+temp[i+k]));
        }
        return ans;

    }
};