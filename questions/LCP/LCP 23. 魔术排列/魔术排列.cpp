/* 魔术排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
秋日市集上，魔术师邀请小扣与他互动。魔术师的道具为分别写有数字 1~N 的 N 张卡牌，然后请小扣思考一个 N 张卡牌的排列 target。

魔术师的目标是找到一个数字 k（k >= 1），使得初始排列顺序为 1~N 的卡牌经过特殊的洗牌方式最终变成小扣所想的排列 target，特殊的洗牌方式为：

第一步，魔术师将当前位于 偶数位置 的卡牌（下标自 1 开始），保持 当前排列顺序 放在位于 奇数位置 的卡牌之前。例如：将当前排列 [1,2,3,4,5] 位于偶数位置的 [2,4] 置于奇数位置的 [1,3,5] 前，排列变为 [2,4,1,3,5]；
第二步，若当前卡牌数量小于等于 k，则魔术师按排列顺序取走全部卡牌；若当前卡牌数量大于 k，则取走前 k 张卡牌，剩余卡牌继续重复这两个步骤，直至所有卡牌全部被取走；
卡牌按照魔术师取走顺序构成的新排列为「魔术取数排列」，请返回是否存在这个数字 k 使得「魔术取数排列」恰好就是 target，从而让小扣感到大吃一惊。

示例 1：

输入：target = [2,4,3,1,5]

输出：true

解释：排列 target 长度为 5，初始排列为：1,2,3,4,5。我们选择 k = 2：
第一次：将当前排列 [1,2,3,4,5] 位于偶数位置的 [2,4] 置于奇数位置的 [1,3,5] 前，排列变为 [2,4,1,3,5]。取走前 2 张卡牌 2,4，剩余 [1,3,5]；
第二次：将当前排列 [1,3,5] 位于偶数位置的 [3] 置于奇数位置的 [1,5] 前，排列变为 [3,1,5]。取走前 2 张 3,1，剩余 [5]；
第三次：当前排列为 [5]，全部取出。
最后，数字按照取出顺序构成的「魔术取数排列」2,4,3,1,5 恰好为 target。

示例 2：

输入：target = [5,4,3,2,1]

输出：false

解释：无法找到一个数字 k 可以使「魔术取数排列」恰好为 target。

提示：

1 <= target.length = N <= 5000
题目保证 target 是 1~N 的一个排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er94lq
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isMagic(vector<int>& target) {
        int n = target.size();
        vector<int> cards(n);
        firstShuffle(cards, n);

        int k = getK(target, cards, n);
        if (k == 0) {
            return false;
        }

        int start = k;
        while (start < n) {
            if (!shuffle(target, cards, n, k, start)) {
                return false;
            }

            start += k;
        }

        return true;
    }

    void firstShuffle(vector<int>& cards, int n) {
        int i = 0, card;

        for (card = 2; card <= n; card += 2) {
            cards[i++] = card;
        }

        for (card = 1; card <= n; card += 2) {
            cards[i++] = card;
        }
    }

    int getK(vector<int>& target, vector<int>& cards, int n) {
        int k;

        /* target和cards的公共前缀长度是len，那么len就是k。假设target是A1,A2...Ai,Ai+1,Ai+2...Ak-1,Ak,T1,T2...，cards是A1,A2...Ai,Ai+1,Ai+2...Ak-1,Ak,C1,C2...
           1、显然k不能比len大，假设k=len+1，那么第一次洗牌后，就会拿A1,A2...Ak-1,Ak,C1，最终结果不可能是A1,A2...Ak-1,Ak,T1
           2、k也不能比len小，假设k=i，i<len，那么第一轮结束后拿走了A1,A2...Ai，此时从Ai+1开始第二轮，显然Ai+2会排到第一个，最终结果只能是A1,A2...Ai,Ai+2...不等于target */
        for (k = 0; k < n && target[k] == cards[k]; ++k) {}

        return k;
    }

    bool shuffle(vector<int>& target, vector<int>& cards, int n, int k, int start) {
        vector<int> tmp(n - start);
        int i, j = 0;

        for (i = start + 1; i < n; i += 2) {
            tmp[j++] = cards[i];
        }

        for (i = start; i < n; i += 2) {
            tmp[j++] = cards[i];
        }

        for (j = 0; j < n - start; ++j) {
            if (j < k && tmp[j] != target[start + j]) {
                return false;
            }

            cards[start + j] = tmp[j];
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> target = { 2,4,3,1,5 };
    check.checkBool(true, o.isMagic(target));

    target = { 2,4,1,5,3 };
    check.checkBool(true, o.isMagic(target));

    target = { 5,4,3,2,1 };
    check.checkBool(false, o.isMagic(target));

    target = { 1 };
    check.checkBool(true, o.isMagic(target));

    target = { 1,2 };
    check.checkBool(false, o.isMagic(target));

    target = { 2,1 };
    check.checkBool(true, o.isMagic(target));

    target = { 2,4,6,8,1,7,3,5 };
    check.checkBool(false, o.isMagic(target));

    target = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,55,59,63,67,53,57,61,65,69 };
    check.checkBool(true, o.isMagic(target));
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
