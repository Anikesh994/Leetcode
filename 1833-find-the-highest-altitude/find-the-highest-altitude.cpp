class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        long long temp=0;
        long long ans=0;
        for(auto it : gain){
            temp+=it;
            ans =max(ans,temp);
        }
        return ans;
    }
};