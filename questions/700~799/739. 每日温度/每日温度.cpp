/* 每日温度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> decreasingTs;
        int i, size = T.size();
        vector<int> waitingDays(size, 0);

        for (i = 0; i < size; i++) {
            while (!decreasingTs.empty() && (decreasingTs.top().first < T[i])) {
                waitingDays[decreasingTs.top().second] = i - decreasingTs.top().second;
                decreasingTs.pop();
            }

            decreasingTs.push({ T[i],i });
        }

        return waitingDays;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> actual = o.dailyTemperatures(T);
    vector<int> expected = { 1, 1, 4, 2, 1, 1, 0, 0 };
    check.checkIntVector(expected, actual);

    T = { 73 };
    actual = o.dailyTemperatures(T);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    T = { 73,73 };
    actual = o.dailyTemperatures(T);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    T = { 73,72 };
    actual = o.dailyTemperatures(T);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    T = { 73,74 };
    actual = o.dailyTemperatures(T);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);

    T = { 73,72,71,74,75,73,72,72,100 };
    actual = o.dailyTemperatures(T);
    expected = { 3,2,1,1,4,3,2,1,0 };
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
