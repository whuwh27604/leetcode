/* 选择建筑的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二进制字符串 s ，它表示一条街沿途的建筑类型，其中：

s[i] = '0' 表示第 i 栋建筑是一栋办公楼，
s[i] = '1' 表示第 i 栋建筑是一间餐厅。
作为市政厅的官员，你需要随机 选择 3 栋建筑。然而，为了确保多样性，选出来的 3 栋建筑 相邻 的两栋不能是同一类型。

比方说，给你 s = "001101" ，我们不能选择第 1 ，3 和 5 栋建筑，因为得到的子序列是 "011" ，有相邻两栋建筑是同一类型，所以 不合 题意。
请你返回可以选择 3 栋建筑的 有效方案数 。

 

示例 1：

输入：s = "001101"
输出：6
解释：
以下下标集合是合法的：
- [0,2,4] ，从 "001101" 得到 "010"
- [0,3,4] ，从 "001101" 得到 "010"
- [1,2,4] ，从 "001101" 得到 "010"
- [1,3,4] ，从 "001101" 得到 "010"
- [2,4,5] ，从 "001101" 得到 "101"
- [3,4,5] ，从 "001101" 得到 "101"
没有别的合法选择，所以总共有 6 种方法。
示例 2：

输入：s = "11100"
输出：0
解释：没有任何符合题意的选择。
 

提示：

3 <= s.length <= 105
s[i] 要么是 '0' ，要么是 '1' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-select-buildings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        long long ways0 = 0, ways1 = 0, ways01 = 0, ways10 = 0, ways010 = 0, ways101 = 0;

        for (char c : s) {
            if (c == '0') {
                ways010 += ways01;
                ways10 += ways1;
                ways0 += 1;
            }
            else {
                ways101 += ways10;
                ways01 += ways0;
                ways1 += 1;
            }
        }

        return ways010 + ways101;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(6, o.numberOfWays("001101"));
    check.checkLongLong(0, o.numberOfWays("11100"));
    check.checkLongLong(1, o.numberOfWays("101"));
    check.checkLongLong(1, o.numberOfWays("010"));
    check.checkLongLong(0, o.numberOfWays("001"));
    check.checkLongLong(54890, o.numberOfWays("00110111100001101111000011011110000110111100001101111000011011110000110111100001101111000011011110000110111100"));
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
