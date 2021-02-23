/* 二进制链表转整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

 

示例 1：



输入：head = [1,0,1]
输出：5
解释：二进制数 (101) 转化为十进制数 (5)
示例 2：

输入：head = [0]
输出：0
示例 3：

输入：head = [1]
输出：1
示例 4：

输入：head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
输出：18880
示例 5：

输入：head = [0,0]
输出：0
 

提示：

链表不为空。
链表的结点总数不超过 30。
每个结点的值不是 0 就是 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/ListNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;

        while (head != NULL) {
            num = num * 2 + head->val;
            head = head->next;
        }

        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,0,1 };
    check.checkInt(5, o.getDecimalValue(createList(values)));

    values = { 1 };
    check.checkInt(1, o.getDecimalValue(createList(values)));

    values = { 0 };
    check.checkInt(0, o.getDecimalValue(createList(values)));

    values = { 1,0,0,1,0,0,1,1,1,0,0,0,0,0,0 };
    check.checkInt(18880, o.getDecimalValue(createList(values)));

    values = { 0,0 };
    check.checkInt(0, o.getDecimalValue(createList(values)));
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
