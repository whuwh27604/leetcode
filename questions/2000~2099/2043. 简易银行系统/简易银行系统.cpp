/* 简易银行系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你的任务是为一个很受欢迎的银行设计一款程序，以自动化执行所有传入的交易（转账，存款和取款）。银行共有 n 个账户，编号从 1 到 n 。每个账号的初始余额存储在一个下标从 0 开始的整数数组 balance 中，其中第 (i + 1) 个账户的初始余额是 balance[i] 。

请你执行所有 有效的 交易。如果满足下面全部条件，则交易 有效 ：

指定的账户数量在 1 和 n 之间，且
取款或者转账需要的钱的总数 小于或者等于 账户余额。
实现 Bank 类：

Bank(long[] balance) 使用下标从 0 开始的整数数组 balance 初始化该对象。
boolean transfer(int account1, int account2, long money) 从编号为 account1 的账户向编号为 account2 的账户转帐 money 美元。如果交易成功，返回 true ，否则，返回 false 。
boolean deposit(int account, long money) 向编号为 account 的账户存款 money 美元。如果交易成功，返回 true ；否则，返回 false 。
boolean withdraw(int account, long money) 从编号为 account 的账户取款 money 美元。如果交易成功，返回 true ；否则，返回 false 。
 

示例：

输入：
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
输出：
[null, true, true, true, false, false]

解释：
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // 返回 true ，账户 3 的余额是 $20 ，所以可以取款 $10 。
                         // 账户 3 余额为 $20 - $10 = $10 。
bank.transfer(5, 1, 20); // 返回 true ，账户 5 的余额是 $30 ，所以可以转账 $20 。
                         // 账户 5 的余额为 $30 - $20 = $10 ，账户 1 的余额为 $10 + $20 = $30 。
bank.deposit(5, 20);     // 返回 true ，可以向账户 5 存款 $20 。
                         // 账户 5 的余额为 $10 + $20 = $30 。
bank.transfer(3, 4, 15); // 返回 false ，账户 3 的当前余额是 $10 。
                         // 所以无法转账 $15 。
bank.withdraw(10, 50);   // 返回 false ，交易无效，因为账户 10 并不存在。
 

提示：

n == balance.length
1 <= n, account, account1, account2 <= 105
0 <= balance[i], money <= 1012
transfer, deposit, withdraw 三个函数，每个 最多调用 104 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simple-bank-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) {
        balances = balance;
        maxAccount = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 == 0 || account1 > maxAccount || account2 == 0 || account2 > maxAccount || balances[account1 - 1] < money) {
            return false;
        }

        balances[account1 - 1] -= money;
        balances[account2 - 1] += money;

        return true;
    }

    bool deposit(int account, long long money) {
        if (account == 0 || account > maxAccount) {
            return false;
        }

        balances[account - 1] += money;

        return true;
    }

    bool withdraw(int account, long long money) {
        if (account == 0 || account > maxAccount || balances[account - 1] < money) {
            return false;
        }

        balances[account - 1] -= money;

        return true;
    }

private:
    vector<long long> balances;
    int maxAccount;
};

int main()
{
    CheckResult check;
    
    vector<long long> balance = { 10,100,20,50,30 };
    Bank o1(balance);
    check.checkBool(true, o1.withdraw(3, 10));
    check.checkBool(true, o1.transfer(5, 1, 20));
    check.checkBool(true, o1.deposit(5, 20));
    check.checkBool(false, o1.transfer(3, 4, 15));
    check.checkBool(false, o1.withdraw(10, 50));
    check.checkBool(false, o1.deposit(0, 20));

    balance = { 767,653,252,849,480,187,761,243,408,385,334,732,289,886,149,320,827,111,315,155,695,110,473,585,83,936,188,818,33,984,66,549,954,761,662,212,208,215,251,792,956,261,863,374,411,639,599,418,909,208,984,602,741,302,911,616,537,422,61,746,206,396,446,661,48,156,725,662,422,624,704,143,94,702,126,76,539,83,270,717,736,393,607,895,661 };
    Bank o2(balance);
    check.checkBool(true, o2.deposit(68, 668));
    check.checkBool(true, o2.deposit(25, 978));
    check.checkBool(false, o2.transfer(8, 31, 924));
    check.checkBool(false, o2.transfer(2, 6, 857));
    check.checkBool(true, o2.transfer(20, 43, 59));
    check.checkBool(true, o2.deposit(71, 307));
    check.checkBool(false, o2.transfer(11, 46, 577));
    check.checkBool(false, o2.withdraw(37, 377));
    check.checkBool(true, o2.deposit(72, 835));
    check.checkBool(false, o2.withdraw(82, 574));
    check.checkBool(false, o2.transfer(67, 9, 939));
    check.checkBool(true, o2.transfer(24, 49, 251));
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
