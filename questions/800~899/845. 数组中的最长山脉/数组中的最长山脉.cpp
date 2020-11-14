/* 数组中的最长山脉.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：

B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）

给出一个整数数组 A，返回最长 “山脉” 的长度。

如果不含有 “山脉” 则返回 0。

 

示例 1：

输入：[2,1,4,7,3,2,5]
输出：5
解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
示例 2：

输入：[2,2,2]
输出：0
解释：不含 “山脉”。
 

提示：

0 <= A.length <= 10000
0 <= A[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-mountain-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i, size = A.size(), length = 0, maxLength = 0, state = STATE_NONE;
        if (size < 3) {
            return 0;
        }

        for (i = 1; i < size; ++i) {
            if (A[i] == A[i - 1]) {
                if (state == STATE_DECREASING) {
                    maxLength = max(maxLength, length);
                }
                length = 0;
                state = STATE_NONE;
            }
            else if (A[i] > A[i - 1]) {
                if (state == STATE_DECREASING) {
                    maxLength = max(maxLength, length);
                    length = 2;
                }
                else if (state == STATE_NONE) {
                    length = 2;
                }
                else {
                    length++;
                }
                state = STATE_INCREASING;
            }
            else {
                if (state != STATE_NONE) {
                    length++;
                    state = STATE_DECREASING;
                }
            }
        }

        return state == STATE_DECREASING ? max(maxLength, length) : maxLength;
    }

private:
    static const int STATE_NONE = 0;
    static const int STATE_INCREASING = 1;
    static const int STATE_DECREASING = 2;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 2,1,4,7,3,2,5 };
    check.checkInt(5, o.longestMountain(A));

    A = { 2,2,2 };
    check.checkInt(0, o.longestMountain(A));

    A = {  };
    check.checkInt(0, o.longestMountain(A));

    A = { 1,2,1,0 };
    check.checkInt(4, o.longestMountain(A));

    A = { 0,1,2,3,4,5,6,7,8,9 };
    check.checkInt(0, o.longestMountain(A));
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
