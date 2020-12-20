/* 数青蛙.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以 croakOfFrogs 中会混合多个 “croak” 。请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。

注意：要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。

如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。

 

示例 1：

输入：croakOfFrogs = "croakcroak"
输出：1
解释：一只青蛙 “呱呱” 两次
示例 2：

输入：croakOfFrogs = "crcoakroak"
输出：2
解释：最少需要两只青蛙，“呱呱” 声用黑体标注
第一只青蛙 "crcoakroak"
第二只青蛙 "crcoakroak"
示例 3：

输入：croakOfFrogs = "croakcrook"
输出：-1
解释：给出的字符串不是 "croak" 的有效组合。
示例 4：

输入：croakOfFrogs = "croakcroa"
输出：-1
 

提示：

1 <= croakOfFrogs.length <= 10^5
字符串中的字符只有 'c', 'r', 'o', 'a' 或者 'k'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> count('r' + 1, 0);
        vector<char> prev('r' + 1);
        int minFrogs = 0;

        prev['k'] = 'a';
        prev['a'] = 'o';
        prev['o'] = 'r';
        prev['r'] = 'c';

        for (char c : croakOfFrogs) {
            ++count[c];

            if (c == 'c') {
                minFrogs = max(minFrogs, count[c]);
            }
            else {
                if (count[c] > count[prev[c]]) {
                    return -1;
                }

                if (c == 'k') {
                    --count['c'];
                    --count['r'];
                    --count['o'];
                    --count['a'];
                    --count['k'];
                }
            }
        }

        return (count['c'] == 0) ? minFrogs : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minNumberOfFrogs("croakcroak"));
    check.checkInt(2, o.minNumberOfFrogs("crcoakroak"));
    check.checkInt(-1, o.minNumberOfFrogs("croakcrook"));
    check.checkInt(-1, o.minNumberOfFrogs("croakcroa"));
    check.checkInt(-1, o.minNumberOfFrogs("coark"));
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
