class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long ans=1e15;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i==j) continue;
                long long ans1=0;
                long long ans2=0;
                for(int q=0;q<nums.size();q++){
                    int val = ((nums[q] % k) + k) % k;
                    if(q%2==0){
                        ans1+=min(k-abs(-val+i),abs(i-val));
                    }
                    else{
                        ans2+=min(k-abs(-val+j),abs(j-val));
                    }
                }
                ans=min(ans,ans1+ans2);
                
            }
        }
        return (int)ans;
    }
};