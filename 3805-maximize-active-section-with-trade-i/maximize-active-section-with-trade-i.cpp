class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n =s.size();
        int high=0;
        vector<int>temp;
        int c=0;
        for(auto it : s){
            if(it=='1') c++;
        }
        while(high <n){
            if(s[high]=='1') high++;
            else{
                int x=high;
                int q=0;
                while(high <n && s[high]=='0') {
                    high++;
                    q++;
                }
                temp.push_back(q);
            }
        }
        if(temp.size()<=1 ) return c;
        int ans=0;
        for(int i=0;i<temp.size()-1;i++){
            ans=max(temp[i] + temp[i+1] ,ans);
        }
        return ans+c;

    }
};