class Solution {

int fn(int low,int high ,vector<int>& nums ,vector<long long>& p,int k){
    int l =low;
    int h =high;
    while(low<=high){
        int mid =(low +high)/2;
        if((1LL*(h-mid+1)*nums[h])-(p[h+1]-p[mid]) <=k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return h-low+1;
}


public:
    int maxFrequency(vector<int>& nums, int k) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>pre(n+1,0);
        for(int i =1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        int ans=1;
        for(int i=n-1;i>=0;i--){
            ans=max(ans,fn(0,i,nums,pre,k));
            if(i<=ans) break;
        }
        
        return ans;                                   
    }
};