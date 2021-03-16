/* 文件夹操作日志搜集器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
每当用户执行变更文件夹操作时，LeetCode 文件系统都会保存一条日志记录。

下面给出对变更操作的说明：

"../" ：移动到当前文件夹的父文件夹。如果已经在主文件夹下，则 继续停留在当前文件夹 。
"./" ：继续停留在当前文件夹。
"x/" ：移动到名为 x 的子文件夹中。题目数据 保证总是存在文件夹 x 。
给你一个字符串列表 logs ，其中 logs[i] 是用户在 ith 步执行的操作。

文件系统启动时位于主文件夹，然后执行 logs 中的操作。

执行完所有变更文件夹操作后，请你找出 返回主文件夹所需的最小步数 。

 

示例 1：



输入：logs = ["d1/","d2/","../","d21/","./"]
输出：2
解释：执行 "../" 操作变更文件夹 2 次，即可回到主文件夹
示例 2：



输入：logs = ["d1/","d2/","./","d3/","../","d31/"]
输出：3
示例 3：

输入：logs = ["d1/","../","../","../"]
输出：0
 

提示：

1 <= logs.length <= 103
2 <= logs[i].length <= 10
logs[i] 包含小写英文字母，数字，'.' 和 '/'
logs[i] 符合语句中描述的格式
文件夹名称由小写英文字母和数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/crawler-log-folder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for (string& operation : logs) {
            if (operation == "./") {

            }
            else if (operation == "../") {
                if (depth > 0) {
                    --depth;
                }
            }
            else {
                ++depth;
            }
        }

        return depth;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> logs = { "d1/","d2/","../","d21/","./" };
    check.checkInt(2, o.minOperations(logs));

    logs = { "d1/","d2/","./","d3/","../","d31/" };
    check.checkInt(3, o.minOperations(logs));

    logs = { "d1/","../","../","../" };
    check.checkInt(0, o.minOperations(logs));

    logs = { "d1/" };
    check.checkInt(1, o.minOperations(logs));

    logs = { "./","../","./" };
    check.checkInt(0, o.minOperations(logs));
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
