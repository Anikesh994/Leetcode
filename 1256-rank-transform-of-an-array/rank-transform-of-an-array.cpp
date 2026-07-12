class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int>um;
        int j=0;
        for(int i=0;i<n;i++){
            if(um.find(temp[i])==um.end()){
                um[temp[i]]=j;
                j++;
            }
        }
        j=0;
        for(auto it : arr){
            temp[j] =um[it]+1;
            j++;
        }
        return temp;
    }
};