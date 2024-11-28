/* 训练计划 VI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
教学过程中，教练示范一次，学员跟做三次。该过程被混乱剪辑后，记录于数组 actions，其中 actions[i] 表示做出该动作的人员编号。请返回教练的编号。



示例 1：

输入：actions = [5, 7, 5, 5]
输出：7
示例 2：

输入：actions = [12, 1, 6, 12, 6, 12, 6]
输出：1


提示：

1 <= actions.length <= 10000
1 <= actions[i] < 2^31
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int trainingPlan(vector<int>& actions) {
        int one = 0, two = 0;

        for (int action : actions) {  // 三个状态00，01，10；输入是0则不变，输入是1则循环进入下一个状态
            one = one ^ action & ~two;
            two = two ^ action & ~one;
        }

        return one;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actions = { 5,7,5,5 };
    check.checkInt(7, o.trainingPlan(actions));

    actions = { 12,1,6,12,6,12,6 };
    check.checkInt(1, o.trainingPlan(actions));
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
