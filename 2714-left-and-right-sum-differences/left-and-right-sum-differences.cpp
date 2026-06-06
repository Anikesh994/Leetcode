class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n =nums.size();
        vector<int>pre(n+1,0);
        int sum=0;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
            sum+=nums[i];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(abs(sum-2*pre[i]-nums[i]));
        }
        return ans;
    }
};