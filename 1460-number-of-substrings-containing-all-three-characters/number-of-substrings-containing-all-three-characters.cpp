class Solution {
public:
    int numberOfSubstrings(string s) {
        long long ans=0;
        int low=0;
        int high=0;
        int c1=0,c2=0,c3 =0;
        for(int high=0;high<s.size();high++){
            if(s[high]=='a') c1++;
            else if(s[high]=='b') c2++;
            else if(s[high]=='c') c3++;
            while(c1>0 && c2>0 && c3>0){
                ans+=(s.size()-high);
                if(s[low]=='a') c1--;
                else if(s[low]=='b') c2--;
                else if(s[low]=='c') c3--;
                low++;
            }
        }
        return ans;
    }
};