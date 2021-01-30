/* 高度检查器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。

请你返回能让所有学生以 非递减 高度排列的最小必要移动人数。

注意，当一组学生被选中时，他们之间可以以任何可能的方式重新排序，而未被选中的学生应该保持不动。

 

示例：

输入：heights = [1,1,4,2,1,3]
输出：3
解释：
当前数组：[1,1,4,2,1,3]
目标数组：[1,1,1,2,3,4]
在下标 2 处（从 0 开始计数）出现 4 vs 1 ，所以我们必须移动这名学生。
在下标 4 处（从 0 开始计数）出现 1 vs 3 ，所以我们必须移动这名学生。
在下标 5 处（从 0 开始计数）出现 3 vs 4 ，所以我们必须移动这名学生。
示例 2：

输入：heights = [5,1,2,3,4]
输出：5
示例 3：

输入：heights = [1,2,3,4,5]
输出：0
 

提示：

1 <= heights.length <= 100
1 <= heights[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/height-checker
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // 因为1 <= heights[i] <= 100，范围较小，可以采用桶排序
        int i, heightsIndex = 0, len = heights.size(), diffCount = 0;
        int bucket[101] = { 0 };
        for (i = 0; i < len; i++) {
            bucket[heights[i]]++;
        }

        for (i = 0; i < 101; i++) {
            if (bucket[i] == 0) {
                continue;
            }

            while (bucket[i]-- != 0) {
                if (i != heights[heightsIndex++]) {
                    diffCount++;
                }
            }
        }

        return diffCount;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> heights = { 1,1,4,2,1,3 };
    check.checkInt(3, o.heightChecker(heights));

    heights = { 5,1,2,3,4 };
    check.checkInt(5, o.heightChecker(heights));

    heights = { 1,2,3,4,5 };
    check.checkInt(0, o.heightChecker(heights));

    heights = { 5 };
    check.checkInt(0, o.heightChecker(heights));

    heights = { 1,5 };
    check.checkInt(0, o.heightChecker(heights));

    heights = { 5,1 };
    check.checkInt(2, o.heightChecker(heights));

    heights = { 5,5 };
    check.checkInt(0, o.heightChecker(heights));

    heights = { 5,4,3,2,1 };
    check.checkInt(4, o.heightChecker(heights));
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
