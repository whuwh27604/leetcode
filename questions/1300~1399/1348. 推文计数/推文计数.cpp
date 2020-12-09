/* 推文计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你实现一个能够支持以下两种方法的推文计数类 TweetCounts：

1. recordTweet(string tweetName, int time)

记录推文发布情况：用户 tweetName 在 time（以 秒 为单位）时刻发布了一条推文。
2. getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)

返回从开始时间 startTime（以 秒 为单位）到结束时间 endTime（以 秒 为单位）内，每 分 minute，时 hour 或者 日 day （取决于 freq）内指定用户 tweetName 发布的推文总数。
freq 的值始终为 分 minute，时 hour 或者 日 day 之一，表示获取指定用户 tweetName 发布推文次数的时间间隔。
第一个时间间隔始终从 startTime 开始，因此时间间隔为 [startTime, startTime + delta*1>,  [startTime + delta*1, startTime + delta*2>, [startTime + delta*2, startTime + delta*3>, ... , [startTime + delta*i, min(startTime + delta*(i+1), endTime + 1)>，其中 i 和 delta（取决于 freq）都是非负整数。
 

示例：

输入：
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

输出：
[null,null,null,null,[2],[2,1],null,[4]]

解释：
TweetCounts tweetCounts = new TweetCounts();
tweetCounts.recordTweet("tweet3", 0);
tweetCounts.recordTweet("tweet3", 60);
tweetCounts.recordTweet("tweet3", 10);                             // "tweet3" 发布推文的时间分别是 0, 10 和 60 。
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // 返回 [2]。统计频率是每分钟（60 秒），因此只有一个有效时间间隔 [0,60> - > 2 条推文。
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // 返回 [2,1]。统计频率是每分钟（60 秒），因此有两个有效时间间隔 1) [0,60> - > 2 条推文，和 2) [60,61> - > 1 条推文。
tweetCounts.recordTweet("tweet3", 120);                            // "tweet3" 发布推文的时间分别是 0, 10, 60 和 120 。
tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // 返回 [4]。统计频率是每小时（3600 秒），因此只有一个有效时间间隔 [0,211> - > 4 条推文。
 

提示：

同时考虑 recordTweet 和 getTweetCountsPerFrequency，最多有 10000 次操作。
0 <= time, startTime, endTime <= 10^9
0 <= endTime - startTime <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tweet-counts-per-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class TweetCounts {
public:
    TweetCounts() {

    }

    void recordTweet(string tweetName, int time) {
        userTweets[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = (freq == "minute" ? 60 : (freq == "hour" ? 3600 : 3600 * 24));
        vector<int> tweetCountsPerFreq((endTime - startTime) / interval + 1, 0);

        auto itStart = userTweets[tweetName].lower_bound(startTime);
        auto itEnd = userTweets[tweetName].upper_bound(endTime);

        for (; itStart != itEnd; ++itStart) {
            ++tweetCountsPerFreq[(*itStart - startTime) / interval];
        }

        return tweetCountsPerFreq;
    }

private:
    unordered_map<string, set<int>> userTweets;
};

int main()
{
    CheckResult check;

    TweetCounts o1;
    o1.recordTweet("tweet3", 0);
    o1.recordTweet("tweet3", 60);
    o1.recordTweet("tweet3", 10);
    vector<int> actual = o1.getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
    vector<int> expected = { 2 };
    check.checkIntVector(expected, actual);
    actual = o1.getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);
    o1.recordTweet("tweet3", 120);
    actual = o1.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);
    expected = { 4 };
    check.checkIntVector(expected, actual);
    actual = o1.getTweetCountsPerFrequency("hour", "tweet1", 0, 210);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    TweetCounts o2;
    o2.recordTweet("tweet1", 1);
    o2.recordTweet("tweet2", 2);
    o2.recordTweet("tweet3", 3);
    o2.recordTweet("tweet2", 62);
    o2.recordTweet("tweet3", 63);
    o2.recordTweet("tweet3", 3603);
    o2.recordTweet("tweet3", 86403);
    actual = o2.getTweetCountsPerFrequency("minute", "tweet1", 0, 60);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);
    actual = o2.getTweetCountsPerFrequency("minute", "tweet2", 0, 60);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);
    actual = o2.getTweetCountsPerFrequency("minute", "tweet2", 0, 120);
    expected = { 1,1,0 };
    check.checkIntVector(expected, actual);
    actual = o2.getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);
    actual = o2.getTweetCountsPerFrequency("hour", "tweet3", 0, 7200);
    expected = { 2,1,0 };
    check.checkIntVector(expected, actual);
    actual = o2.getTweetCountsPerFrequency("day", "tweet3", 0, 172800);
    expected = { 3,1,0 };
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
