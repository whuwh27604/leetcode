/* 完成一半题目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 N 位扣友参加了微软与力扣举办了「以扣会友」线下活动。主办方提供了 2*N 道题目，整型数组 questions 中每个数字对应了每道题目所涉及的知识点类型。
若每位扣友选择不同的一题，请返回被选的 N 道题目至少包含多少种知识点类型。

示例 1：

输入：questions = [2,1,6,2]

输出：1

解释：有 2 位扣友在 4 道题目中选择 2 题。
可选择完成知识点类型为 2 的题目时，此时仅一种知识点类型
因此至少包含 1 种知识点类型。

示例 2：

输入：questions = [1,5,1,3,4,5,2,5,3,3,8,6]

输出：2

解释：有 6 位扣友在 12 道题目中选择题目，需要选择 6 题。
选择完成知识点类型为 3、5 的题目，因此至少包含 2 种知识点类型。

提示：

questions.length == 2*n
2 <= questions.length <= 10^5
1 <= questions[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/WqXACV
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        int i, n = questions.size() / 2, maxKnowledge = *max_element(questions.begin(), questions.end()), count = 0, types = 0;
        vector<int> knowledges(maxKnowledge + 1, 0);
        multiset<int> knowledgeCount;

        for (int knowledge : questions) {
            ++knowledges[knowledge];
        }

        for (i = 1; i <= maxKnowledge; ++i) {
            if (knowledges[i] != 0) {
                knowledgeCount.insert(knowledges[i]);
            }
        }

        for (auto iter = --knowledgeCount.end(); count < n; --iter) {
            ++types;
            count += *iter;
        }

        return types;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> questions = { 2,1,6,2 };
    check.checkInt(1, o.halfQuestions(questions));

    questions = { 1,5,1,3,4,5,2,5,3,3,8,6 };
    check.checkInt(2, o.halfQuestions(questions));

    questions = { 1,1 };
    check.checkInt(1, o.halfQuestions(questions));

    questions = { 1,2 };
    check.checkInt(1, o.halfQuestions(questions));

    questions = { 1,2,3,4,5,6,7,8 };
    check.checkInt(4, o.halfQuestions(questions));
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
