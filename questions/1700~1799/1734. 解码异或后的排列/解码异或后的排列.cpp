/* 解码异或后的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。

它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。

给你 encoded 数组，请你返回原始数组 perm 。题目保证答案存在且唯一。

 

示例 1：

输入：encoded = [3,1]
输出：[1,2,3]
解释：如果 perm = [1,2,3] ，那么 encoded = [1 XOR 2,2 XOR 3] = [3,1]
示例 2：

输入：encoded = [6,5,4,6]
输出：[2,4,1,5,3]
 

提示：

3 <= n < 105
n 是奇数。
encoded.length == n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-xored-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int i, size = encoded.size(), xorWithoutFirst = 0, xorAll = size + 1;

        for (i = 1; i < size; i += 2) {
            xorWithoutFirst ^= encoded[i];
            xorAll ^= (i ^ (i + 1));
        }

        vector<int> nums(size + 1);
        nums[0] = xorAll ^ xorWithoutFirst;

        for (i = 0; i < size; ++i) {
            nums[i + 1] = nums[i] ^ encoded[i];
        }

        return nums;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> encoded = { 3,1 };
    vector<int> actual = o.decode(encoded);
    vector<int> expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    encoded = { 6,5,4,6 };
    actual = o.decode(encoded);
    expected = { 2,4,1,5,3 };
    check.checkIntVector(expected, actual);
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
