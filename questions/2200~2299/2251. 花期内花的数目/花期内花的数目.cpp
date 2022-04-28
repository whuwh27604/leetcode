/* 花期内花的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的 花期 从 starti 到 endi （都 包含）。同时给你一个下标从 0 开始大小为 n 的整数数组 persons ，persons[i] 是第 i 个人来看花的时间。

请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目 。

 

示例 1：



输入：flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
输出：[1,2,2,2]
解释：上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。
示例 2：



输入：flowers = [[1,10],[3,3]], persons = [3,3,2]
输出：[2,2,1]
解释：上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。
 

提示：

1 <= flowers.length <= 5 * 104
flowers[i].length == 2
1 <= starti <= endi <= 109
1 <= persons.length <= 5 * 104
1 <= persons[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-flowers-in-full-bloom
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        unordered_map<int, int> times;
        int i, size = persons.size(), maxTime = discretization(flowers, persons, times);
        vector<int> diffs(maxTime + 1, 0), bloomFlowers(size);

        for (auto& flower : flowers) {
            ++diffs[times[flower[0]]];
            --diffs[times[flower[1] + 1]];
        }

        for (i = 1; i <= maxTime; ++i) {
            diffs[i] += diffs[i - 1];
        }

        for (i = 0; i < size; ++i) {
            bloomFlowers[i] = diffs[times[persons[i]]];
        }

        return bloomFlowers;
    }

    int discretization(vector<vector<int>>& flowers, vector<int>& persons, unordered_map<int, int>& times) {
        set<int> nums;
        int index = 0;

        for (auto& flower : flowers) {
            nums.insert(flower[0]);
            nums.insert(flower[1] + 1);
        }

        for (int person : persons) {
            nums.insert(person);
        }

        for (int time : nums) {
            times[time] = index++;
        }

        return index;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> flowers = { {1,6},{3,7},{9,12},{4,13} };
    vector<int> persons = { 2,3,7,11 };
    vector<int> actual = o.fullBloomFlowers(flowers, persons);
    vector<int> expected = { 1,2,2,2 };
    check.checkIntVector(expected, actual);

    flowers = { {1,10},{3,3} };
    persons = { 3,3,2 };
    actual = o.fullBloomFlowers(flowers, persons);
    expected = { 2,2,1 };
    check.checkIntVector(expected, actual);

    flowers = { {5,5} };
    persons = { 5 };
    actual = o.fullBloomFlowers(flowers, persons);
    expected = { 1 };
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
