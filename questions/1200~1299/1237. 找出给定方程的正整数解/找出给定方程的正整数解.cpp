/* 找出给定方程的正整数解.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个函数  f(x, y) 和一个目标结果 z，请你计算方程 f(x,y) == z 所有可能的正整数 数对 x 和 y。

给定函数是严格单调的，也就是说：

f(x, y) < f(x + 1, y)
f(x, y) < f(x, y + 1)
函数接口定义如下：

interface CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
  int f(int x, int y);
};
如果你想自定义测试，你可以输入整数 function_id 和一个目标结果 z 作为输入，其中 function_id 表示一个隐藏函数列表中的一个函数编号，题目只会告诉你列表中的 2 个函数。  

你可以将满足条件的 结果数对 按任意顺序返回。

 

示例 1：

输入：function_id = 1, z = 5
输出：[[1,4],[2,3],[3,2],[4,1]]
解释：function_id = 1 表示 f(x, y) = x + y
示例 2：

输入：function_id = 2, z = 5
输出：[[1,5],[5,1]]
解释：function_id = 2 表示 f(x, y) = x * y
 

提示：

1 <= function_id <= 9
1 <= z <= 100
题目保证 f(x, y) == z 的解处于 1 <= x, y <= 1000 的范围内。
在 1 <= x, y <= 1000 的前提下，题目保证 f(x, y) 是一个 32 位有符号整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-positive-integer-solution-for-a-given-equation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class CustomFunction {
public:
    int f(int x, int y) {
        if (id == 1) {
            return x + y;
        }
        else if (id == 2) {
            return x * y;
        }
        else {
            return x + y - 1000;
        }
    }

    int id;
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> pairs;
        int maxY = 1000;

        for (int x = 1; x <= 1000; x++) {
            int y = binarySearch(customfunction, z, x, 1, maxY);
            if (y != -1) {
                pairs.push_back({ x,y });
                maxY = y - 1;
            }

            if (y == 1) {
                break;
            }
        }

        return pairs;
    }

    int binarySearch(CustomFunction& customfunction, int z, int x, int left, int right) {
        if (left > right) {
            return -1;
        }

        int middle = (left + right) / 2;
        int fn = customfunction.f(x, middle);
        if (fn == z) {
            return middle;
        }
        else if (fn > z) {
            return binarySearch(customfunction, z, x, left, middle - 1);
        }
        else {
            return binarySearch(customfunction, z, x, middle + 1, right);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    CustomFunction customfunction;
    customfunction.id = 1;
    vector<vector<int>> actual = o.findSolution(customfunction, 5);
    vector<vector<int>> expected = { {1,4},{2,3},{3,2},{4,1} };
    check.checkIntDoubleVector(expected, actual);

    customfunction.id = 2;
    actual = o.findSolution(customfunction, 5);
    expected = { {1,5},{5,1} };
    check.checkIntDoubleVector(expected, actual);

    customfunction.id = 2;
    actual = o.findSolution(customfunction, 1);
    expected = { {1,1} };
    check.checkIntDoubleVector(expected, actual);

    customfunction.id = 2;
    actual = o.findSolution(customfunction, 100);
    expected = { {1,100},{2,50},{4,25},{5,20},{10,10},{20,5},{25,4},{50,2},{100,1} };
    check.checkIntDoubleVector(expected, actual);
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
