/* 宝石补给.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣新手村，在开始试炼之前，请各位勇者先进行「宝石补给」。

每位勇者初始都拥有一些能量宝石， gem[i] 表示第 i 位勇者的宝石数量。现在这些勇者们进行了一系列的赠送，operations[j] = [x, y] 表示在第 j 次的赠送中 第 x 位勇者将自己一半的宝石（需向下取整）赠送给第 y 位勇者。

在完成所有的赠送后，请找到拥有最多宝石的勇者和拥有最少宝石的勇者，并返回他们二者的宝石数量之差。

注意：

赠送将按顺序逐步进行。
示例 1：

输入：gem = [3,1,2], operations = [[0,2],[2,1],[2,0]]

输出：2

解释：
第 1 次操作，勇者 0 将一半的宝石赠送给勇者 2， gem = [2,1,3]
第 2 次操作，勇者 2 将一半的宝石赠送给勇者 1， gem = [2,2,2]
第 3 次操作，勇者 2 将一半的宝石赠送给勇者 0， gem = [3,2,1]
返回 3 - 1 = 2

示例 2：

输入：gem = [100,0,50,100], operations = [[0,2],[0,1],[3,0],[3,0]]

输出：75

解释：
第 1 次操作，勇者 0 将一半的宝石赠送给勇者 2， gem = [50,0,100,100]
第 2 次操作，勇者 0 将一半的宝石赠送给勇者 1， gem = [25,25,100,100]
第 3 次操作，勇者 3 将一半的宝石赠送给勇者 0， gem = [75,25,100,50]
第 4 次操作，勇者 3 将一半的宝石赠送给勇者 0， gem = [100,25,100,25]
返回 100 - 25 = 75

示例 3：

输入：gem = [0,0,0,0], operations = [[1,2],[3,1],[1,2]]

输出：0

提示：

2 <= gem.length <= 10^3
0 <= gem[i] <= 10^3
0 <= operations.length <= 10^4
operations[i].length == 2
0 <= operations[i][0], operations[i][1] < gem.length

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/WHnhjV
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& oper : operations) {
            int half = gem[oper[0]] / 2;
            gem[oper[0]] -= half;
            gem[oper[1]] += half;
        }

        return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> gem = { 3,1,2 };
    vector<vector<int>> operations = { {0,2},{2,1},{2,0} };
    check.checkInt(2, o.giveGem(gem, operations));

    gem = { 100,0,50,100 };
    operations = { {0,2},{0,1},{3,0},{3,0} };
    check.checkInt(75, o.giveGem(gem, operations));

    gem = { 0,0,0,0 };
    operations = { {1,2},{3,1},{1,2} };
    check.checkInt(0, o.giveGem(gem, operations));
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
