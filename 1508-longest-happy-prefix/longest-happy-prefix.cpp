class Solution {
public:
    string longestPrefix(string s) {
        int n =s.size();
        long long forward =0;
        long long backward =0;
        long long base =27;
        long long mod =1e9+7;
        long long pow=1;
        int j=0;
        for(int i=0;i<n-1;i++){
            int val1 = (s[i]-'a');
            int val2 = (s[n-i-1]-'a');
            forward =(1LL*forward*base + val1)%mod;
            backward = (backward + (1LL*pow * val2)%mod)%mod;
            pow =(pow*base)%mod;
            if( forward==backward){
                j=i+1;
            }

        }
        return s.substr(0,j);
    }
};