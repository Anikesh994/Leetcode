class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>um;
        um['b']=um['a']=um['l']=um['o']=um['n']=0;
        for(auto it : text){
            if(it=='b' || it=='a' || it=='o' || it=='l' || it=='n'){
                um[it]++;
            }
        }
        int ans=INT_MAX;
        for(auto it : um){
            if(it.first =='l' || it.first =='o'){
                ans=min(ans,it.second/2);
            }
            else{
                ans=min(ans,it.second);
            }
        }

        return ans;
    }
};