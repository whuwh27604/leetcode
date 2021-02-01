/* 小张刷题计划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
为了提高自己的代码能力，小张制定了 LeetCode 刷题计划，他选中了 LeetCode 题库中的 n 道题，编号从 0 到 n-1，并计划在 m 天内按照题目编号顺序刷完所有的题目（注意，小张不能用多天完成同一题）。

在小张刷题计划中，小张需要用 time[i] 的时间完成编号 i 的题目。此外，小张还可以使用场外求助功能，通过询问他的好朋友小杨题目的解法，可以省去该题的做题时间。为了防止“小张刷题计划”变成“小杨刷题计划”，小张每天最多使用一次求助。

我们定义 m 天中做题时间最多的一天耗时为 T（小杨完成的题目不计入做题总时间）。请你帮小张求出最小的 T是多少。

示例 1：

输入：time = [1,2,3,3], m = 2

输出：3

解释：第一天小张完成前三题，其中第三题找小杨帮忙；第二天完成第四题，并且找小杨帮忙。这样做题时间最多的一天花费了 3 的时间，并且这个值是最小的。

示例 2：

输入：time = [999,999,999], m = 4

输出：0

解释：在前三天中，小张每天求助小杨一次，这样他可以在三天内完成所有的题目并不花任何时间。

 

限制：

1 <= time.length <= 10^5
1 <= time[i] <= 10000
1 <= m <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xiao-zhang-shua-ti-ji-hua
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int low = 0, high = getTotalTime(time);  // m大于等于time.size时，minTime=0；high取所有时间之和，一天就可以刷完所有题

        while (low <= high) {
            int middle = (low + high) / 2;
            int days = countDays(time, middle);  // 假设最小的maxTime是middle，看看需要多少天刷完所有题

            if (days > m) {  // days多了，需要加大maxTime
                low = middle + 1;
            }
            else {
                high = middle - 1;  // 此时middle可能是一个解。如果middle使days==m，middle-1使days>m也没有关系，接下来会一直执行days>m分支，最终low==此时的middle
            }
        }

        return low;
    }

    int getTotalTime(vector<int>& times) {
        int totalTime = 0;

        for (int time : times) {
            totalTime += time;
        }

        return totalTime;
    }
    
    int countDays(vector<int>& times, int maxTime) {
        int days = 0, sum = 0, maximun = 0;

        for (int time : times) {
            maximun = max(maximun, time);
            sum += time;

            if (sum - maximun > maxTime) {  // 肯定是耗时最大的一题求助，所以把它减去
                ++days;
                sum = maximun = time;
            }
        }

        return ++days;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> time = { 1,2,3,3 };
    check.checkInt(3, o.minTime(time, 2));

    time = { 999,999,999 };
    check.checkInt(0, o.minTime(time, 4));

    time = { 999,999,1,999 };
    check.checkInt(1, o.minTime(time, 3));

    time = { 1,2,7,4,7,7 };
    check.checkInt(7, o.minTime(time, 2));

    time = { 94,92,90,57,6,89,63,15,91,74 };
    check.checkInt(63, o.minTime(time, 6));

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
