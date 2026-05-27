class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>temp;
        int n =word.size();
        for(int i=0;i<n;i++){
            if(word[i]>'Z' ){
                temp[26 + word[i]-'a']=i;
            }
            else if(temp.find(word[i]-'A')==temp.end()){
                temp[ word[i]-'A']=i;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(temp.find(i)!=temp.end() && temp.find(i+26)!=temp.end()){
                if(temp[i]>temp[i+26]){
                    ans++;
                }
            }
        }
        return ans;
    }
};