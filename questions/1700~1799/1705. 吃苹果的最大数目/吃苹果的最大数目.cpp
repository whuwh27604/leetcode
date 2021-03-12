/* 吃苹果的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一棵特殊的苹果树，一连 n 天，每天都可以长出若干个苹果。在第 i 天，树上会长出 apples[i] 个苹果，这些苹果将会在 days[i] 天后（也就是说，第 i + days[i] 天时）腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 apples[i] == 0 且 days[i] == 0 表示。

你打算每天 最多 吃一个苹果来保证营养均衡。注意，你可以在这 n 天之后继续吃苹果。

给你两个长度为 n 的整数数组 days 和 apples ，返回你可以吃掉的苹果的最大数目。

 

示例 1：

输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
输出：7
解释：你可以吃掉 7 个苹果：
- 第一天，你吃掉第一天长出来的苹果。
- 第二天，你吃掉一个第二天长出来的苹果。
- 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
- 第四天到第七天，你吃的都是第四天长出来的苹果。
示例 2：

输入：apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
输出：5
解释：你可以吃掉 5 个苹果：
- 第一天到第三天，你吃的都是第一天长出来的苹果。
- 第四天和第五天不吃苹果。
- 第六天和第七天，你吃的都是第六天长出来的苹果。
 

提示：

apples.length == n
days.length == n
1 <= n <= 2 * 104
0 <= apples[i], days[i] <= 2 * 104
只有在 apples[i] = 0 时，days[i] = 0 才成立

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-eaten-apples
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        multimap<int, int> grownApples;
        int day = 0, size = apples.size(), eatApples = 0;

        do {
            if (day < size && apples[day] != 0) {  // 每天干三件事情：1、把新长出来的苹果按照过期时间放入队列
                grownApples.insert({ day + days[day], apples[day] });
            }

            while (!grownApples.empty() && grownApples.begin()->first <= day) {  // 把已经过期的苹果扔掉
                grownApples.erase(grownApples.begin());
            }

            if (!grownApples.empty()) {  // 如果还有苹果，就吃一个
                ++eatApples;
                if (--grownApples.begin()->second == 0) {
                    grownApples.erase(grownApples.begin());
                }
            }

            ++day;
        } while (day < size || !grownApples.empty());

        return eatApples;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> apples = { 1,2,3,5,2 };
    vector<int> days = { 3,2,1,4,2 };
    check.checkInt(7, o.eatenApples(apples, days));

    apples = { 3,0,0,0,0,2 };
    days = { 3,0,0,0,0,2 };
    check.checkInt(5, o.eatenApples(apples, days));

    apples = { 3,3,2 };
    days = { 8,4,3 };
    check.checkInt(7, o.eatenApples(apples, days));

    apples = { 3,3,0,0,0,2 };
    days = { 2,1,0,0,0,100 };
    check.checkInt(4, o.eatenApples(apples, days));

    apples = { 9,24,5,12,15,21,13,12,28,0,21,6,0,26,20,0,21,21,7,0,19,25,0,30,32,32,0,0,0,22,0,11,2,27,16,0,15,12,14,33,10,11,0,13,11,0,27,0,0,14,20,11,0,22,10,1,22,6,0,13,31,33,30,27,2,30,18 };
    days = { 3,48,2,21,20,13,25,9,20,0,34,6,0,33,38,0,42,24,9,0,20,38,0,30,52,22,0,0,0,27,0,22,2,53,8,0,10,18,1,62,20,15,0,9,13,0,28,0,0,24,2,2,0,9,3,2,1,2,0,15,46,58,37,12,1,28,29 };
    check.checkInt(119, o.eatenApples(apples, days));
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
