// 执行所有后缀指令.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int i, j, m = s.size();
        vector<int> instructions(m);

        for (i = 0; i < m; ++i) {
            int r = startPos[0], c = startPos[1];

            for (j = i; j < m; ++j) {
                if (s[j] == 'L') {
                    --c;
                }
                else if (s[j] == 'R') {
                    ++c;
                }
                else if (s[j] == 'U') {
                    --r;
                }
                else {
                    ++r;
                }

                if (r < 0 || r >= n || c < 0 || c >= n) {
                    break;
                }
            }

            instructions[i] = j - i;
        }

        return instructions;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> startPos = { 0,1 };
    vector<int> actual = o.executeInstructions(3, startPos, "RRDDLU");
    vector<int> expected = { 1,5,4,3,1,0 };
    check.checkIntVector(expected, actual);

    startPos = { 1,1 };
    actual = o.executeInstructions(2, startPos, "LURD");
    expected = { 4,1,0,0 };
    check.checkIntVector(expected, actual);

    startPos = { 0,0 };
    actual = o.executeInstructions(1, startPos, "LRUD");
    expected = { 0,0,0,0 };
    check.checkIntVector(expected, actual);
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
