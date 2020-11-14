/* 和相同的二元子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。

 

示例：

输入：A = [1,0,1,0,1], S = 2
输出：4
解释：
如下面黑体所示，有 4 个满足题目要求的子数组：
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

提示：

A.length <= 30000
0 <= S <= A.length
A[i] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-subarrays-with-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int size = A.size(), preSum = 0, ans = 0;
        vector<int> preSumCount(size + 1, 0);
        preSumCount[0] = 1;

        for (int num : A) {
            preSum += num;

            if (preSum >= S) {
                ans += preSumCount[preSum - S];
            }

            preSumCount[preSum] += 1;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 0 };
    check.checkInt(1, o.numSubarraysWithSum(A, 0));

    A = { 0,0 };
    check.checkInt(3, o.numSubarraysWithSum(A, 0));

    A = { 1,0,1,0,0,1,0,0,0 };
    check.checkInt(10, o.numSubarraysWithSum(A, 0));

    A = {  };
    check.checkInt(0, o.numSubarraysWithSum(A, 0));

    A = {  };
    check.checkInt(0, o.numSubarraysWithSum(A, 1));

    A = { 0 };
    check.checkInt(0, o.numSubarraysWithSum(A, 1));

    A = { 0,0 };
    check.checkInt(0, o.numSubarraysWithSum(A, 1));

    A = { 1,0,1,0,1 };
    check.checkInt(4, o.numSubarraysWithSum(A, 2));

    A = { 0,0,1 };
    check.checkInt(3, o.numSubarraysWithSum(A, 1));
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
