class Solution {
public:
    string longestPrefix(string s) {
        int n =s.size();
        vector<int>presum(n,0);
        int i=1;
        int length=0;
        int ans=0;
        while(i<s.size()){
            if(s[i]==s[length]){
                presum[i]=length+1;
                length++;
                
                i++;
            }
            else{
                if(length!=0){
                    length =presum[length-1];
                }
                else{
                    presum[i]=0;
                    i++;
                }
            }
        }
        ans =presum[n-1];
        string temp="";
        for(int i=n-ans;i<n;i++){
            temp+=s[i];
        }
        
        return temp;
 
    }
};