/* 两个数组间的距离值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。

「距离值」 定义为符合此描述的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d 。

 

示例 1：

输入：arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
输出：2
解释：
对于 arr1[0]=4 我们有：
|4-10|=6 > d=2
|4-9|=5 > d=2
|4-1|=3 > d=2
|4-8|=4 > d=2
对于 arr1[1]=5 我们有：
|5-10|=5 > d=2
|5-9|=4 > d=2
|5-1|=4 > d=2
|5-8|=3 > d=2
对于 arr1[2]=8 我们有：
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
示例 2：

输入：arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
输出：2
示例 3：

输入：arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
输出：1
 

提示：

1 <= arr1.length, arr2.length <= 500
-10^3 <= arr1[i], arr2[j] <= 10^3
0 <= d <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int i, j, len1 = arr1.size(), len2 = arr2.size(), distance = 0;

        for (i = 0; i < len1; i++) {
            for (j = 0; j < len2; j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    break;
                }
            }

            if (j == len2) {
                distance++;
            }
        }

        return distance;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr1 = { 4,5,8 };
    vector<int> arr2 = { 10,9,1,8 };
    check.checkInt(2, o.findTheDistanceValue(arr1, arr2, 2)); 
    
    arr1 = { 1,4,2,3 };
    arr2 = { -4,-3,6,10,20,30 };
    check.checkInt(2, o.findTheDistanceValue(arr1, arr2, 3));

    arr1 = { 2,1,100,3 };
    arr2 = { -5,-2,10,-3,7 };
    check.checkInt(1, o.findTheDistanceValue(arr1, arr2, 6));

    arr1 = { 0 };
    arr2 = { 100 };
    check.checkInt(0, o.findTheDistanceValue(arr1, arr2, 100));

    arr1 = { 0 };
    arr2 = { 101,-101 };
    check.checkInt(1, o.findTheDistanceValue(arr1, arr2, 100));

    arr1 = {  };
    for (int i = 1; i <= 500; i++) {
        arr1.push_back(i);
    }
    arr2 = {  };
    for (int i = 1; i <= 500; i++) {
        arr2.push_back(i + 1000);
    }
    check.checkInt(500, o.findTheDistanceValue(arr1, arr2, 1));
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
