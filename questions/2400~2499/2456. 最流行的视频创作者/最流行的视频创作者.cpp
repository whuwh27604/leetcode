/* 最流行的视频创作者.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串数组 creators 和 ids ，和一个整数数组 views ，所有数组的长度都是 n 。平台上第 i 个视频者是 creator[i] ，视频分配的 id 是 ids[i] ，且播放量为 views[i] 。

视频创作者的 流行度 是该创作者的 所有 视频的播放量的 总和 。请找出流行度 最高 创作者以及该创作者播放量 最大 的视频的 id 。

如果存在多个创作者流行度都最高，则需要找出所有符合条件的创作者。
如果某个创作者存在多个播放量最高的视频，则只需要找出字典序最小的 id 。
返回一个二维字符串数组 answer ，其中 answer[i] = [creatori, idi] 表示 creatori 的流行度 最高 且其最流行的视频 id 是 idi ，可以按任何顺序返回该结果。

 

示例 1：

输入：creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
输出：[["alice","one"],["bob","two"]]
解释：
alice 的流行度是 5 + 5 = 10 。
bob 的流行度是 10 。
chris 的流行度是 4 。
alice 和 bob 是流行度最高的创作者。
bob 播放量最高的视频 id 为 "two" 。
alice 播放量最高的视频 id 是 "one" 和 "three" 。由于 "one" 的字典序比 "three" 更小，所以结果中返回的 id 是 "one" 。
示例 2：

输入：creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
输出：[["alice","b"]]
解释：
id 为 "b" 和 "c" 的视频都满足播放量最高的条件。
由于 "b" 的字典序比 "c" 更小，所以结果中返回的 id 是 "b" 。
 

提示：

n == creators.length == ids.length == views.length
1 <= n <= 105
1 <= creators[i].length, ids[i].length <= 5
creators[i] 和 ids[i] 仅由小写英文字母组成
0 <= views[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/most-popular-video-creator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int i, size = ids.size();
        long long maxView = 0;
        unordered_map<string, pair<int, string>> minIds;
        unordered_map<string, long long> totalViews;
        vector<vector<string>> ans;

        for (i = 0; i < size; ++i) {
            totalViews[creators[i]] += views[i];

            if (minIds.count(creators[i]) == 0) {
                minIds[creators[i]] = { views[i],ids[i] };
            }
            else {
                if (views[i] > minIds[creators[i]].first) {
                    minIds[creators[i]] = { views[i],ids[i] };
                }
                else if (views[i] == minIds[creators[i]].first) {
                    minIds[creators[i]].second = min(minIds[creators[i]].second, ids[i]);
                }
            }
        }

        for (auto& cv : totalViews) {
            if (cv.second > maxView) {
                ans = { {cv.first,minIds[cv.first].second} };
                maxView = cv.second;
            }
            else if (cv.second == maxView) {
                ans.push_back({ cv.first,minIds[cv.first].second });
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> creators = { "alice","bob","alice","chris" };
    vector<string> ids = { "one","two","three","four" };
    vector<int> views = { 5,10,5,4 };
    vector<vector<string>> actual = o.mostPopularCreator(creators, ids, views);
    vector<vector<string>> expected = { {"alice","one"},{"bob","two"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    creators = { "alice","alice","alice" };
    ids = { "a","b","c" };
    views = { 1,2,2 };
    actual = o.mostPopularCreator(creators, ids, views);
    expected = { {"alice","b"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    creators = { "a" };
    ids = { "a" };
    views = { 0 };
    actual = o.mostPopularCreator(creators, ids, views);
    expected = { {"a","a"} };
    check.checkStringVectorRandomOrderVector(expected, actual);
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
