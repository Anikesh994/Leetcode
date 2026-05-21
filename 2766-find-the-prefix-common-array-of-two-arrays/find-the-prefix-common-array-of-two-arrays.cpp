class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>t1;
        unordered_map<int,int>t2;
        int n =A.size();
        int ans=0;
        vector<int>response;
        for(int i=0;i<n;i++){
            if(A[i]==B[i]){
                ans++;
                response.push_back(ans);
            }
            else{
                if(t1.find(B[i])!=t1.end()){
                    ans++;
                }
                else{
                    t2[B[i]]++;
                }
                if(t2.find(A[i])!=t2.end()){
                    ans++;
                }
                else{
                    t1[A[i]]++;
                }
                response.push_back(ans);
            }
        }
        return response;
    }
};