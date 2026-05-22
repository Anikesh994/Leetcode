class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int n =nums.size();
        int high =n-1;
        int ans;
        while(low<high){
            int mid =(low+high)/2;
            ans=mid;
            if(nums[mid]<nums[high]){
                high=mid;
            }
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high--;
            }
        }
        return nums[low];
    }
};