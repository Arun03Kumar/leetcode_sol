class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follow_map;
    int tweet_counter;

    Twitter() {
        tweet_counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++tweet_counter, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto &x: tweets[userId]) {
            pq.push(x);

            if(pq.size() > 10) pq.pop();
        }

        for(int x: follow_map[userId]) {
            for(auto &y: tweets[x]) {
                pq.push(y);

                if(pq.size() > 10) pq.pop();
            } 
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
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