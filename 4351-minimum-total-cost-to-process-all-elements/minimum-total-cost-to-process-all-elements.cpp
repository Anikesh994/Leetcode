class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long c=0;
        int mod =1e9+7;
        int temp =k;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=temp){
                temp-=nums[i];
            }
            else{
                int x = (nums[i]-temp);
                int y =(x/k);
                if(x%k!=0) y++;
                c+=y;
                temp+=(y*k);
                temp-=nums[i];
            }
        }
        if(c%2==0){
            return ((1LL * (c/2) % mod) * ((c + 1) % mod)) % mod;
        }
        return ((1LL * c % mod) * ((c + 1)/2 % mod)) % mod;
        
    }
};