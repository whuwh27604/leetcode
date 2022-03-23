/* 字典序的第K小数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。

 

示例 1:

输入: n = 13, k = 2
输出: 10
解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
示例 2:

输入: n = 1, k = 1
输出: 1
 

提示:

1 <= k <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int kth = 1;

        while (k > 1) {
            int cnt = count(kth, n);  // 统计以当前节点为根的子树总共有多少个节点

            if (cnt < k) {  // 如果比k小，说明kth不在这个子树下面
                k -= cnt;  // 该子树的节点个数全部减掉
                kth += 1;  // 到同级的下一个节点查找
            }
            else {  // 如果比k大，说明kth在这个子树下面
                k -= 1;  // 减去根节点占用的一个排序
                kth *= 10;  // 到下级节点的第一个开始查找
            }
        }

        return kth;
    }

    int count(int root, long long limit) {
        int cnt = 0;
        long long first = root, last = root;

        while (first <= limit) {
            cnt += (int)(min(last, limit) - first + 1);
            first *= 10;
            last = last * 10 + 9;
        }

        return cnt;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(10, o.findKthNumber(13, 2));
    check.checkInt(1, o.findKthNumber(1, 1));
    check.checkInt(999999999, o.findKthNumber(1000000000, 1000000000));
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
