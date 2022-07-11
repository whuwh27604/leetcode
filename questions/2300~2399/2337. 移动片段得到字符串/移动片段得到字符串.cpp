/* 移动片段得到字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 start 和 target ，长度均为 n 。每个字符串 仅 由字符 'L'、'R' 和 '_' 组成，其中：

字符 'L' 和 'R' 表示片段，其中片段 'L' 只有在其左侧直接存在一个 空位 时才能向 左 移动，而片段 'R' 只有在其右侧直接存在一个 空位 时才能向 右 移动。
字符 '_' 表示可以被 任意 'L' 或 'R' 片段占据的空位。
如果在移动字符串 start 中的片段任意次之后可以得到字符串 target ，返回 true ；否则，返回 false 。

 

示例 1：

输入：start = "_L__R__R_", target = "L______RR"
输出：true
解释：可以从字符串 start 获得 target ，需要进行下面的移动：
- 将第一个片段向左移动一步，字符串现在变为 "L___R__R_" 。
- 将最后一个片段向右移动一步，字符串现在变为 "L___R___R" 。
- 将第二个片段向右移动散步，字符串现在变为 "L______RR" 。
可以从字符串 start 得到 target ，所以返回 true 。
示例 2：

输入：start = "R_L_", target = "__LR"
输出：false
解释：字符串 start 中的 'R' 片段可以向右移动一步得到 "_RL_" 。
但是，在这一步之后，不存在可以移动的片段，所以无法从字符串 start 得到 target 。
示例 3：

输入：start = "_R", target = "R_"
输出：false
解释：字符串 start 中的片段只能向右移动，所以无法从字符串 start 得到 target 。
 

提示：

n == start.length == target.length
1 <= n <= 105
start 和 target 由字符 'L'、'R' 和 '_' 组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/move-pieces-to-obtain-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int size = start.size(), left = 0, right = 0, blank = 0;

        for (int i = 0; i < size; ++i) {
            start[i] == 'L' ? ++left : start[i] == 'R' ? ++right : ++blank;
            target[i] == 'L' ? --left : target[i] == 'R' ? --right : --blank;

            if ((target[i] == 'L' && right > 0)  // L无法越过R
                || (target[i] == 'R' && (left > 0 || blank > 0))  // R无法越过L和_
                || (target[i] == '_' && left > 0)) {  // _无法越过L
                return false;
            }
        }

        return left == 0 && right == 0 && blank == 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.canChange("_L__R__R_", "L______RR"));
    check.checkBool(false, o.canChange("R_L_", "__LR"));
    check.checkBool(false, o.canChange("_R", "R_"));
    check.checkBool(false, o.canChange("_R", "L_"));
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
