/* 下载插件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣打算给自己的 VS code 安装使用插件，初始状态下带宽每分钟可以完成 1 个插件的下载。假定每分钟选择以下两种策略之一:

使用当前带宽下载插件
将带宽加倍（下载插件数量随之加倍）
请返回小扣完成下载 n 个插件最少需要多少分钟。

注意：实际的下载的插件数量可以超过 n 个

示例 1：

输入：n = 2

输出：2

解释：
以下两个方案，都能实现 2 分钟内下载 2 个插件

方案一：第一分钟带宽加倍，带宽可每分钟下载 2 个插件；第二分钟下载 2 个插件
方案二：第一分钟下载 1 个插件，第二分钟下载 1 个插件
示例 2：

输入：n = 4

输出：3

解释：
最少需要 3 分钟可完成 4 个插件的下载，以下是其中一种方案:
第一分钟带宽加倍，带宽可每分钟下载 2 个插件;
第二分钟下载 2 个插件;
第三分钟下载 2 个插件。

提示：

1 <= n <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/Ju9Xwi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int leastMinutes(int n) {
        int minutes = 1, num = 1;

        while (num < n) {
            num <<= 1;
            ++minutes;
        }

        return minutes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.leastMinutes(1));
    check.checkInt(2, o.leastMinutes(2));
    check.checkInt(3, o.leastMinutes(4));
    check.checkInt(4, o.leastMinutes(8));
    check.checkInt(5, o.leastMinutes(10));
    check.checkInt(8, o.leastMinutes(100));
    check.checkInt(11, o.leastMinutes(1000));
    check.checkInt(15, o.leastMinutes(10000));
    check.checkInt(18, o.leastMinutes(100000));
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
