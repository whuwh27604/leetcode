/* 柠檬水找零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

示例 1：

输入：[5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
示例 2：

输入：[5,5,10]
输出：true
示例 3：

输入：[10,10]
输出：false
示例 4：

输入：[5,5,10,10,20]
输出：false
解释：
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
 

提示：

0 <= bills.length <= 10000
bills[i] 不是 5 就是 10 或是 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lemonade-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        count5 = 0;
        count10 = 0;

        for (unsigned int i = 0; i < bills.size(); i++) {
            int result, dollar = bills[i];
            if (dollar == 5) {
                result = dealWithFive();
            }
            else if (dollar == 10) {
                result = dealWithTen();
            }
            else {
                result = dealWithTwenty();
            }

            if (result == -1) {
                return false;
            }
        }

        return true;
    }

    int dealWithFive() {
        count5++;
        return 0;
    }

    int dealWithTen() {
        if (count5 == 0) {
            return -1;
        }

        count10++;
        count5--;
        return 0;
    }

    int dealWithTwenty() {
        if (count10 == 0) {
            if (count5 < 3) {
                return -1;
            }
            count5 -= 3;
        }
        else {
            if (count5 == 0) {
                return -1;
            }
            count10 -= 1;
            count5 -= 1;
        }

        return 0;
    }

    Solution() : count5(0), count10(10) {}

    int count5;
    int count10;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> bills = { 5,5,5,10,20 };
    check.checkBool(true, o.lemonadeChange(bills));

    bills = { 10,10 };
    check.checkBool(false, o.lemonadeChange(bills));

    bills = { 5,5,10,10,20 };
    check.checkBool(false, o.lemonadeChange(bills));

    bills = {  };
    check.checkBool(true, o.lemonadeChange(bills));

    bills = { 5 };
    check.checkBool(true, o.lemonadeChange(bills));

    bills = { 10 };
    check.checkBool(false, o.lemonadeChange(bills));

    bills = { 20 };
    check.checkBool(false, o.lemonadeChange(bills));

    bills = { 5,5,5,10,5,5,10,20,20,20 };
    check.checkBool(false, o.lemonadeChange(bills));
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
