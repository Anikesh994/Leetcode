class Solution {
public:
    int minOperations(string s1, string s2) {
        // string11 = "1220";
        // string10 = "2301";
        int n =s1.size();
        if(n==1){
            if(s1[0]=='0'){
                if(s1[0]!=s2[0]) return 1;
                else return 0;
            }
            else{
                if(s1[0]==s2[0]) return 0;
                return -1;
            }
        }
        if(s1.size()!=s2.size()) return -1;
        int ans=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='0' && s1[i]!=s2[i]){
                ans++;
                s1[i]=s2[i];
            }
            else if(s1[i]=='1' && s1[i]!=s2[i] && i != s1.size()-1){
                s1[i]=s2[i];
                if(s1[i+1]=='1'){
                    if(s2[i+1]=='1'){
                        ans+=2;
                    }
                    else{
                        s1[i+1]='0';
                        ans++;
                    }
                }
                else{
                    if(s2[i+1]=='1'){
                        ans+=3;
                        s1[i+1]='1';
                    }
                    else{
                        ans+=2;
                        s1[i+1]='0';
                    }
                }
            }
        }
        if(s1[n-1]!=s2[n-1]){
            ans+=2;
            s1[n-1]=s2[n-1];
        }
        if(s1==s2) return ans;
        return -1;


    }
};