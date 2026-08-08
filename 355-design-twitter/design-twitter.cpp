class Twitter {
    class cmp {
    public:
        bool operator()(const pair<int, int>& a,
                        const pair<int, int>& b) {
            return a.first > b.first;   // min-heap based on timestamp
        }
    };

public:
    int c = 0;

    // t1[follower][followee]
    unordered_map<int, unordered_map<int, int>> t1;

    // t2[user] = {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> t2;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        t2[userId].push_back({c, tweetId});
        c++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            cmp
        > pq;

        // Include user's own tweets
        for (auto tweet : t2[userId]) {
            if (pq.size() < 10) {
                pq.push(tweet);
            } else if (pq.top().first < tweet.first) {
                pq.pop();
                pq.push(tweet);
            }
        }

        // Include tweets of people userId follows
        for (auto it : t1[userId]) {
            int followeeId = it.first;

            for (auto tweet : t2[followeeId]) {
                if (pq.size() < 10) {
                    pq.push(tweet);
                } else if (pq.top().first < tweet.first) {
                    pq.pop();
                    pq.push(tweet);
                }
            }
        }

        // pq is oldest -> newest because it's a min-heap
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        t1[followerId][followeeId] = 1;
    }

    void unfollow(int followerId, int followeeId) {
        t1[followerId].erase(followeeId);
    }
};