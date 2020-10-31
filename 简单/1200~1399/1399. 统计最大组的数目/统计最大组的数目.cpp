/* 统计最大组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 。请你先求出从 1 到 n 的每个整数 10 进制表示下的数位和（每一位上的数字相加），然后把数位和相等的数字放到同一个组中。

请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。

 

示例 1：

输入：n = 13
输出：4
解释：总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
[1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。
示例 2：

输入：n = 2
输出：2
解释：总共有 2 个大小为 1 的组 [1]，[2]。
示例 3：

输入：n = 15
输出：6
示例 4：

输入：n = 24
输出：5
 

提示：

1 <= n <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-largest-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        int i, maxCount = 0, sumDigitsCount[37]{};  // 最大的数位和是4*9=36
        for (i = 1; i <= n; i++) {
            sumDigitsCount[sumOfDigits(i)]++;
        }

        unordered_map<int, int> sameSumDigitsCount;
        for (i = 1; i < 37; i++) {
            int count = sumDigitsCount[i];
            if (count == 0) {
                continue;
            }

            maxCount = max(maxCount, count);
            auto iter = sameSumDigitsCount.find(count);
            if (iter == sameSumDigitsCount.end()) {
                sameSumDigitsCount[count] = 1;
            }
            else {
                iter->second++;
            }
        }

        return sameSumDigitsCount[maxCount];
    }

    int sumOfDigits(int n) {
        int sum = 0;

        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.countLargestGroup(13));
    check.checkInt(2, o.countLargestGroup(2));
    check.checkInt(6, o.countLargestGroup(15));
    check.checkInt(5, o.countLargestGroup(24));
    check.checkInt(1, o.countLargestGroup(1));
    check.checkInt(9, o.countLargestGroup(9));
    check.checkInt(1, o.countLargestGroup(10));
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
