class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;;
        int high=nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return min(nums[0],nums[1]);
        }
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]<=nums[high]){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return nums[low];
    }
};