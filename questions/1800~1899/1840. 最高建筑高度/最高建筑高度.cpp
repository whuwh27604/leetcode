// 最高建筑高度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int i, size = restrictions.size();
        if (size == 0) {
            return n - 1;
        }

        sort(restrictions.begin(), restrictions.end(), vectorCompare);

        restrictions[0][1] = min(restrictions[0][1], restrictions[0][0] - 1);
        for (i = 1; i < size; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        }

        for (i = size - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }

        int maxHeight = restrictions[0][1];
        for (i = 1; i < size; ++i) {
            maxHeight = max(maxHeight, (restrictions[i - 1][1] + restrictions[i][1] + restrictions[i][0] - restrictions[i - 1][0]) / 2);
        }

        return max(maxHeight, restrictions[size - 1][1] + n - restrictions[size - 1][0]);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> restrictions = { {2,1},{4,1} };
    check.checkInt(2, o.maxBuilding(5, restrictions));

    restrictions = { };
    check.checkInt(5, o.maxBuilding(6, restrictions));

    restrictions = { {5,3},{2,5},{7,4},{10,3} };
    check.checkInt(5, o.maxBuilding(10, restrictions));

    restrictions = { {8,5},{9,0},{6,2},{4,0},{3,2},{10,0},{5,3},{7,3},{2,4} };
    check.checkInt(2, o.maxBuilding(10, restrictions));
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
