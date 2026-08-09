class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>temp(26,0);
        for(auto it : s){
            temp[it-'a']++;
        }
        string ans="";
        string ans1="";
        for(int i=0;i<26;i++){
            int x=(temp[i])/2;
            for(int j=0;j<x;j++){
                ans+=('a'+i);
            }
            if(temp[i]%2!=0) ans1+=('a'+i);
        }
        string t1=ans;
        reverse(t1.begin(),t1.end());
        return ans+ans1+t1;
    }
};