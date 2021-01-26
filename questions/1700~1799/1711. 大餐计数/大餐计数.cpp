/* 大餐计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。

你可以搭配 任意 两道餐品做一顿大餐。

给你一个整数数组 deliciousness ，其中 deliciousness[i] 是第 i​​​​​​​​​​​​​​ 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 大餐 的数量。结果需要对 109 + 7 取余。

注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。

 

示例 1：

输入：deliciousness = [1,3,5,7,9]
输出：4
解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。
示例 2：

输入：deliciousness = [1,1,1,3,3,3,7]
输出：15
解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。
 

提示：

1 <= deliciousness.length <= 105
0 <= deliciousness[i] <= 220

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-meals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        long long pairs1 = 0, pairs2 = 0;
        vector<int> powers = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576 };

        unordered_map<int, long long> numsCount;
        countNums(deliciousness, numsCount);

        for (auto iter = numsCount.begin(); iter != numsCount.end(); ++iter) {
            for (int power : powers) {
                if (iter->first == power) {
                    pairs1 += (iter->second * (iter->second - 1) / 2);
                }

                int num = power - iter->first;
                if (num != iter->first && numsCount.count(num) != 0) {
                    pairs2 += (iter->second * numsCount[num]);
                }
            }
        }

        return (int)((pairs1 + pairs2 / 2) % 1000000007);
    }

    void countNums(vector<int>& deliciousness, unordered_map<int, long long>& numsCount) {
        for (int num : deliciousness) {
            ++numsCount[num];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> deliciousness = { 1,0 };
    check.checkInt(1, o.countPairs(deliciousness));
    
    deliciousness = { 0,0 };
    check.checkInt(0, o.countPairs(deliciousness));

    deliciousness = { 1,3,5,7,9 };
    check.checkInt(4, o.countPairs(deliciousness));

    deliciousness = { 1,1,1,3,3,3,7 };
    check.checkInt(15, o.countPairs(deliciousness));

    deliciousness = { 1,1,3,7,15,31,63,127,255,511 };
    check.checkInt(17, o.countPairs(deliciousness));

    deliciousness = { 2160,1936,3,29,27,5,2503,1593,2,0,16,0,3860,28908,6,2,15,49,6246,1946,23,105,7996,196,0,2,55,457,5,3,924,7268,16,48,4,0,12,116,2628,1468 };
    check.checkInt(53, o.countPairs(deliciousness));

    deliciousness = { 2,14,11,5,1744,2352,0,1,1300,2796,0,4,376,1672,73,55,2006,42,10,6,0,2,2,0,0,1,0,1,0,2,271,241,1,63,1117,931,3,5,378,646,2,0,2,0,15,1 };
    check.checkInt(174, o.countPairs(deliciousness));
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
