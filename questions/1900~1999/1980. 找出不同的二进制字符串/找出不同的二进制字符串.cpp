/* 找出不同的二进制字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 nums ，该数组由 n 个 互不相同 的二进制字符串组成，且每个字符串长度都是 n 。请你找出并返回一个长度为 n 且 没有出现 在 nums 中的二进制字符串。如果存在多种答案，只需返回 任意一个 即可。

 

示例 1：

输入：nums = ["01","10"]
输出："11"
解释："11" 没有出现在 nums 中。"00" 也是正确答案。
示例 2：

输入：nums = ["00","01"]
输出："11"
解释："11" 没有出现在 nums 中。"10" 也是正确答案。
示例 3：

输入：nums = ["111","011","001"]
输出："101"
解释："101" 没有出现在 nums 中。"000"、"010"、"100"、"110" 也是正确答案。
 

提示：

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] 为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-unique-binary-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int i, size = nums.size();
        string cantor(size, 0);  //  康托对角线

        for (i = 0; i < size; ++i) {
            cantor[i] = (nums[i][i] == '0' ? '1' : '0');
        }

        return cantor;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> nums = { "01","10" };
    check.checkString("11", o.findDifferentBinaryString(nums));

    nums = { "00","01" };
    check.checkString("10", o.findDifferentBinaryString(nums));

    nums = { "111","011","001" };
    check.checkString("000", o.findDifferentBinaryString(nums));

    nums = { "0" };
    check.checkString("1", o.findDifferentBinaryString(nums));
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
