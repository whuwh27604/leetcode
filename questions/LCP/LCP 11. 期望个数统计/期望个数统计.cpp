/* 期望个数统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
某互联网公司一年一度的春招开始了，一共有 n 名面试者入选。每名面试者都会提交一份简历，公司会根据提供的简历资料产生一个预估的能力值，数值越大代表越有可能通过面试。

小 A 和小 B 负责审核面试者，他们均有所有面试者的简历，并且将各自根据面试者能力值从大到小的顺序浏览。由于简历事先被打乱过，能力值相同的简历的出现顺序是从它们的全排列中等可能地取一个。现在给定 n 名面试者的能力值 scores，设 X 代表小 A 和小 B 的浏览顺序中出现在同一位置的简历数，求 X 的期望。

提示：离散的非负随机变量的期望计算公式为 。在本题中，由于 X 的取值为 0 到 n 之间，期望计算公式可以是 。

示例 1：

输入：scores = [1,2,3]

输出：3

解释：由于面试者能力值互不相同，小 A 和小 B 的浏览顺序一定是相同的。X的期望是 3 。

示例 2：

输入：scores = [1,1]

输出：1

解释：设两位面试者的编号为 0, 1。由于他们的能力值都是 1，小 A 和小 B 的浏览顺序都为从全排列 [[0,1],[1,0]] 中等可能地取一个。如果小 A 和小 B 的浏览顺序都是 [0,1] 或者 [1,0] ，那么出现在同一位置的简历数为 2 ，否则是 0 。所以 X 的期望是 (2+0+2+0) * 1/4 = 1

示例 3：

输入：scores = [1,1,2]

输出：2

限制：

1 <= scores.length <= 10^5
0 <= scores[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qi-wang-ge-shu-tong-ji
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

/* a、b两个人能力值相同，则A、B浏览的顺序可能是：abab（相同个数为2）、abba（0）、baab（0）、baba（2），每种情况的概率是1/4，总的相同的期望就是：
   2/4+0/4+0/4+2/4=1
   a、b、c三个人能力值相同，则A浏览的顺序可能是：abc、acb、bac、bca、cab、cba，B也一样，所以总共有6*6=36种可能。以A取abc为例，和B相同的期望是：
   3/36+1/36+1/36+0/36+0/36+1/36=6/36，其它情况也一样，总的期望是6*6/36=1
   根据期望公式可证其它相同个数的期望值也是1，所以问题实质就是求有多少个不同的能力值。 */
class Solution {
public:
    int expectNumber(vector<int>& scores) {
        unordered_set<int> diffScores;

        for (unsigned int i = 0; i < scores.size(); i++) {
            diffScores.insert(scores[i]);
        }

        return diffScores.size();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> scores = { 1,2,3 };
    check.checkInt(3, o.expectNumber(scores));

    scores = { 1,1 };
    check.checkInt(1, o.expectNumber(scores));

    scores = { 1,1,2 };
    check.checkInt(2, o.expectNumber(scores));

    scores = { 0 };
    check.checkInt(1, o.expectNumber(scores));
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
