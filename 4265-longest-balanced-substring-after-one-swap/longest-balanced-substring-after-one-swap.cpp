class Solution {
public:
    int longestBalanced(string s) {
        int n =s.size();
        int one=0;
        int zero=0;
        int ans=0;
        int z=0;
        int o=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') o++;
            else{
                z++;
            }
        }
        unordered_map<int,vector<int>>um;
        um[0].push_back(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='1') one++;
            else{
                zero++;
            }
            if(um.find(one-zero)!=um.end()){
                ans=max(ans,i-um[one-zero][0]);
            }
            if (um.find(one-zero-2)!=um.end()){
                for(auto it :um[one-zero-2] ){
                    if((i-it-2)/2<z){
                        ans=max(ans,i-it);
                        break;
                    }
                }
            }
            if (um.find(one-zero+2)!=um.end()){
                for(auto it :um[one-zero+2] ){
                    if((i-it-2)/2<o){
                        ans=max(ans,i-it);
                        break;
                    }
                }
            }
            um[one-zero].push_back(i);
            
            
            
        }
        
        return ans;
    }
};