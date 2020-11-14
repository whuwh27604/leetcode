/* 子数组的最小值之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，找到 min(B) 的总和，其中 B 的范围为 A 的每个（连续）子数组。

由于答案可能很大，因此返回答案模 10^9 + 7。

 

示例：

输入：[3,1,2,4]
输出：17
解释：
子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
 

提示：

1 <= A <= 30000
1 <= A[i] <= 30000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-subarray-minimums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        A.push_back(-1);  // 最后加个-1把栈里所有元素pop出来
        int i, size = A.size();
        vector<pair<int, int>> lrCount(size, pair<int, int>{0, 0});
        stack<pair<int, int>> increasingNums;
        increasingNums.push({ -1, -1 });  // 栈底放入-1，避免过程中出现空栈

        for (i = 0; i < size; ++i) {
            while (A[i] < increasingNums.top().first) {
                lrCount[increasingNums.top().second].second = i - increasingNums.top().second;
                increasingNums.pop();
            }

            lrCount[i].first = i - increasingNums.top().second;
            increasingNums.push({ A[i],i });
        }

        long long sum = 0;
        for (i = 0; i < size - 1; ++i) {
            sum = (sum + ((long long)lrCount[i].first * lrCount[i].second) * A[i]) % 1000000007;
        }

        return (int)sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 3,1,2,4 };
    check.checkInt(17, o.sumSubarrayMins(A));

    A = { 3 };
    check.checkInt(3, o.sumSubarrayMins(A));

    A = { 3,5 };
    check.checkInt(11, o.sumSubarrayMins(A));

    A = { 10,3,4,5,3,2,3,10 };
    check.checkInt(108, o.sumSubarrayMins(A));

    A = { 1,7,5,2,4,3,9 };
    check.checkInt(73, o.sumSubarrayMins(A));

    A = { 1,2,3,4,5,4,3,2,1 };
    check.checkInt(95, o.sumSubarrayMins(A));

    A = { 5,5,5,5,5 };
    check.checkInt(75, o.sumSubarrayMins(A));
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
