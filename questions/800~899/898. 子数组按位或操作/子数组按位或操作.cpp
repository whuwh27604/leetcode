/* 子数组按位或操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有一个非负整数数组 A。

对于每个（连续的）子数组 B = [A[i], A[i+1], ..., A[j]] （ i <= j），我们对 B 中的每个元素进行按位或操作，获得结果 A[i] | A[i+1] | ... | A[j]。

返回可能结果的数量。 （多次出现的结果在最终答案中仅计算一次。）

 

示例 1：

输入：[0]
输出：1
解释：
只有一个可能的结果 0 。
示例 2：

输入：[1,1,2]
输出：3
解释：
可能的子数组为 [1]，[1]，[2]，[1, 1]，[1, 2]，[1, 1, 2]。
产生的结果为 1，1，2，1，3，3 。
有三个唯一值，所以答案是 3 。
示例 3：

输入：[1,2,4]
输出：6
解释：
可能的结果是 1，2，3，4，6，以及 7 。
 

提示：

1 <= A.length <= 50000
0 <= A[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-ors-of-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> ans;
        int i, j, size = A.size();

        for (i = 0; i < size; ++i) {
            ans.insert(A[i]);

            for (j = i - 1; j >= 0; --j) {
                if ((A[j] | A[i]) == A[j]) {
                    break;
                }

                A[j] |= A[i];
                ans.insert(A[j]);
            }
        }

        return ans.size();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 0 };
    check.checkInt(1, o.subarrayBitwiseORs(A));

    A = { 1,1,2 };
    check.checkInt(3, o.subarrayBitwiseORs(A));

    A = { 1,2,4 };
    check.checkInt(6, o.subarrayBitwiseORs(A));
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
