class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>ma;
        int n =nums.size();
        int mi1 =INT_MAX;
        int ma1 = INT_MIN;
        for(int i=0;i<n;i++){
            ma1 = max(ma1,nums[i]);
            
            ma.push_back(ma1);

        }
        int ans = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mi1 = min(mi1,nums[i]);
            if(ma[i]-mi1 <= k){
                ans=min(ans,i);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};