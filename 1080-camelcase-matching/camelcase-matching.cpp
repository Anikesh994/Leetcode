class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int temp=0;
            int q=0;
            bool t=true;
            for(int j=0;j<queries[i].size();j++){
                if(q<pattern.size() && queries[i][j]==pattern[q]){
                    q++;
                }
                else if((queries[i][j]-'A'>=0 && queries[i][j]-'A'<26)){
                    t=false;
                    break;
                }
            }
            if(q==pattern.size() && t) ans.push_back(true);
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};