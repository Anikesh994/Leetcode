class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int low1=0;
        int low2=0;
        int n1= nums1.size();
        int n2= nums2.size();
        while(low1<n1 && low2<n2){
            if(nums1[low1]==nums2[low2]){
                return nums1[low1];
            }
            else if(nums1[low1]<nums2[low2]){
                low1++;
            }
            else{
                low2++;
            }
        }
        return -1;
    }
};