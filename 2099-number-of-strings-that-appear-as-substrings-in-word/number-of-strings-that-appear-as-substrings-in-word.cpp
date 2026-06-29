class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n =word.size();
        unordered_map<string ,int>um;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=i;j<n;j++){
                s+=word[j];
                um[s]++;
            }
            
        }
        int ans=0;
        for(int i=0;i<patterns.size();i++){
            if(um.find(patterns[i])!=um.end()) ans++;
        }
        return ans;
    }
};