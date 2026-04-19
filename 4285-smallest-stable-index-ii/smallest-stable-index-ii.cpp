class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>mi;
        vector<int>ma;
        int n =nums.size();
        int k1 = n-1;
        int mi1 =INT_MAX;
        int ma1 = INT_MIN;
        for(int i=0;i<n;i++){
            ma1 = max(ma1,nums[i]);
            mi1 = min(mi1,nums[k1-i]);
            ma.push_back(ma1);
            mi.push_back(mi1);

        }
        reverse(mi.begin(),mi.end());
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(ma[i]-mi[i] <= k){
                ans=min(ans,i);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};