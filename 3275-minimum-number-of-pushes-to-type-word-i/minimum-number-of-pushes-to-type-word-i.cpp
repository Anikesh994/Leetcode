class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char ,int>um;
        for(auto it : word){
            um[it]++;
        }
        int x= um.size();
        if(x<=8) return x;
        if(x<=16){
            return (8+ (x-8)*2);
        }
        if(x<=24){
            return (8+ 16 +(x-16)*3);
        }
        return (8+ 16 + 24+(x-24)*4);
        return 0;
    }
};