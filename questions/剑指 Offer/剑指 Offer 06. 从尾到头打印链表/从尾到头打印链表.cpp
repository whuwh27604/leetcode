/* 从尾到头打印链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：

0 <= 链表长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;

        while (head != NULL) {
            ans.push_back(head->val);
            head = head->next;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,3,2 };
    vector<int> actual = o.reversePrint(createList(values));
    vector<int> expected = { 2,3,1 };
    check.checkIntVector(expected, actual);

    values = {  };
    actual = o.reversePrint(createList(values));
    expected = {  };
    check.checkIntVector(expected, actual);
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
