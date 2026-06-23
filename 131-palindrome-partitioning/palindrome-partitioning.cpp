class Solution {

void solve(int i ,string s ,vector<vector<bool>>&ispal,vector<vector<string>>&ans,vector<string>&temp ){
    if(i==s.size()){
        ans.push_back(temp);
        return ;
    }

    for(int j=i;j<s.size();j++){
        if(ispal[i][j]){
            temp.push_back(s.substr(i ,j-i+1));
            solve(j+1 ,s,ispal ,ans,temp);
            temp.pop_back();
        }
    }
}



public:
    vector<vector<string>> partition(string s) {
        int n =s.size();
        vector<vector<bool>>ispal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i ;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1) ispal[i][j]=true;
                    else{
                    ispal[i][j] =ispal[i+1][j-1];
                    } 
                }
                
            }
        }
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,ispal,ans,temp);
        return ans;
    }
};