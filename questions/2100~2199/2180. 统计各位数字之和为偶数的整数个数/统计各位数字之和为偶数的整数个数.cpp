/* 统计各位数字之和为偶数的整数个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 num ，请你统计并返回 小于或等于 num 且各位数字之和为 偶数 的正整数的数目。

正整数的 各位数字之和 是其所有位上的对应数字相加的结果。

 

示例 1：

输入：num = 4
输出：2
解释：
只有 2 和 4 满足小于等于 4 且各位数字之和为偶数。
示例 2：

输入：num = 30
输出：14
解释：
只有 14 个整数满足小于等于 30 且各位数字之和为偶数，分别是：
2、4、6、8、11、13、15、17、19、20、22、24、26 和 28 。
 

提示：

1 <= num <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-integers-with-even-digit-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countEven(int num) {
        if (num < 10) {
            return num / 2;
        }

        int count = num / 10 * 10 / 2 - 1, tmp = num, sum = 0;  // 每10个数里面，有5个位和为偶数，5个位和为奇数，把数字0排除

        while (tmp != 0) {
            sum += (tmp % 10);
            tmp /= 10;
        }

        return count + (num % 10 + 1) / 2 + ((num % 2) == 0 && (sum % 2) == 0 ? 1 : 0);  // 计算最后不满10个的数
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.countEven(1));
    check.checkInt(2, o.countEven(4));
    check.checkInt(14, o.countEven(30));
    check.checkInt(4, o.countEven(10));
    check.checkInt(5, o.countEven(11));
    check.checkInt(14, o.countEven(28));
    check.checkInt(14, o.countEven(29));
    check.checkInt(49, o.countEven(100));
    check.checkInt(50, o.countEven(101));
    check.checkInt(499, o.countEven(999));
    check.checkInt(499, o.countEven(1000));
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
