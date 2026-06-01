class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>temp;
        int n =arr.size();
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>qw;
            for(int j=i;j<n;j++){
                qw[arr[j]]++;
                if(qw[arr[i]]==0) qw.erase(arr[i]);
                qw[temp[j]]--;
                if(qw[temp[i]]==0) qw.erase(temp[i]);
                if(qw.size()==0) ans++;
                i=j+1;
            }
        }
        return ans;
    }
};