/* 贴纸拼词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。

您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。

返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。

注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的，并且 target 被选择为两个随机单词的连接。

 

示例 1：

输入： stickers = ["with","example","science"], target = "thehat"
输出：3
解释：
我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
此外，这是形成目标字符串所需的最小贴纸数量。
示例 2:

输入：stickers = ["notice","possible"], target = "basicbasic"
输出：-1
解释：我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
 

提示:

n == stickers.length
1 <= n <= 50
1 <= stickers[i].length <= 10
1 <= target <= 15
stickers[i] 和 target 由小写英文单词组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/stickers-to-spell-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int size = target.size(), maxMask = (1 << size), inf = 1000000000;
        vector<int> leastStickers(maxMask, inf);
        leastStickers[0] = 0;

        preprocess(stickers, target);

        for (int mask = 1; mask < maxMask; ++mask) {
            for (string& sticker : stickers) {  // 用sticker覆盖一部分，看剩下的还需要多少
                leastStickers[mask] = min(leastStickers[mask], 1 + leastStickers[getNextMask(target, sticker, mask)]);
            }
        }

        return leastStickers[maxMask - 1] >= inf ? -1 : leastStickers[maxMask - 1];
    }

    void preprocess(vector<string>& stickers, string& target) {  // 排序之后利于双指针求交集
        sort(target.begin(), target.end());

        for (string& sticker : stickers) {
            sort(sticker.begin(), sticker.end());
        }
    }

    int getNextMask(string& target, string& sticker, int mask) {
        int i, j = 0, bit, size = target.size(), size1 = sticker.size(), nextMask = mask;

        for (i = 0, bit = 1; i < size; ++i, bit <<= 1) {  // 双指针求target和sticker的交集
            if ((mask & bit) != 0) {
                while (j < size1 && sticker[j] < target[i]) {  // 小于target的字符不再需要
                    ++j;
                }

                if (j < size1 && sticker[j] == target[i]) {  // 匹配上了，j移到下一个位置，mask屏蔽掉该位
                    ++j;
                    nextMask ^= bit;
                }
            }
        }

        return nextMask;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> stickers = { "with","example","science" };
    check.checkInt(3, o.minStickers(stickers, "thehat"));

    stickers = { "notice","possible" };
    check.checkInt(-1, o.minStickers(stickers, "basicbasic"));

    stickers = { "fly","me","charge","mind","bottom" };
    check.checkInt(4, o.minStickers(stickers, "centorder"));
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
