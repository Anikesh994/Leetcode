class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n,pivot);
        int low =0;
        int high =n-1;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[low]=nums[i];
                low++;
            }
            else if(nums[i]>pivot){
                ans[high]=nums[i];
                high--;
            }
        }
        reverse(ans.begin()+high+1,ans.end());
        return ans;
    }
};