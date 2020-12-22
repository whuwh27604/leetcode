/* 形成两个异或相等数组的三元组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 。

现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。

a 和 b 定义如下：

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
注意：^ 表示 按位异或 操作。

请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。

 

示例 1：

输入：arr = [2,3,1,6,7]
输出：4
解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
示例 2：

输入：arr = [1,1,1,1,1]
输出：10
示例 3：

输入：arr = [2,3]
输出：0
示例 4：

输入：arr = [1,3,5,7,9]
输出：3
示例 5：

输入：arr = [7,11,12,9,5,2,7,17,22]
输出：8
 

提示：

1 <= arr.length <= 300
1 <= arr[i] <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        /* 1、if a==b, then a^b = 0, 所以如果arr[i]^...^arr[j]^...^arr[k]=0，那么j可以取[i,k]之间任何一个
           2、if preXOR[i]==preXOR[j], then preXOR[i,j]=0 */
        unordered_map<int, vector<int>> preXORs = { {0,{-1}} };  // 预置index=-1的preXOR等于0
        int i, size = arr.size(), preXOR = 0, triplets = 0;

        for (i = 0; i < size; ++i) {
            preXOR ^= arr[i];

            for (int index : preXORs[preXOR]) {
                triplets += (i - index - 1);  // 对于前面每一个preXOR相等的位置index，从index+1到i的preXOR等于0，j可以选择(index+1,i]之间任何一个
            }

            preXORs[preXOR].push_back(i);
        }

        return triplets;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 2,3,1,6,7 };
    check.checkInt(4, o.countTriplets(arr));

    arr = { 1,1,1,1,1 };
    check.checkInt(10, o.countTriplets(arr));

    arr = { 2,3 };
    check.checkInt(0, o.countTriplets(arr));

    arr = { 1,3,5,7,9 };
    check.checkInt(3, o.countTriplets(arr));

    arr = { 7,11,12,9,5,2,7,17,22 };
    check.checkInt(8, o.countTriplets(arr));

    arr = { 0,0,0,0,0,0,0,0 };
    check.checkInt(84, o.countTriplets(arr));
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
