/* 猜数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小A 和 小B 在玩猜数字。小B 每次从 1, 2, 3 中随机选择一个，小A 每次也从 1, 2, 3 中选择一个猜。他们一共进行三次这个游戏，请返回 小A 猜对了几次？

 

输入的guess数组为 小A 每次的猜测，answer数组为 小B 每次的选择。guess和answer的长度都等于3。

 

示例 1：

输入：guess = [1,2,3], answer = [1,2,3]
输出：3
解释：小A 每次都猜对了。
 

示例 2：

输入：guess = [2,2,3], answer = [3,2,1]
输出：1
解释：小A 只猜对了第二次。
 

限制：

guess的长度 = 3
answer的长度 = 3
guess的元素取值为 {1, 2, 3} 之一。
answer的元素取值为 {1, 2, 3} 之一。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/guess-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int right = 0;

        for (int i = 0; i < 3; i++) {
            if (guess[i] == answer[i]) {
                right++;
            }
        }

        return right;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> guess = { 1,2,3 };
    vector<int> answer = { 1,2,3 };
    check.checkInt(3, o.game(guess, answer));
    
    guess = { 2,2,3 };
    answer = { 3,2,1 };
    check.checkInt(1, o.game(guess, answer));
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
