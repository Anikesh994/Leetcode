class Solution {

vector<pair<int,bool>> solve(string &s , string &t){
        int l1=0;
        int l2 =0;
        int c=0;
        int n1 =s.size();
        int n2 = t.size();
        vector<pair<int,bool>>post(t.size());
        while(l2 < n2){
            if(l1 ==n1){
                post[l2]={n1,true};
                l2++;
                continue;
            }
            if(l2==0 && s[l1]==t[l2]){
                c++;
                post[0] ={c,false};
                l1++;
                l2++;
            }
            else if(s[l1]==t[l2]){
                c++;
                
                post[l2] = {c,false};
                l1++;
                l2++;
            }
            else{
                post[l2]={c,true};
                l2++;
            }

        }
        return post;
}

vector<pair<int,bool>> solve1(string &s , string &t){
        
        int c=0;
        int n1 =s.size();
        int n2 = t.size();
        int l1=n1-1;
        int l2 =n2-1;
        vector<pair<int,bool>>post(t.size());
        while(l2 >=0){
            if(l1 <0){
                post[l2]={n1,true};
                l2--;
                continue;
            }
            if(l2==n2-1 && s[l1]==t[l2]){
                c++;
                post[0] ={c,false};
                l1--;
                l2--;
            }
            else if(s[l1]==t[l2]){
                c++;
                
                post[l2] = {c,false};
                l1--;
                l2--;
            }
            else{
                post[l2]={c,true};
                l2--;
            }

        }
        return post;
}


public:
    bool canMakeSubsequence(string s, string t) {
        
        int n1 =s.size();
        int n2 = t.size();
        if(n1>n2) return false;
        auto it1 =solve(s,t);
        auto it2 =solve1(s,t);
        for(int i=0;i<n2;i++){
            if(it1[i].first+it2[i].first > n1) return true;
            if(it1[i].first==n1 || it2[i].first==n1) return true;
            if(it1[i].first+it2[i].first == n1 && (it1[i].second || it2[i].second)) return true;
            if(it1[i].first+it2[i].first +1 == n1 && (it1[i].second && it2[i].second)) return true;
        }
        return false;
    }
};