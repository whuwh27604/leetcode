/* 棒球比赛.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你现在是棒球比赛记录员。
给定一个字符串列表，每个字符串可以是以下四种类型之一：
1.整数（一轮的得分）：直接表示您在本轮中获得的积分数。
2. "+"（一轮的得分）：表示本轮获得的得分是前两轮有效 回合得分的总和。
3. "D"（一轮的得分）：表示本轮获得的得分是前一轮有效 回合得分的两倍。
4. "C"（一个操作，这不是一个回合的分数）：表示您获得的最后一个有效 回合的分数是无效的，应该被移除。

每一轮的操作都是永久性的，可能会对前一轮和后一轮产生影响。
你需要返回你在所有回合中得分的总和。

示例 1:

输入: ["5","2","C","D","+"]
输出: 30
解释:
第1轮：你可以得到5分。总和是：5。
第2轮：你可以得到2分。总和是：7。
操作1：第2轮的数据无效。总和是：5。
第3轮：你可以得到10分（第2轮的数据已被删除）。总数是：15。
第4轮：你可以得到5 + 10 = 15分。总数是：30。
示例 2:

输入: ["5","-2","4","C","D","9","+","+"]
输出: 27
解释:
第1轮：你可以得到5分。总和是：5。
第2轮：你可以得到-2分。总数是：3。
第3轮：你可以得到4分。总和是：7。
操作1：第3轮的数据无效。总数是：3。
第4轮：你可以得到-4分（第三轮的数据已被删除）。总和是：-1。
第5轮：你可以得到9分。总数是：8。
第6轮：你可以得到-4 + 9 = 5分。总数是13。
第7轮：你可以得到9 + 5 = 14分。总数是27。
注意：

输入列表的大小将介于1和1000之间。
列表中的每个整数都将介于-30000和30000之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/baseball-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <sstream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> pointsStack;
        for (unsigned int i = 0; i < ops.size(); i++) {
            string operation = ops[i];
            if (operation == "+") {
                processAdd(pointsStack);
            }
            else if (operation == "D") {
                processDouble(pointsStack);
            }
            else if (operation == "C") {
                processCancel(pointsStack);
            }
            else {
                processPoint(operation, pointsStack);
            }
        }

        int sum = 0;
        while (!pointsStack.empty()) {
            sum += pointsStack.top();
            pointsStack.pop();
        }
        return sum;
    }

    void processAdd(stack<int>& pointsStack) {
        int points = pointsStack.top();
        pointsStack.pop();
        int currentPoints = (points + pointsStack.top());
        pointsStack.push(points);
        pointsStack.push(currentPoints);
    }

    void processDouble(stack<int>& pointsStack) {
        int points = pointsStack.top();
        pointsStack.push(points * 2);
    }

    void processCancel(stack<int>& pointsStack) {
        pointsStack.pop();
    }

    void processPoint(string& operation, stack<int>& pointsStack) {
        stringstream ss;
        ss << operation;
        int points;
        ss >> points;
        pointsStack.push(points);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> ops = { "5","2","C","D","+" };
    check.checkInt(30, o.calPoints(ops));

    ops = { "5","-2","4","C","D","9","+","+" };
    check.checkInt(27, o.calPoints(ops));

    ops = { "5" };
    check.checkInt(5, o.calPoints(ops));
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
