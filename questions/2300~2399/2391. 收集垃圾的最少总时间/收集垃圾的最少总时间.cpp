/* 收集垃圾的最少总时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 garbage ，其中 garbage[i] 表示第 i 个房子的垃圾集合。garbage[i] 只包含字符 'M' ，'P' 和 'G' ，但可能包含多个相同字符，每个字符分别表示一单位的金属、纸和玻璃。垃圾车收拾 一 单位的任何一种垃圾都需要花费 1 分钟。

同时给你一个下标从 0 开始的整数数组 travel ，其中 travel[i] 是垃圾车从房子 i 行驶到房子 i + 1 需要的分钟数。

城市里总共有三辆垃圾车，分别收拾三种垃圾。每辆垃圾车都从房子 0 出发，按顺序 到达每一栋房子。但它们 不是必须 到达所有的房子。

任何时刻只有 一辆 垃圾车处在使用状态。当一辆垃圾车在行驶或者收拾垃圾的时候，另外两辆车 不能 做任何事情。

请你返回收拾完所有垃圾需要花费的 最少 总分钟数。

 

示例 1：

输入：garbage = ["G","P","GP","GG"], travel = [2,4,3]
输出：21
解释：
收拾纸的垃圾车：
1. 从房子 0 行驶到房子 1
2. 收拾房子 1 的纸垃圾
3. 从房子 1 行驶到房子 2
4. 收拾房子 2 的纸垃圾
收拾纸的垃圾车总共花费 8 分钟收拾完所有的纸垃圾。
收拾玻璃的垃圾车：
1. 收拾房子 0 的玻璃垃圾
2. 从房子 0 行驶到房子 1
3. 从房子 1 行驶到房子 2
4. 收拾房子 2 的玻璃垃圾
5. 从房子 2 行驶到房子 3
6. 收拾房子 3 的玻璃垃圾
收拾玻璃的垃圾车总共花费 13 分钟收拾完所有的玻璃垃圾。
由于没有金属垃圾，收拾金属的垃圾车不需要花费任何时间。
所以总共花费 8 + 13 = 21 分钟收拾完所有垃圾。
示例 2：

输入：garbage = ["MMM","PGM","GP"], travel = [3,10]
输出：37
解释：
收拾金属的垃圾车花费 7 分钟收拾完所有的金属垃圾。
收拾纸的垃圾车花费 15 分钟收拾完所有的纸垃圾。
收拾玻璃的垃圾车花费 15 分钟收拾完所有的玻璃垃圾。
总共花费 7 + 15 + 15 = 37 分钟收拾完所有的垃圾。
 

提示：

2 <= garbage.length <= 105
garbage[i] 只包含字母 'M' ，'P' 和 'G' 。
1 <= garbage[i].length <= 10
travel.length == garbage.length - 1
1 <= travel[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lastM = 0, lastP = 0, lastG = 0;
        vector<vector<int>> garbageCount(garbage.size(), vector<int>(3, 0));

        count(garbage, garbageCount, lastM, lastP, lastG);

        return collection(garbageCount, travel, 0, lastM)
            + collection(garbageCount, travel, 1, lastP)
            + collection(garbageCount, travel, 2, lastG);
    }

    void count(vector<string>& garbage, vector<vector<int>>& garbageCount, int& lastM, int& lastP, int& lastG) {
        for (int i = 0; i < (int)garbage.size(); ++i) {
            for (char c : garbage[i]) {
                if (c == 'M') {
                    ++garbageCount[i][0];
                    lastM = i;
                }
                else if (c == 'P') {
                    ++garbageCount[i][1];
                    lastP = i;
                }
                else {
                    ++garbageCount[i][2];
                    lastG = i;
                }
            }
        }
    }

    int collection(vector<vector<int>>& garbageCount, vector<int>& travel, int type, int last) {
        int time = 0;

        for (int i = 0; i < last; ++i) {
            time += garbageCount[i][type];
            time += travel[i];
        }

        return time + garbageCount[last][type];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> garbage = { "G","P","GP","GG" };
    vector<int> travel = { 2,4,3 };
    check.checkInt(21, o.garbageCollection(garbage, travel));

    garbage = { "MMM","PGM","GP" };
    travel = { 3,10 };
    check.checkInt(37, o.garbageCollection(garbage, travel));
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
