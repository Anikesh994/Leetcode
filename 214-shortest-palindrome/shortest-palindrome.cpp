class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int>presum(2*n+1,0);
        string s2=s;
        reverse(s2.begin(),s2.end());
        string s1 = s + '#' + s2;
        int i=1;
        int length=0;
        int ans=0;
        while(i<s1.size()){
            if(s1[i]==s1[length]){
                presum[i]=length+1;
                length++;
                ans=max(ans,length);
                i++;
            }
            else{
                if(length!=0){
                    length =presum[length-1];
                }
                else{
                    presum[i]=0;
                    i++;
                }
            }
        }
        for(int i=0;i<(s.size()-length);i++){
            s2.push_back(s[length+i]);
        }
        reverse(s2.begin(),s2.end());
        return s2;

    }
};