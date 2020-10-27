/* 独一无二的出现次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

 

示例 1：

输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：

输入：arr = [1,2]
输出：false
示例 3：

输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true
 

提示：

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-number-of-occurrences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numsCount;
        unordered_set<int> times;

        for (int num : arr) {
            ++numsCount[num];
        }

        for (auto iter = numsCount.begin(); iter != numsCount.end(); ++iter) {
            if (times.count(iter->second) != 0) {
                return false;
            }

            times.insert(iter->second);
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 1,2,2,1,1,3 };
    check.checkBool(true, o.uniqueOccurrences(arr));

    arr = { 1,2 };
    check.checkBool(false, o.uniqueOccurrences(arr));

    arr = { 2,2 };
    check.checkBool(true, o.uniqueOccurrences(arr));

    arr = { -3,0,1,-3,1,1,1,-3,10,0 };
    check.checkBool(true, o.uniqueOccurrences(arr));

    arr = { 5 };
    check.checkBool(true, o.uniqueOccurrences(arr));
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
