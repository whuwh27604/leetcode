/* H指数 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列。编写一个方法，计算出研究者的 h 指数。

h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"

 

示例:

输入: citations = [0,1,3,5,6]
输出: 3
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。
 

说明:

如果 h 有多有种可能的值 ，h 指数是其中最大的那个。

 

进阶：

这是 H指数 的延伸题目，本题中的 citations 数组是保证有序的。
你可以优化你的算法到对数时间复杂度吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/h-index-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size(), left = 0, right = size - 1, middle = 0, paperNumber = 0;

        if (size == 0) {
            return 0;
        }

        while (left <= right) {
            middle = left + (right - left) / 2;
            int citation = citations[middle];
            paperNumber = size - middle;

            if (citation == paperNumber) {
                return paperNumber;
            }

            if (citation < paperNumber) {
                left = middle + 1;
                continue;
            }

            if ((middle > left) && (citations[middle - 1] < (paperNumber + 1))) {
                break;  // 如果citations[middle - 1] < (paperNumber + 1)，则middle就是答案，不能直接right = middle - 1;
            }
            right = middle - 1;
        }

        return min(citations[middle], paperNumber);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> citations = {};
    check.checkInt(0, o.hIndex(citations));

    citations = { 5 };
    check.checkInt(1, o.hIndex(citations));

    citations = { 0 };
    check.checkInt(0, o.hIndex(citations));

    citations = { 0,0 };
    check.checkInt(0, o.hIndex(citations));

    citations = { 5,5 };
    check.checkInt(2, o.hIndex(citations));

    citations = { 1,5 };
    check.checkInt(1, o.hIndex(citations));

    citations = { 0,0,0,0,0 };
    check.checkInt(0, o.hIndex(citations));

    citations = { 1,1,1,1,1 };
    check.checkInt(1, o.hIndex(citations));

    citations = { 10,10,10,10,10 };
    check.checkInt(5, o.hIndex(citations));

    citations = { 0,1,3,5,6 };
    check.checkInt(3, o.hIndex(citations));

    citations = { 0,1,4,5,6 };
    check.checkInt(3, o.hIndex(citations));

    citations = { 0,3,8,9,10 };
    check.checkInt(3, o.hIndex(citations));

    citations = { 0,4,8,9,10 };
    check.checkInt(4, o.hIndex(citations));

    citations = { 1,4,5,6,7 };
    check.checkInt(4, o.hIndex(citations));
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
