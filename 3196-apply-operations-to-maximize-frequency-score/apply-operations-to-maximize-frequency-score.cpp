class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        int low=0;
        int high=0;
        int ans=1;
        while(high<n){
            int mid = (high+low)/2;
            int x1= high-mid;
            int x2 =mid-low;
            if(((1LL*x2*nums[mid]-(pre[mid]-pre[low]))+((pre[high+1]-pre[mid+1])-1LL*x1*nums[mid])) <=k){
                ans =max(ans,high-low+1);
                high++;
            }
            else{
                
                low++;
            }
           
            
        }
        return ans;
        
    }
};