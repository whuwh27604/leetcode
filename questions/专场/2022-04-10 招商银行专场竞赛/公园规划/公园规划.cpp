// 公园规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numFlowers(vector<vector<int>>& roads) {
        vector<int> degrees(roads.size() + 1, 0);

        for (auto& road : roads) {
            ++degrees[road[0]];
            ++degrees[road[1]];
        }

        return *max_element(degrees.begin(), degrees.end()) + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> roads = { {0,1},{1,3},{1,2} };
    check.checkInt(4, o.numFlowers(roads));

    roads = { {0,1},{0,2},{1,3},{2,5},{3,6},{5,4} };
    check.checkInt(3, o.numFlowers(roads));

    roads = { {0,1} };
    check.checkInt(2, o.numFlowers(roads));
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
