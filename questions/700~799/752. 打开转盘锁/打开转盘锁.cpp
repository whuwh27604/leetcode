/* 打开转盘锁.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

 

示例 1:

输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:

输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:

输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:

输入: deadends = ["0000"], target = "8888"
输出：-1
 

提示：

死亡列表 deadends 的长度范围为 [1, 500]。
目标数字 target 不会在 deadends 之中。
每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/open-the-lock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> seen;
        unordered_set<string> deadNums;
        hashDeadNums(deadends, deadNums);
        queue<string> nums;
        nums.push("0000");
        int round = 0;

        while (!nums.empty()) {
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                string num = nums.front();
                nums.pop();

                if (num == target) {
                    return round;
                }

                if (deadNums.find(num) != deadNums.end()) {
                    continue;
                }

                for (int j = 0; j < 8; j++) {
                    string next = num;
                    nextNum(next, j);

                    if (seen.find(next) == seen.end()) {
                        seen.insert(next);
                        nums.push(next);
                    }
                }
            }

            round++;
        }

        return -1;
    }

    void hashDeadNums(vector<string>& deadends, unordered_set<string>& deadNums) {
        for (string& deadNum : deadends) {
            deadNums.insert(deadNum);
        }
    }

    void nextNum(string& num, int index) {
        switch (index) {
        case 0:
            num[0] = (num[0] == '9') ? '0' : num[0] + 1;
            break;
        case 1:
            num[0] = (num[0] == '0') ? '9' : num[0] - 1;
            break;
        case 2:
            num[1] = (num[1] == '9') ? '0' : num[1] + 1;
            break;
        case 3:
            num[1] = (num[1] == '0') ? '9' : num[1] - 1;
            break;
        case 4:
            num[2] = (num[2] == '9') ? '0' : num[2] + 1;
            break;
        case 5:
            num[2] = (num[2] == '0') ? '9' : num[2] - 1;
            break;
        case 6:
            num[3] = (num[3] == '9') ? '0' : num[3] + 1;
            break;
        case 7:
            num[3] = (num[3] == '0') ? '9' : num[3] - 1;
            break;
        default:
            break;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> deadends = { "0201","0101","0102","1212","2002" };
    check.checkInt(6, o.openLock(deadends, "0202"));

    deadends = { "8888" };
    check.checkInt(1, o.openLock(deadends, "0009"));

    deadends = { "0000" };
    check.checkInt(-1, o.openLock(deadends, "8888"));

    deadends = { "8887","8889","8878","8898","8788","8988","7888","9888" };
    check.checkInt(-1, o.openLock(deadends, "8888"));

    deadends = { "1202","9202","0302","0102","0212","0292","0203","1201","9201","0301", "0101","0211","0291","0200" };
    check.checkInt(-1, o.openLock(deadends, "0202"));

    deadends = { "0100","0010","0001","9000","0900","0090","0009","1100","1010","1001","1900","1090","1009","2000" };
    check.checkInt(-1, o.openLock(deadends, "0400"));
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
