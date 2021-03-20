/* 卡车上的最大单元数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你将一些箱子装在 一辆卡车 上。给你一个二维数组 boxTypes ，其中 boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi] ：

numberOfBoxesi 是类型 i 的箱子的数量。
numberOfUnitsPerBoxi 是类型 i 每个箱子可以装载的单元数量。
整数 truckSize 表示卡车上可以装载 箱子 的 最大数量 。只要箱子数量不超过 truckSize ，你就可以选择任意箱子装到卡车上。

返回卡车可以装载 单元 的 最大 总数。

 

示例 1：

输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
输出：8
解释：箱子的情况如下：
- 1 个第一类的箱子，里面含 3 个单元。
- 2 个第二类的箱子，每个里面含 2 个单元。
- 3 个第三类的箱子，每个里面含 1 个单元。
可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
示例 2：

输入：boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
输出：91
 

提示：

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-units-on-a-truck
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> units(1001, 0);
        int maxUnits = 0, boxesLeft = truckSize;

        for (auto& type : boxTypes) {
            units[type[1]] += type[0];
        }

        for (int i = 1000; i >= 0; --i) {
            if (units[i] <= boxesLeft) {
                maxUnits += (units[i] * i);
                boxesLeft -= units[i];
            }
            else {
                maxUnits += (boxesLeft * i);
                break;
            }
        }

        return maxUnits;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> boxTypes = { {1,3},{2,2},{3,1} };
    check.checkInt(8, o.maximumUnits(boxTypes, 4));

    boxTypes = { {5,10},{2,5},{4,7},{3,9} };
    check.checkInt(91, o.maximumUnits(boxTypes, 10));

    boxTypes = { {1,1} };
    check.checkInt(1, o.maximumUnits(boxTypes, 1));
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
