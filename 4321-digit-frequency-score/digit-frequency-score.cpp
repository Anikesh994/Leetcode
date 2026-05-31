class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>temp;
        while(n>0){
            temp[n%10]++;
            n=n/10;
        }
        long long ans=0;
        for(auto it : temp){
            ans+=(it.first*it.second);
        }
        return ans;
    }
};