/* 避免洪水泛滥.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你的国家有无数个湖泊，所有湖泊一开始都是空的。当第 n 个湖泊下雨的时候，如果第 n 个湖泊是空的，那么它就会装满水，否则这个湖泊会发生洪水。你的目标是避免任意一个湖泊发生洪水。

给你一个整数数组 rains ，其中：

rains[i] > 0 表示第 i 天时，第 rains[i] 个湖泊会下雨。
rains[i] == 0 表示第 i 天没有湖泊会下雨，你可以选择 一个 湖泊并 抽干 这个湖泊的水。
请返回一个数组 ans ，满足：

ans.length == rains.length
如果 rains[i] > 0 ，那么ans[i] == -1 。
如果 rains[i] == 0 ，ans[i] 是你第 i 天选择抽干的湖泊。
如果有多种可行解，请返回它们中的 任意一个 。如果没办法阻止洪水，请返回一个 空的数组 。

请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生（详情请看示例 4）。

 

示例 1：

输入：rains = [1,2,3,4]
输出：[-1,-1,-1,-1]
解释：第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，装满水的湖泊包括 [1,2,3]
第四天后，装满水的湖泊包括 [1,2,3,4]
没有哪一天你可以抽干任何湖泊的水，也没有湖泊会发生洪水。
示例 2：

输入：rains = [1,2,0,0,2,1]
输出：[-1,-1,2,1,-1,-1]
解释：第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，我们抽干湖泊 2 。所以剩下装满水的湖泊包括 [1]
第四天后，我们抽干湖泊 1 。所以暂时没有装满水的湖泊了。
第五天后，装满水的湖泊包括 [2]。
第六天后，装满水的湖泊包括 [1,2]。
可以看出，这个方案下不会有洪水发生。同时， [-1,-1,1,2,-1,-1] 也是另一个可行的没有洪水的方案。
示例 3：

输入：rains = [1,2,0,1,2]
输出：[]
解释：第二天后，装满水的湖泊包括 [1,2]。我们可以在第三天抽干一个湖泊的水。
但第三天后，湖泊 1 和 2 都会再次下雨，所以不管我们第三天抽干哪个湖泊的水，另一个湖泊都会发生洪水。
示例 4：

输入：rains = [69,0,0,0,69]
输出：[-1,69,1,1,-1]
解释：任何形如 [-1,69,x,y,-1], [-1,x,69,y,-1] 或者 [-1,x,y,69,-1] 都是可行的解，其中 1 <= x,y <= 10^9
示例 5：

输入：rains = [10,20,20]
输出：[]
解释：由于湖泊 20 会连续下 2 天的雨，所以没有没有办法阻止洪水。
 

提示：

1 <= rains.length <= 10^5
0 <= rains[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/avoid-flood-in-the-city
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int i, size = rains.size();
        set<int> zeroIndices;
        unordered_map<int, int> lakeIndices;
        vector<int> ans(size, 1);

        for (i = 0; i < size; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                zeroIndices.insert(i);
                continue;
            }

            if (lakeIndices.count(lake) != 0) {
                auto iter = zeroIndices.upper_bound(lakeIndices[lake]);
                if (iter == zeroIndices.end()) {
                    return {};
                }

                ans[*iter] = lake;
                zeroIndices.erase(iter);
            }

            ans[i] = -1;
            lakeIndices[lake] = i;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rains = { 1,2,3,4 };
    vector<int> actual = o.avoidFlood(rains);
    vector<int> expected = { -1,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    rains = { 1,2,0,0,2,1 };
    actual = o.avoidFlood(rains);
    expected = { -1,-1,2,1,-1,-1 };
    check.checkIntVector(expected, actual);

    rains = { 1,2,0,1,2 };
    actual = o.avoidFlood(rains);
    expected = {  };
    check.checkIntVector(expected, actual);

    rains = { 69,0,0,0,69 };
    actual = o.avoidFlood(rains);
    expected = { -1,69,1,1,-1 };
    check.checkIntVector(expected, actual);

    rains = { 10,20,20 };
    actual = o.avoidFlood(rains);
    expected = {  };
    check.checkIntVector(expected, actual);

    rains = { 0,1,1 };
    actual = o.avoidFlood(rains);
    expected = {  };
    check.checkIntVector(expected, actual);

    rains = { 1,0,2,0,2,1 };
    actual = o.avoidFlood(rains);
    expected = { -1,1,-1,2,-1,-1 };
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
