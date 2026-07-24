class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n  =nums.size();
        int x= log2(n);
        long long ans=1;
        if(n<=2) return n;
        ans = ans << (x+1);
        return ans;
        
    }
};