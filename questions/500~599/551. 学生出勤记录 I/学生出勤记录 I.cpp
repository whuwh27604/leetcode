/* 学生出勤记录 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

你需要根据这个学生的出勤记录判断他是否会被奖赏。

示例 1:

输入: "PPALLP"
输出: True
示例 2:

输入: "PPALLL"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/student-attendance-record-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, countL = 0;

        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                countL = 0;
                countA++;
                if (countA > 1) {
                    return false;
                }
            }
            else if (s[i] == 'L') {
                countL++;
                if (countL > 2) {
                    return false;
                }
            }
            else {
                countL = 0;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.checkRecord("PPALLP"));
    check.checkBool(false, o.checkRecord("PPALLL"));
    check.checkBool(false, o.checkRecord("AA"));
    check.checkBool(false, o.checkRecord("APPPA"));
    check.checkBool(false, o.checkRecord("LLL"));
    check.checkBool(true, o.checkRecord(""));
    check.checkBool(true, o.checkRecord("A"));
    check.checkBool(true, o.checkRecord("AL"));
    check.checkBool(true, o.checkRecord("ALL"));
    check.checkBool(true, o.checkRecord("ALLPL"));
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
