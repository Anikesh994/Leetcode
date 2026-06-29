class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n =word.size();
        unordered_map<string,int>um;
        for(int i=0;i<patterns.size();i++){
            um[patterns[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=i;j<n;j++){
                s+=word[j];
                if(um.find(s)!=um.end()){
                    ans+=um[s]; 
                    um.erase(s);
                    //if(um[s]==0) um.erase(s);
                } 
            }
            
        }
        
        
        return ans;
    }
};