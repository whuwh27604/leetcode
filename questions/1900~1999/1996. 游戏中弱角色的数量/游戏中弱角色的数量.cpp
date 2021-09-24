/* 游戏中弱角色的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。给你一个二维整数数组 properties ，其中 properties[i] = [attacki, defensei] 表示游戏中第 i 个角色的属性。

如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，则认为该角色为 弱角色 。更正式地，如果认为角色 i 弱于 存在的另一个角色 j ，那么 attackj > attacki 且 defensej > defensei 。

返回 弱角色 的数量。

 

示例 1：

输入：properties = [[5,5],[6,3],[3,6]]
输出：0
解释：不存在攻击和防御都严格高于其他角色的角色。
示例 2：

输入：properties = [[2,2],[3,3]]
输出：1
解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
示例 3：

输入：properties = [[1,5],[10,4],[4,3]]
输出：1
解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
 

提示：

2 <= properties.length <= 105
properties[i].length == 2
1 <= attacki, defensei <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return (v1[0] > v2[0]) || ((v1[0] == v2[0]) && (v1[1] < v2[1]));  // 先按attack排序，大的排前面；如果attack相等，则defense小的排前面
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxDefense = 0, weakers = 0;

        sort(properties.begin(), properties.end(), vectorCompare);

        for (auto& property : properties) {
            if (property[1] < maxDefense) {
                ++weakers;
            }

            maxDefense = max(maxDefense, property[1]);
        }

        return weakers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> properties = { {5,5},{6,3},{3,6} };
    check.checkInt(0, o.numberOfWeakCharacters(properties));

    properties = { {2,2},{3,3} };
    check.checkInt(1, o.numberOfWeakCharacters(properties));

    properties = { {2,3},{3,2} };
    check.checkInt(0, o.numberOfWeakCharacters(properties));

    properties = { {1,5},{10,4},{4,3} };
    check.checkInt(1, o.numberOfWeakCharacters(properties));

    properties = { {1,5},{10,4},{4,3},{1,5},{10,4},{4,3},{1,5},{10,4},{4,3},{1,5},{10,4},{4,3},{1,5},{10,4},{4,3},{1,5},{10,4},{4,3} };
    check.checkInt(6, o.numberOfWeakCharacters(properties));
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
