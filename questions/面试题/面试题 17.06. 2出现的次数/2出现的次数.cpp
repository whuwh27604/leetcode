/* 2出现的次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个方法，计算从 0 到 n (含 n) 中数字 2 出现的次数。

示例:

输入: 25
输出: 9
解释: (2, 12, 20, 21, 22, 23, 24, 25)(注意 22 应该算作两次)
提示：

n <= 10^9
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOf2sInRange(int n) {
        int count = 0;
        n = min(n, 999999999);  // 避免整型溢出，将1000000000转换为999999999，两者的最终答案是一样的

        for (int cur = 1; cur <= n; cur *= 10) {
            int digit = n / cur % 10, left = n / (10 * cur), right = n % cur;  // 当前数位是digit，左边是left，右边是right

            count += left * cur;  // 当前位设置为2时，左边可以设置为小于left的数，即[0,left)共left个数，右边可以是[0,cur)共cur个数
            if (digit > 2) {  // digit大于等于2时，左边还可以设置为left。如果digit大于2，那么右边可以是[0,cur)共cur个数
                count += cur;
            }
            else if (digit == 2) {  // 如果digit等于2，那么右边可以是[0,right]共right + 1个数
                count += (right + 1);
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(9, o.numberOf2sInRange(25));
    check.checkInt(0, o.numberOf2sInRange(0));
    check.checkInt(0, o.numberOf2sInRange(1));
    check.checkInt(1, o.numberOf2sInRange(2));
    check.checkInt(9, o.numberOf2sInRange(25));
    check.checkInt(30399, o.numberOf2sInRange(51243));
    check.checkInt(900000000, o.numberOf2sInRange(999999999));
    check.checkInt(900000000, o.numberOf2sInRange(1000000000));
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
