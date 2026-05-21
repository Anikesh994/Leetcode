class Solution {

void set1(int n , unordered_map<string,int>&temp){
    string g=to_string(n);
    string s="";
    for(auto it : g){
        s+=it;
        if(temp.find(s)==temp.end()) temp[s]++;

    }
}
int chek(int n , unordered_map<string,int>&temp){
    string g=to_string(n);
    string s="";
    int t=0;
    for(auto it : g){
        s+=it;
        if(temp.find(s)!=temp.end()){
            t=s.size();
        }

    }
    return t;
}




public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>temp;
        int n =arr1.size();
        for(int i=0;i<n;i++){
            if(temp.find(to_string(arr1[i]))==temp.end()){
                set1(arr1[i],temp);
            }
        }
        int n1=arr2.size();
        int ans=0;
        for(int i=0;i<n1;i++){
            ans = max(ans,chek(arr2[i],temp));
        }
        return ans;
    }
};