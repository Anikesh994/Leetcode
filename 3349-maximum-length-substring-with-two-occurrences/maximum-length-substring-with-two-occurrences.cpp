class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int high=0,low=0;
        unordered_map<char,int>mp;
        int ans=0;
        while(high<n){
            mp[s[high]]++;
            while(mp[s[high]]>2){
                mp[s[low]]--;
                low++;
            }
            high++;
            ans=max(ans,high-low);
        }
        return ans;
    }
};