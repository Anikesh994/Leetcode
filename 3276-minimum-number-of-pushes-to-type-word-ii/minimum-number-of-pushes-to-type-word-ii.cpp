class Solution {
public:
    int minimumPushes(string word) {
        vector<int>temp(26,0);
        for(auto it : word){
            temp[it-'a']++;
        }
        int c=0;
        int ans=0;
        sort(temp.begin(),temp.end() , greater<int>());
        for(auto it : temp){
            if(it <=0) continue;
            if(c<8){
                ans+=it;
            }
            else if(c<16){
                ans+=2*it;
            }
            else if(c<24){
                ans+=3*it;
            }
            else{
                ans+=4*it;
            }
            c++;
        }
        return ans;
    }
};