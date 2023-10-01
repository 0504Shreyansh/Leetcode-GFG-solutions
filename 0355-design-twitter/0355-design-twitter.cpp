class Twitter {
public:
    int timer = 0;
    map<int, set<int>> f;
    map<int, vector<pair<int, int>>> tweet;
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (auto &it : tweet[userId])
            pq.push(it);
        for (auto &it : f[userId]) {
            for (auto &j : tweet[it])
                pq.push(j);
        }
        while (pq.size() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */