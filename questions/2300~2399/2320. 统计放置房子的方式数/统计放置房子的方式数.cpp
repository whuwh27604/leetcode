// 统计放置房子的方式数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        int total = dp(1, 1, n);

        return dp(total, total, n);
    }

    int dp(int house, int noHouse, int n) {
        int mod = 1000000007;

        for (int i = 1; i < n; ++i) {
            int tmpHouse = noHouse;
            int tmpNoHouse = (house + noHouse) % mod;
            house = tmpHouse;
            noHouse = tmpNoHouse;
        }

        return (house + noHouse) % mod;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.countHousePlacements(1));
    check.checkInt(9, o.countHousePlacements(2));
    check.checkInt(402613600, o.countHousePlacements(10000));
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
