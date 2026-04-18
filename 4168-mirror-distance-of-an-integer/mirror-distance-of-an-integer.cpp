class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        int k=s.size();
        
        long long ans=0;
        long long n1=1;
        int i=0;
        while(i<k){
            ans +=n1*(s[i]-'0');
            n1=n1*10;
            i++;
        }
        return abs(n-ans);
    }
};