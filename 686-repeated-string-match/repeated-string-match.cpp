class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n1=a.size();
        int n2=b.size();
        int ans=1;
        string q1=a;
        while(a.size()<=1e4){
            if(a.find(b)!=-1) return ans;
            else{
                ans++;
                a+=q1;

            }
        }
        return -1;
    }
};