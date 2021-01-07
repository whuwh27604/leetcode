/* 旋转数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。

如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。

现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

 

示例：

输入: 10
输出: 4
解释:
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
 

提示：

N 的取值范围是 [1, 10000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotated-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int sum = 0;
        for (int i = 2; i <= N; i++) {
            if (isGoodNumber(i)) {
                sum++;
            }
        }

        return sum;
    }

    bool isGoodNumber(int n) {
        bool result = false;
        while (n != 0) {
            int remainder = (n % 10);
            if ((remainder == 3) || (remainder == 4) || (remainder == 7)) {
                return false;
            }
            else if ((remainder == 2) || (remainder == 5) || (remainder == 6) || (remainder == 9)) {
                result = true;
            }

            n /= 10;
        }

        return result;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.rotatedDigits(10));
    check.checkInt(0, o.rotatedDigits(1));
    check.checkInt(1, o.rotatedDigits(2));
    check.checkInt(1, o.rotatedDigits(3));
    check.checkInt(1, o.rotatedDigits(4));
    check.checkInt(2, o.rotatedDigits(5));
    check.checkInt(3, o.rotatedDigits(6));
    check.checkInt(3, o.rotatedDigits(7));
    check.checkInt(3, o.rotatedDigits(8));
    check.checkInt(4, o.rotatedDigits(9));
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
