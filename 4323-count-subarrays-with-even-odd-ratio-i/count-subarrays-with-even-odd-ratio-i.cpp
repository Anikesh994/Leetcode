class Solution {
public:
    
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n =nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int x1=0;
            int x2=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) x2++;
                else{
                    x1++;
                }
                if(x1>0 && (x2*b <= a*x1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};