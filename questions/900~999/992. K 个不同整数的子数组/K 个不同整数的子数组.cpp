/* K 个不同整数的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）

返回 A 中好子数组的数目。

 

示例 1：

输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
示例 2：

输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 

提示：

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarrays-with-k-different-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int left = 0, right, size = A.size(), subarrays = 0;
        unordered_map<int, int> numsInWindow;
        unordered_map<int, int> lastIndices;  // 记录一个数最后出现时的索引
        set<int> indices;  // 窗口内的数，最小的一个最后索引到当前位置就是满足条件的最小子数组

        for (right = 0; right < size; ++right) {
            int num = A[right];
            ++numsInWindow[num];  // 更新窗口内的数

            if (lastIndices.count(num) != 0) {
                indices.erase(lastIndices[num]);
            }
            lastIndices[num] = right;  // 更新最小索引
            indices.insert(right);  // 排序找最小的一个

            while ((int)numsInWindow.size() > K) {  // 窗口内的数多了
                num = A[left];

                if (--numsInWindow[num] == 0) {  // 移除一个
                    numsInWindow.erase(num);
                    lastIndices.erase(num);
                    indices.erase(left);
                }

                ++left;
            }

            if (numsInWindow.size() == K) {
                subarrays += (*indices.begin() - left + 1);  // 从left到最小子数组之间所有的子数组都是以right为结尾的解
            }
        }

        return subarrays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,2,1,2,3 };
    check.checkInt(7, o.subarraysWithKDistinct(A, 2));

    A = { 1,2,1,3,4 };
    check.checkInt(3, o.subarraysWithKDistinct(A, 3));

    A = { 4 };
    check.checkInt(1, o.subarraysWithKDistinct(A, 1));

    A = { 4,4 };
    check.checkInt(0, o.subarraysWithKDistinct(A, 2));

    A = { 4,4,4,4,4 };
    check.checkInt(15, o.subarraysWithKDistinct(A, 1));
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
