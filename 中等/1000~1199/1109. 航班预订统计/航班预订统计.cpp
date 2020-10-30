/* 航班预订统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
这里有 n 个航班，它们分别从 1 到 n 进行编号。

我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k 个座位。

请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。

 

示例：

输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
 

提示：

1 <= bookings.length <= 20000
1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
1 <= bookings[i][2] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/corporate-flight-bookings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> preSum(n + 1, 0);

        for (vector<int>& booking : bookings) {
            preSum[booking[0] - 1] += booking[2];
            preSum[booking[1]] -= booking[2];
        }

        for (int i = 1; i <= n; ++i) {
            preSum[i] += preSum[i - 1];
        }

        preSum.pop_back();
        return preSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> bookings = { {1,2,10},{2,3,20},{2,5,25} };
    vector<int> actual = o.corpFlightBookings(bookings, 5);
    vector<int> expected = { 10,55,45,25,25 };
    check.checkIntVector(expected, actual);

    bookings = { {1,1,10} };
    actual = o.corpFlightBookings(bookings, 1);
    expected = { 10 };
    check.checkIntVector(expected, actual);

    bookings = { {1,1,10} };
    actual = o.corpFlightBookings(bookings, 3);
    expected = { 10,0,0 };
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
