/* 森林中的兔子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在 answers 数组里。

返回森林中兔子的最少数量。

示例:
输入: answers = [1, 1, 2]
输出: 5
解释:
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
因此森林中兔子的最少数量是 5: 3 只回答的和 2 只没有回答的。

输入: answers = [10, 10, 10]
输出: 11

输入: answers = []
输出: 0
说明:

answers 的长度最大为1000。
answers[i] 是在 [0, 999] 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rabbits-in-forest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> answerTimes;
        countAnswers(answers, answerTimes);

        int count = 0;
        for (auto iter = answerTimes.begin(); iter != answerTimes.end(); iter++) {
            /* 假设回答x的兔子有y个，那么最多只能有x+1个兔子是一种颜色，最少有(y-1)/(x+1)+1种颜色，所以最少有((y-1)/(x+1)+1)*(x+1)个兔子
               比如7个兔子回答2，那么最多3个兔子是颜色1，3个兔子是颜色2，还剩1个兔子和2个没有回答的兔子同一种颜色*/
            count += (((iter->second - 1) / (iter->first + 1) + 1) * (iter->first + 1));
        }

        return count;
    }

    void countAnswers(vector<int>& answers, unordered_map<int, int>& answerTimes) {
        for (int answer : answers) {
            auto iter = answerTimes.find(answer);
            if (iter == answerTimes.end()) {
                answerTimes[answer] = 1;
            }
            else {
                iter->second++;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> answers = { 1,1,2 };
    check.checkInt(5, o.numRabbits(answers));

    answers = { 10,10,10 };
    check.checkInt(11, o.numRabbits(answers));

    answers = {  };
    check.checkInt(0, o.numRabbits(answers));

    answers = { 0 };
    check.checkInt(1, o.numRabbits(answers));

    answers = { 1,0,0,0,1 };
    check.checkInt(5, o.numRabbits(answers));

    answers = { 0,0,1,1,1 };
    check.checkInt(6, o.numRabbits(answers));
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
