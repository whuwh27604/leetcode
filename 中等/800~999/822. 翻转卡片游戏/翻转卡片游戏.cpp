/* 翻转卡片游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在桌子上有 N 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。

我们可以先翻转任意张卡片，然后选择其中一张卡片。

如果选中的那张卡片背面的数字 X 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。

哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0。

其中, fronts[i] 和 backs[i] 分别代表第 i 张卡片的正面和背面的数字。

如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。

示例：

输入：fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
输出：2
解释：假设我们翻转第二张卡片，那么在正面的数变成了 [1,3,4,4,7] ， 背面的数变成了 [1,2,4,1,3]。
接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。
 

提示：

1 <= fronts.length == backs.length <= 1000
1 <= fronts[i] <= 2000
1 <= backs[i] <= 2000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/card-flipping-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        // 正反面相同的数字不能选，不同的数字都可以选，从里面选择最小的即可
        unordered_set<int> fbSames, fbDiffs;
        int i, size = backs.size(), minimun = INT_MAX;

        for (i = 0; i < size; i++) {
            if (fronts[i] == backs[i]) {
                fbSames.insert(backs[i]);
                fbDiffs.erase(backs[i]);
            }
            else {
                if (fbSames.count(fronts[i]) == 0) {
                    fbDiffs.insert(fronts[i]);
                }
                if (fbSames.count(backs[i]) == 0) {
                    fbDiffs.insert(backs[i]);
                }
            }
        }

        if (fbDiffs.empty()) {
            return 0;
        }

        for (auto iter = fbDiffs.begin(); iter != fbDiffs.end(); iter++) {
            minimun = min(minimun, *iter);
        }

        return minimun;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> fronts = { 1,2,4,4,7 };
    vector<int> backs = { 1,3,4,1,3 };
    check.checkInt(2, o.flipgame(fronts, backs));

    fronts = { 1,2,4,4,7,2,3,7 };
    backs = { 1,3,4,1,3,2,3,7 };
    check.checkInt(0, o.flipgame(fronts, backs));

    fronts = { 1 };
    backs = { 1 };
    check.checkInt(0, o.flipgame(fronts, backs));

    fronts = { 3 };
    backs = { 5 };
    check.checkInt(3, o.flipgame(fronts, backs));

    fronts = { 1,7 };
    backs = { 1,8 };
    check.checkInt(7, o.flipgame(fronts, backs));
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
