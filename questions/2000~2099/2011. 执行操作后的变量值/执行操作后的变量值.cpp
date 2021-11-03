/* 执行操作后的变量值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
存在一种仅支持 4 种操作和 1 个变量 X 的编程语言：

++X 和 X++ 使变量 X 的值 加 1
--X 和 X-- 使变量 X 的值 减 1
最初，X 的值是 0

给你一个字符串数组 operations ，这是由操作组成的一个列表，返回执行所有操作后， X 的 最终值 。

 

示例 1：

输入：operations = ["--X","X++","X++"]
输出：1
解释：操作按下述步骤执行：
最初，X = 0
--X：X 减 1 ，X =  0 - 1 = -1
X++：X 加 1 ，X = -1 + 1 =  0
X++：X 加 1 ，X =  0 + 1 =  1
示例 2：

输入：operations = ["++X","++X","X++"]
输出：3
解释：操作按下述步骤执行：
最初，X = 0
++X：X 加 1 ，X = 0 + 1 = 1
++X：X 加 1 ，X = 1 + 1 = 2
X++：X 加 1 ，X = 2 + 1 = 3
示例 3：

输入：operations = ["X++","++X","--X","X--"]
输出：0
解释：操作按下述步骤执行：
最初，X = 0
X++：X 加 1 ，X = 0 + 1 = 1
++X：X 加 1 ，X = 1 + 1 = 2
--X：X 减 1 ，X = 2 - 1 = 1
X--：X 减 1 ，X = 1 - 1 = 0
 

提示：

1 <= operations.length <= 100
operations[i] 将会是 "++X"、"X++"、"--X" 或 "X--"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/final-value-of-variable-after-performing-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int value = 0;

        for (string& oper : operations) {
            oper[1] == '+' ? ++value : --value;
        }

        return value;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> operations = { "--X","X++","X++" };
    check.checkInt(1, o.finalValueAfterOperations(operations));

    operations = { "++X","++X","X++" };
    check.checkInt(3, o.finalValueAfterOperations(operations));

    operations = { "X++","++X","--X","X--" };
    check.checkInt(0, o.finalValueAfterOperations(operations));
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
