/* 在LR字符串中交换相邻字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回True。

 

示例 :

输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
输出: True
解释:
我们可以通过以下几步将start转换成end:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
 

提示：

1 <= len(start) = len(end) <= 10000。
start和end中的字符串仅限于'L', 'R'和'X'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-adjacent-in-lr-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        /* 1、L只能往左移，R只能往右移，XXXLRXXX最后可以转变为LXXXXXXR；而XXXRLXXX无法变动。可以看出，在源、目标里面LR的相对顺序保持完全一致
           2、只能XXLX变为XLXX，不能XLXX变为XXLX，所以目标字符串里面L一定要在源左边，R一定要在源右边 */
        int indexS = 0, indexE = 0, size = start.size();

        while (true) {
            while ((indexS < size) && (start[indexS] == 'X')) {
                indexS++;
            }

            while ((indexE < size) && (end[indexE] == 'X')) {
                indexE++;
            }

            if ((indexS == size) && (indexE == size)) {
                return true;
            }

            if (((indexS == size) && (indexE != size)) || ((indexS != size) && (indexE == size))) {
                return false;  // LR在源、目的的个数不一样
            }

            if (start[indexS] != end[indexE]) {
                return false;  // LR在源、目的的顺序不一样
            }

            if (((start[indexS] == 'L') && (indexS < indexE)) || ((start[indexS] == 'R') && (indexS > indexE))) {
                return false;  // L更靠左，R更靠右，在目的的位置不可达
            }

            indexS++;
            indexE++;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.canTransform("RXXLRXRXL", "XRLXXRRLX"));
    check.checkBool(true, o.canTransform("R", "R"));
    check.checkBool(false, o.canTransform("R", "L"));
    check.checkBool(false, o.canTransform("R", "X"));
    check.checkBool(true, o.canTransform("XXXLRXXX", "LXXXXXXR"));
    check.checkBool(false, o.canTransform("XXXLRLXXX", "XXXRLXXX"));
    check.checkBool(false, o.canTransform("XLXX", "XXLX"));
    check.checkBool(true, o.canTransform("XXXLRX", "XXXLXR"));
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
