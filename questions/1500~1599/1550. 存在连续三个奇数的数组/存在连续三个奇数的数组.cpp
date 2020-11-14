/* 存在连续三个奇数的数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。

 

示例 1：

输入：arr = [2,6,4,1]
输出：false
解释：不存在连续三个元素都是奇数的情况。
示例 2：

输入：arr = [1,2,34,3,4,5,7,23,12]
输出：true
解释：存在连续三个元素都是奇数的情况，即 [5,7,23] 。
 

提示：

1 <= arr.length <= 1000
1 <= arr[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-consecutive-odds
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;

        for (int num : arr) {
            if (num % 2 == 1) {
                if (++odds == 3) {
                    return true;
                }
            }
            else {
                odds = 0;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 2,6,4,1 };
    check.checkBool(false, o.threeConsecutiveOdds(arr));

    arr = { 1,2,34,3,4,5,7,23,12 };
    check.checkBool(true, o.threeConsecutiveOdds(arr));

    arr = { 1 };
    check.checkBool(false, o.threeConsecutiveOdds(arr));

    arr = { 1,3 };
    check.checkBool(false, o.threeConsecutiveOdds(arr));

    arr = { 1,3,5 };
    check.checkBool(true, o.threeConsecutiveOdds(arr));
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
