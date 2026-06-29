class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n1=a.size();
        int n2=b.size();
        int a1=n2/n1;
        char first =b[0];
        int q=-1;
        vector<int>temp;
        for(int i=0;i<n1;i++){
            if(a[i]==first){
                temp.push_back(i);
            }
        }
        if(temp.size()==0) return -1;
        int ans=1;
        for(int i=0;i<temp.size();i++){
            ans=1;
            int j=temp[i];
            int q=0;
            while(q<n2 && b[q]==a[j]){
                q++;
                j++;
                if(j==n1){
                    
                    j=0;
                    if(q<n2) ans++;
                }
                
            }
            if(q==n2) return ans;
        }
        return -1;

    }
};