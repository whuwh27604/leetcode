/* 分割数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个数组 A，将其划分为两个不相交（没有公共元素）的连续子数组 left 和 right， 使得：

left 中的每个元素都小于或等于 right 中的每个元素。
left 和 right 都是非空的。
left 要尽可能小。
在完成这样的分组后返回 left 的长度。可以保证存在这样的划分方法。

 

示例 1：

输入：[5,0,3,8,6]
输出：3
解释：left = [5,0,3]，right = [8,6]
示例 2：

输入：[1,1,1,0,6,12]
输出：4
解释：left = [1,1,1,0]，right = [6,12]
 

提示：

2 <= A.length <= 30000
0 <= A[i] <= 10^6
可以保证至少有一种方法能够按题目所描述的那样对 A 进行划分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-disjoint-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int i, size = A.size();
        int leftMax = A[0], globleMax = A[0], len = 0;

        for (i = 1; i < size; ++i) {
            if (A[i] > globleMax) {
                globleMax = A[i];
            }
            else if (A[i] < leftMax) {
                leftMax = globleMax;
                len = i;
            }
        }

        return len + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 5,0,3,8,6 };
    check.checkInt(3, o.partitionDisjoint(A));

    A = { 1,1,1,0,6,12 };
    check.checkInt(4, o.partitionDisjoint(A));

    A = { 1,1,1,6,12 };
    check.checkInt(1, o.partitionDisjoint(A));

    A = { 1,2 };
    check.checkInt(1, o.partitionDisjoint(A));

    A = { 1,1 };
    check.checkInt(1, o.partitionDisjoint(A));

    A = { 80,86,79,900,85,89,1000 };
    check.checkInt(6, o.partitionDisjoint(A));
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
