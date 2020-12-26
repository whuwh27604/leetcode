/* 切割后面积最大的蛋糕.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
矩形蛋糕的高度为 h 且宽度为 w，给你两个整数数组 horizontalCuts 和 verticalCuts，其中 horizontalCuts[i] 是从矩形蛋糕顶部到第  i 个水平切口的距离，类似地， verticalCuts[j] 是从矩形蛋糕的左侧到第 j 个竖直切口的距离。

请你按数组 horizontalCuts 和 verticalCuts 中提供的水平和竖直位置切割后，请你找出 面积最大 的那份蛋糕，并返回其 面积 。由于答案可能是一个很大的数字，因此需要将结果对 10^9 + 7 取余后返回。

 

示例 1：



输入：h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
输出：4
解释：上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色的那份蛋糕面积最大。
示例 2：



输入：h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
输出：6
解释：上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色和黄色的两份蛋糕面积最大。
示例 3：

输入：h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
输出：9
 

提示：

2 <= h, w <= 10^9
1 <= horizontalCuts.length < min(h, 10^5)
1 <= verticalCuts.length < min(w, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
题目数据保证 horizontalCuts 中的所有元素各不相同
题目数据保证 verticalCuts 中的所有元素各不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        return (int)(((long long)getMaxInterval(h, horizontalCuts) * (long long)getMaxInterval(w, verticalCuts)) % 1000000007);
    }

    int getMaxInterval(int len, vector<int>& cuts) {
        int prev = 0, maxInterval = 0;

        for (int cut : cuts) {
            int interval = cut - prev;
            maxInterval = max(maxInterval, interval);
            prev = cut;
        }

        return max(maxInterval, len - prev);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> horizontalCuts = { 1,2,4 };
    vector<int> verticalCuts = { 1,3 };
    check.checkInt(4, o.maxArea(5, 4, horizontalCuts, verticalCuts));

    horizontalCuts = { 3,1 };
    verticalCuts = { 1 };
    check.checkInt(6, o.maxArea(5, 4, horizontalCuts, verticalCuts));

    horizontalCuts = { 3 };
    verticalCuts = { 3 };
    check.checkInt(9, o.maxArea(5, 4, horizontalCuts, verticalCuts));

    horizontalCuts = {  };
    verticalCuts = {  };
    check.checkInt(20, o.maxArea(5, 4, horizontalCuts, verticalCuts));
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
