/* 设计推特.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

postTweet(userId, tweetId): 创建一条新的推文
getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
follow(followerId, followeeId): 关注一个用户
unfollow(followerId, followeeId): 取消关注一个用户
示例:

Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-twitter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Tweet {
public:
    Tweet() {
        maxTweetsNumber = 10;
    }

    void postTweet(int userId, int tweetId, int globeId) {
        auto iter = userTweetsId.find(userId);
        if (iter == userTweetsId.end()) {
            list<pair<int, int>> tweets;
            tweets.push_front({ tweetId, globeId });
            userTweetsId[userId] = tweets;
        }
        else {
            list<pair<int, int>>& tweets = iter->second;
            tweets.push_front({ tweetId, globeId });
            if (tweets.size() > maxTweetsNumber) {
                tweets.pop_back();
            }
        }
    }

    int getTweets(int userId, list<pair<int, int>>** tweets) {
        auto iter = userTweetsId.find(userId);
        if (iter != userTweetsId.end()) {
            *tweets =  &(iter->second);
            return 0;
        }

        return -1;
    }

private:
    unordered_map<int, list<pair<int, int>>> userTweetsId;
    unsigned int maxTweetsNumber;
};

class User {
public:
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        auto iter = followedUsers.find(followerId);
        if (iter == followedUsers.end()) {
            unordered_set<int> users;
            users.insert(followeeId);
            followedUsers[followerId] = users;
        }
        else {
            iter->second.insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        auto iter = followedUsers.find(followerId);
        if (iter != followedUsers.end()) {
            iter->second.erase(followeeId);
        }
    }

    int getFollowedUsers(int followerId, unordered_set<int>** followed) {
        auto iter = followedUsers.find(followerId);
        if (iter != followedUsers.end()) {
            *followed = &(iter->second);
            return 0;
        }

        return -1;
    }

private:
    unordered_map<int, unordered_set<int>> followedUsers;
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        globeTweetId = 0;
        maxTweetsNumber = 10;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet.postTweet(userId, tweetId, globeTweetId++);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        map<int, int> globeLocalTweetId;
        list<pair<int, int>>* tweets = NULL;
        if (tweet.getTweets(userId, &tweets) == 0) {
            for (auto iter = (*tweets).begin(); iter != (*tweets).end(); ++iter) {
                globeLocalTweetId[iter->second] = iter->first;
            }
        }

        unordered_set<int>* followedUsers = NULL;
        if (user.getFollowedUsers(userId, &followedUsers) == 0) {
            for (auto itUser = (*followedUsers).begin(); itUser != (*followedUsers).end(); ++itUser) {
                list<pair<int, int>>* followedTweets = NULL;
                if (tweet.getTweets(*itUser, &followedTweets) == 0) {
                    for (auto itTweet = (*followedTweets).begin(); itTweet != (*followedTweets).end(); ++itTweet) {
                        globeLocalTweetId[itTweet->second] = itTweet->first;
                        if (globeLocalTweetId.size() > maxTweetsNumber) {
                            globeLocalTweetId.erase(globeLocalTweetId.begin());
                        }
                    }
                }
            }
        }

        vector<int> news;
        for (auto rit = globeLocalTweetId.rbegin(); rit != globeLocalTweetId.rend(); ++rit) {
            news.push_back(rit->second);
        }

        return news;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user.follow(followerId, followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        user.unfollow(followerId, followeeId);
    }

    int globeTweetId;
    unsigned int maxTweetsNumber;
    Tweet tweet;
    User user;
};

int main()
{
    CheckResult check;

    Twitter o1;
    o1.postTweet(1, 5);
    vector<int> actual = o1.getNewsFeed(1);
    vector<int> expected = { 5 };
    check.checkIntVector(expected, actual);
    o1.follow(1, 2);
    o1.postTweet(2, 6);
    actual = o1.getNewsFeed(1);
    expected = { 6,5 };
    check.checkIntVector(expected, actual);
    o1.unfollow(1, 2);
    actual = o1.getNewsFeed(1);
    expected = { 5 };
    check.checkIntVector(expected, actual);
    actual = o1.getNewsFeed(2);
    expected = { 6 };
    check.checkIntVector(expected, actual);
    actual = o1.getNewsFeed(3);
    expected = {  };
    check.checkIntVector(expected, actual);

    Twitter o2;
    o2.postTweet(1, 10);
    o2.postTweet(1, 9);
    o2.postTweet(1, 8);
    o2.postTweet(1, 7);
    o2.postTweet(1, 6);
    o2.postTweet(1, 5);
    o2.postTweet(1, 4);
    o2.postTweet(1, 3);
    o2.postTweet(1, 2);
    o2.postTweet(1, 1);
    o2.postTweet(1, 0);
    actual = o2.getNewsFeed(1);
    expected = { 0,1,2,3,4,5,6,7,8,9 };
    check.checkIntVector(expected, actual);

    Twitter o3;
    o3.unfollow(1, 2);
    actual = o3.getNewsFeed(1);
    expected = {  };
    check.checkIntVector(expected, actual);
    o3.follow(1, 2);
    o3.follow(1, 3);
    o3.follow(1, 4);
    o3.postTweet(1, 100);
    o3.postTweet(2, 99);
    o3.postTweet(3, 101);
    o3.postTweet(4, 98);
    o3.postTweet(1, 102);
    o3.postTweet(2, 97);
    o3.postTweet(3, 103);
    o3.postTweet(4, 96);
    o3.postTweet(1, 104);
    o3.postTweet(2, 95);
    o3.postTweet(3, 105);
    o3.postTweet(4, 94);
    actual = o3.getNewsFeed(1);
    expected = { 94,105,95,104,96,103,97,102,98,101 };
    check.checkIntVector(expected, actual);
    actual = o3.getNewsFeed(2);
    expected = { 95,97,99 };
    check.checkIntVector(expected, actual);
    o3.follow(1, 2);
    o3.unfollow(1, 2);
    actual = o3.getNewsFeed(1);
    expected = { 94,105,104,96,103,102,98,101,100 };
    check.checkIntVector(expected, actual);
    o3.unfollow(1, 3);
    actual = o3.getNewsFeed(1);
    expected = { 94,104,96,102,98,100 };
    check.checkIntVector(expected, actual);
    o3.unfollow(1, 4);
    o3.unfollow(1, 4);
    actual = o3.getNewsFeed(1);
    expected = { 104,102,100 };
    check.checkIntVector(expected, actual);
    o3.unfollow(1, 1);
    actual = o3.getNewsFeed(1);
    expected = { 104,102,100 };
    check.checkIntVector(expected, actual);

    Twitter o4;
    o4.follow(1, 1);
    o4.postTweet(1, 5);
    actual = o4.getNewsFeed(1);
    expected = { 5 };
    check.checkIntVector(expected, actual);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
