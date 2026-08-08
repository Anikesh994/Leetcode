
class Twitter {

class cmp{
public:
    bool operator()(const pair<int,int>& a , const pair<int,int>& b){
        return a.first>b.first;
    }
      
};

public:
    int c=0;
    unordered_map<int,unordered_map<int,int>>t1;
    unordered_map<int,vector<pair<int,int>>>t2;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        t2[userId].push_back({c,tweetId});
        c++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

        // own tweets
        int x = 0;
        for(auto it1 = t2[userId].rbegin();
            it1 != t2[userId].rend() && x < 10;
            it1++, x++){

            if(pq.size()<10){
                pq.push(*it1);
            }
            else{
                auto it3 = pq.top();
                if(it3.first < it1->first){
                    pq.pop();
                    pq.push(*it1);
                }
            }
        }

        // friends' tweets
        for(auto it : t1[userId]){
            
            x = 0;

            for(auto it1 = t2[it.first].rbegin(); 
                it1 != t2[it.first].rend() && x < 10; 
                it1++, x++){

                if(pq.size()<10){
                    pq.push(*it1);
                }
                else{
                    auto it3 = pq.top();
                    if(it3.first < it1->first){
                        pq.pop();
                        pq.push(*it1);
                    }
                }
            }
        }

        vector<int>temp;

        while(!pq.empty()){
            temp.push_back(pq.top().second);
            pq.pop();
        }

        reverse(temp.begin(),temp.end());

        return temp;
    }
    
    void follow(int followerId, int followeeId) {
        t1[followerId][followeeId]++;
    }
    
    void unfollow(int followerId, int followeeId) {
        t1[followerId].erase(followeeId);
    }
};

