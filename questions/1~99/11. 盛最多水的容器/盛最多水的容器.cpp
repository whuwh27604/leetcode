/* 盛最多水的容器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

 



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例：

输入：[1,8,6,2,5,4,8,3,7]
输出：49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 对任意i、j范围内以min(a[i],a[j])为一边的容器，min(a[i],a[j])*(j-i)的容量一定是最大的
        int len = height.size(), left = 0, right = len - 1, maxVolume = 0;

        while (left != right) {
            int minHeight = (height[left] < height[right]) ? height[left] : height[right];
            int Volume = minHeight * (right - left);
            maxVolume = (maxVolume > Volume) ? maxVolume : Volume;

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxVolume;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> height = { 1,8,6,2,5,4,8,3,7 };
    check.checkInt(49, o.maxArea(height));

    height = { 8,6 };
    check.checkInt(6, o.maxArea(height));
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
