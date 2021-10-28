/* 乘法表中第k小的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？

给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。

例 1：

输入: m = 3, n = 3, k = 5
输出: 3
解释:
乘法表:
1	2	3
2	4	6
3	6	9

第5小的数字是 3 (1, 2, 2, 3, 3).
例 2：

输入: m = 2, n = 3, k = 6
输出: 6
解释:
乘法表:
1	2	3
2	4	6

第6小的数字是 6 (1, 2, 2, 3, 4, 6).
注意：

m 和 n 的范围在 [1, 30000] 之间。
k 的范围在 [1, m * n] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n, kthNumber = 0;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (isNoGreaterTargetNoLessK(m, n, k, middle)) {
                kthNumber = middle;
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return kthNumber;
    }

    bool isNoGreaterTargetNoLessK(int m, int n, int k, int target) {
        int i, j = n, count = 0;

        for (i = 1; i <= m; ++i) {
            while (i * j > target) {
                --j;
            }

            count += j;
            if (count >= k) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.findKthNumber(3, 3, 5));
    check.checkInt(9, o.findKthNumber(3, 3, 9));
    check.checkInt(1, o.findKthNumber(3, 3, 1));
    check.checkInt(6, o.findKthNumber(2, 3, 6));
    check.checkInt(3, o.findKthNumber(4, 4, 4));
    check.checkInt(1, o.findKthNumber(1, 1, 1));
    check.checkInt(91217098, o.findKthNumber(30000, 30000, 300000000));
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
