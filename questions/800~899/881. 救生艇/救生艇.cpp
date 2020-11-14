/* 救生艇.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。

每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。

返回载到每一个人所需的最小船数。(保证每个人都能被船载)。

 

示例 1：

输入：people = [1,2], limit = 3
输出：1
解释：1 艘船载 (1, 2)
示例 2：

输入：people = [3,2,2,1], limit = 3
输出：3
解释：3 艘船分别载 (1, 2), (2) 和 (3)
示例 3：

输入：people = [3,5,3,4], limit = 5
输出：4
解释：4 艘船分别载 (3), (3), (4), (5)
提示：

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/boats-to-save-people
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /* 假设排序后为W1,W2...Wp...Wq...Wx...Wy...Wn-2,Wn-1，按照贪心策略，Wn-1+Wp=limit，Wn-2+Wq=limit，...Wy+Wx=limit，可以配对的个数是min([W1,Wx],[Wy,Wn-1])
           简化策略，直接(Wn-1,W1),(Wn-2,W2)...配对，最终可能的相遇点还是由(Wx,Wy)决定，可以配对的个数仍然是min([W1,Wx],[Wy,Wn-1])。所以可以简化策略 */
        sort(people.begin(), people.end());

        int size = people.size(), left = 0, right = size - 1, boats = 0;

        while (left < right) {
            if (people[left] + people[right] > limit) {
                --right;
            }
            else {
                ++left;
                --right;
            }

            ++boats;
        }

        return (left == right) ? boats + 1 : boats;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> people = { 1,2 };
    check.checkInt(1, o.numRescueBoats(people, 3));

    people = { 3,2,2,1 };
    check.checkInt(3, o.numRescueBoats(people, 3));

    people = { 3,5,3,4 };
    check.checkInt(4, o.numRescueBoats(people, 5));
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
