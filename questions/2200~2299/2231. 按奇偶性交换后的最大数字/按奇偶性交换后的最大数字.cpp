/* 按奇偶性交换后的最大数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 num 。你可以交换 num 中 奇偶性 相同的任意两位数字（即，都是奇数或者偶数）。

返回交换 任意 次之后 num 的 最大 可能值。

 

示例 1：

输入：num = 1234
输出：3412
解释：交换数字 3 和数字 1 ，结果得到 3214 。
交换数字 2 和数字 4 ，结果得到 3412 。
注意，可能存在其他交换序列，但是可以证明 3412 是最大可能值。
注意，不能交换数字 4 和数字 1 ，因为它们奇偶性不同。
示例 2：

输入：num = 65875
输出：87655
解释：交换数字 8 和数字 6 ，结果得到 85675 。
交换数字 5 和数字 7 ，结果得到 87655 。
注意，可能存在其他交换序列，但是可以证明 87655 是最大可能值。
 

提示：

1 <= num <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number-after-digit-swaps-by-parity
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int size = s.size();
        
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if ((s[i] < s[j]) && ((s[i] % 2) ^ (s[j] % 2)) == 0) {
                    swap(s[i], s[j]);
                }
            }
        }

        return stoi(s);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3412, o.largestInteger(1234));
    check.checkInt(87655, o.largestInteger(65875));
    check.checkInt(1, o.largestInteger(1));
    check.checkInt(12, o.largestInteger(12));
    check.checkInt(987642301, o.largestInteger(123406789));
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
