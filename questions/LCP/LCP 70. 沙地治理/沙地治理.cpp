/* 沙地治理.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在力扣城的沙漠分会场展示了一种沙柳树，这种沙柳树能够将沙地转化为坚实的绿地。 展示的区域为正三角形，这片区域可以拆分为若干个子区域，每个子区域都是边长为 1 的小三角形，其中第 i 行有 2i - 1 个小三角形。

初始情况下，区域中的所有位置都为沙地，你需要指定一些子区域种植沙柳树成为绿地，以达到转化整片区域为绿地的最终目的，规则如下：

若两个子区域共用一条边，则视为相邻；
如下图所示，(1,1)和(2,2)相邻，(3,2)和(3,3)相邻；(2,2)和(3,3)不相邻，因为它们没有共用边。

若至少有两片绿地与同一片沙地相邻，则这片沙地也会转化为绿地
转化为绿地的区域会影响其相邻的沙地image.png
现要将一片边长为 size 的沙地全部转化为绿地，请找到任意一种初始指定 最少 数量子区域种植沙柳的方案，并返回所有初始种植沙柳树的绿地坐标。

示例 1：

输入：size = 3 输出：[[1,1],[2,1],[2,3],[3,1],[3,5]] 解释：如下图所示，一种方案为： 指定所示的 5 个子区域为绿地。 相邻至少两片绿地的 (2,2)，(3,2) 和 (3,4) 演变为绿地。 相邻两片绿地的 (3,3) 演变为绿地。image.png

示例 2：

输入：size = 2 输出：[[1,1],[2,1],[2,3]] 解释：如下图所示： 指定所示的 3 个子区域为绿地。 相邻三片绿地的 (2,2) 演变为绿地。image.png

提示：

1 <= size <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> sandyLandManagement(int n) {
        vector<vector<int>> ans = { {n,1} };

        if (n > 1) {
            ans.push_back({ n,n * 2 - 1 });
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= i * 2 - 1; j += 4) {
                ans.push_back({ i,j });
            }
        }

        for (int i = 4; i < n * 2 - 1; i += 8) {
            ans.push_back({ n,i });
        }

        for (int i = 7; i < n * 2 - 1; i += 8) {
            ans.push_back({ n,i });
        }

        for (int i = 9; i < n * 2 - 1; i += 8) {
            ans.push_back({ n,i });
        }

        return ans;  // 一共是 (n*n + 3n + 2) / 4 个
	}
};

int main()
{
	Solution o;
	CheckResult check;

    vector<vector<int>> actual = o.sandyLandManagement(1);
    vector<vector<int>> expected = { {1,1} };
    check.checkIntVectorVector(expected, actual);

    actual = o.sandyLandManagement(2);
    expected = { {2,1},{2,3},{1,1} };
    check.checkIntVectorVector(expected, actual);

    actual = o.sandyLandManagement(3);
    expected = { {3,1},{3,5},{1,1},{2,1},{3,4} };
    check.checkIntVectorVector(expected, actual);

    actual = o.sandyLandManagement(4);
    expected = { {4,1},{4,7},{1,1},{2,1},{3,1},{3,5},{4,4} };
    check.checkIntVectorVector(expected, actual);

    actual = o.sandyLandManagement(5);
    expected = { {5,1},{5,9},{1,1},{2,1},{3,1},{3,5},{4,1},{4,5},{5,4},{5,7} };
    check.checkIntVectorVector(expected, actual);
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
