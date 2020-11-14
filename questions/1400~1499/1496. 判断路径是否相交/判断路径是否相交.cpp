/* 判断路径是否相交.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。

机器人从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。

如果路径在任何位置上出现相交的情况，也就是走到之前已经走过的位置，请返回 True ；否则，返回 False 。

 

示例 1：



输入：path = "NES"
输出：false
解释：该路径没有在任何位置相交。
示例 2：



输入：path = "NESWW"
输出：true
解释：该路径经过原点两次。
 

提示：

1 <= path.length <= 10^4
path 仅由 {'N', 'S', 'E', 'W} 中的字符组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-crossing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<int> crossedPoints;
        crossedPoints.insert(0);
        int x = 0, y = 0;

        for (char direction : path) {
            switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            case 'E':
                x++;
                break;
            default:
                break;
            }

            int key = (x * 20001) + y;
            if (crossedPoints.find(key) != crossedPoints.end()) {
                return true;
            }

            crossedPoints.insert(key);
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(false, o.isPathCrossing("NES"));
    check.checkBool(true, o.isPathCrossing("NESWW"));
    check.checkBool(false, o.isPathCrossing("N"));
    check.checkBool(false, o.isPathCrossing("S"));
    check.checkBool(false, o.isPathCrossing("W"));
    check.checkBool(false, o.isPathCrossing("E"));
    check.checkBool(true, o.isPathCrossing("NS"));
    check.checkBool(true, o.isPathCrossing("SN"));
    check.checkBool(true, o.isPathCrossing("EW"));
    check.checkBool(true, o.isPathCrossing("WE"));
    check.checkBool(true, o.isPathCrossing("NNS"));
    check.checkBool(true, o.isPathCrossing("SSN"));
    check.checkBool(true, o.isPathCrossing("EEW"));
    check.checkBool(true, o.isPathCrossing("WWE"));
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
