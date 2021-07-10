class Twitter {
    private:
    unordered_map<int,unordered_set<int>>f;
    unordered_map<int,vector<pair<int,int>>>t;
    int time;
public:
    /** Initialize your data structure here. */
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userID, int tweetID) {
        t[userID].push_back({time++,tweetID});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userID) {
        priority_queue<pair<int,int>>p;
        for (auto i: t[userID]){
            p.push(i);
        }
        vector<int>ans;
        for (auto i:f[userID]){
            for (auto j:t[i]){
                p.push(j);
            }
        }
        while (ans.size()<10 && !p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerID, int followeeID) {
        f[followerID].insert(followeeID);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerID, int followeeID) {
        f[followerID].erase(followeeID);
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
