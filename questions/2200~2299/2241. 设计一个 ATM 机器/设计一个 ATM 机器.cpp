/* 设计一个 ATM 机器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 ATM 机器，存有 5 种面值的钞票：20 ，50 ，100 ，200 和 500 美元。初始时，ATM 机是空的。用户可以用它存或者取任意数目的钱。

取款时，机器会优先取 较大 数额的钱。

比方说，你想取 $300 ，并且机器里有 2 张 $50 的钞票，1 张 $100 的钞票和1 张 $200 的钞票，那么机器会取出 $100 和 $200 的钞票。
但是，如果你想取 $600 ，机器里有 3 张 $200 的钞票和1 张 $500 的钞票，那么取款请求会被拒绝，因为机器会先取出 $500 的钞票，然后无法取出剩余的 $100 。注意，因为有 $500 钞票的存在，机器 不能 取 $200 的钞票。
请你实现 ATM 类：

ATM() 初始化 ATM 对象。
void deposit(int[] banknotesCount) 分别存入 $20 ，$50，$100，$200 和 $500 钞票的数目。
int[] withdraw(int amount) 返回一个长度为 5 的数组，分别表示 $20 ，$50，$100 ，$200 和 $500 钞票的数目，并且更新 ATM 机里取款后钞票的剩余数量。如果无法取出指定数额的钱，请返回 [-1] （这种情况下 不 取出任何钞票）。
 

示例 1：

输入：
["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
[[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]
输出：
[null, null, [0,0,1,0,1], null, [-1], [0,1,0,0,1]]

解释：
ATM atm = new ATM();
atm.deposit([0,0,1,2,1]); // 存入 1 张 $100 ，2 张 $200 和 1 张 $500 的钞票。
atm.withdraw(600);        // 返回 [0,0,1,0,1] 。机器返回 1 张 $100 和 1 张 $500 的钞票。机器里剩余钞票的数量为 [0,0,0,2,0] 。
atm.deposit([0,1,0,1,1]); // 存入 1 张 $50 ，1 张 $200 和 1 张 $500 的钞票。
                          // 机器中剩余钞票数量为 [0,1,0,3,1] 。
atm.withdraw(600);        // 返回 [-1] 。机器会尝试取出 $500 的钞票，然后无法得到剩余的 $100 ，所以取款请求会被拒绝。
                          // 由于请求被拒绝，机器中钞票的数量不会发生改变。
atm.withdraw(550);        // 返回 [0,1,0,0,1] ，机器会返回 1 张 $50 的钞票和 1 张 $500 的钞票。
 

提示：

banknotesCount.length == 5
0 <= banknotesCount[i] <= 109
1 <= amount <= 109
总共 最多有 5000 次 withdraw 和 deposit 的调用。
函数 withdraw 和 deposit 至少各有 一次 调用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-an-atm-machine
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class ATM {
public:
    ATM() {
        count500 = 0;
        count200 = 0;
        count100 = 0;
        count50 = 0;
        count20 = 0;
    }

    void deposit(vector<int> banknotesCount) {
        count20 += banknotesCount[0];
        count50 += banknotesCount[1];
        count100 += banknotesCount[2];
        count200 += banknotesCount[3];
        count500 += banknotesCount[4];
    }

    vector<int> withdraw(int amount) {
        long long cnt500 = 0, cnt200 = 0, cnt100 = 0, cnt50 = 0, cnt20 = 0, money = amount;

        if (money >= 500) {
            cnt500 = min(count500, money / 500);
            money -= (cnt500 * 500);
        }

        if (money >= 200) {
            cnt200 = min(count200, money / 200);
            money -= (cnt200 * 200);
        }

        if (money >= 100) {
            cnt100 = min(count100, money / 100);
            money -= (cnt100 * 100);
        }

        if (money >= 50) {
            cnt50 = min(count50, money / 50);
            money -= (cnt50 * 50);
        }

        if (money >= 20) {
            cnt20 = min(count20, money / 20);
            money -= (cnt20 * 20);
        }

        if (money != 0) {
            return { -1 };
        }

        count500 -= cnt500;
        count200 -= cnt200;
        count100 -= cnt100;
        count50 -= cnt50;
        count20 -= cnt20;

        return { (int)cnt20,(int)cnt50,(int)cnt100,(int)cnt200,(int)cnt500 };
    }

private:
    long long count500;
    long long count200;
    long long count100;
    long long count50;
    long long count20;
};

int main()
{
    CheckResult check;

    ATM o1;
    vector<int> banknotesCount = { 0,0,1,2,1 };
    o1.deposit(banknotesCount);
    vector<int> actual = o1.withdraw(600);
    vector<int> expected = { 0,0,1,0,1 };
    check.checkIntVector(expected, actual);
    banknotesCount = { 0,1,0,1,1 };
    o1.deposit(banknotesCount);
    actual = o1.withdraw(600);
    expected = { -1 };
    check.checkIntVector(expected, actual);
    actual = o1.withdraw(550);
    expected = { 0,1,0,0,1 };
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
