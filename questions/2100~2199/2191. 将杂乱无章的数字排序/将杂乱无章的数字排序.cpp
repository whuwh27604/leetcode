/* 将杂乱无章的数字排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 mapping ，它表示一个十进制数的映射规则，mapping[i] = j 表示这个规则下将数位 i 映射为数位 j 。

一个整数 映射后的值 为将原数字每一个数位 i （0 <= i <= 9）映射为 mapping[i] 。

另外给你一个整数数组 nums ，请你将数组 nums 中每个数按照它们映射后对应数字非递减顺序排序后返回。

注意：

如果两个数字映射后对应的数字大小相同，则将它们按照输入中的 相对顺序 排序。
nums 中的元素只有在排序的时候需要按照映射后的值进行比较，返回的值应该是输入的元素本身。
 

示例 1：

输入：mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
输出：[338,38,991]
解释：
将数字 991 按照如下规则映射：
1. mapping[9] = 6 ，所有数位 9 都会变成 6 。
2. mapping[1] = 9 ，所有数位 1 都会变成 8 。
所以，991 映射的值为 669 。
338 映射为 007 ，去掉前导 0 后得到 7 。
38 映射为 07 ，去掉前导 0 后得到 7 。
由于 338 和 38 映射后的值相同，所以它们的前后顺序保留原数组中的相对位置关系，338 在 38 的前面。
所以，排序后的数组为 [338,38,991] 。
示例 2：

输入：mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
输出：[123,456,789]
解释：789 映射为 789 ，456 映射为 456 ，123 映射为 123 。所以排序后数组为 [123,456,789] 。
 

提示：

mapping.length == 10
0 <= mapping[i] <= 9
mapping[i] 的值 互不相同 。
1 <= nums.length <= 3 * 104
0 <= nums[i] < 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-the-jumbled-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class mappingNum {
public:
    int num;
    int mapped;
    int index;

    mappingNum(int n, int idx, vector<int>& mapping) {
        num = n;
        index = idx;
        string str = to_string(n);

        for (char& c : str) {
            c = mapping[c - '0'] + '0';
        }

        mapped = stoi(str);
    }

    bool operator<(const mappingNum& o) const {
        return mapped == o.mapped ? index < o.index : mapped < o.mapped;
    }
};

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int i, size = nums.size();
        vector<mappingNum> mappingNums;
        vector<int> ans(size);

        for (i = 0; i < size; ++i) {
            mappingNums.push_back(mappingNum(nums[i], i, mapping));
        }

        sort(mappingNums.begin(), mappingNums.end());

        for (i = 0; i < size; ++i) {
            ans[i] = mappingNums[i].num;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> mapping = { 8,9,4,0,2,1,3,5,7,6 };
    vector<int> nums = { 991,338,38 };
    vector<int> actual = o.sortJumbled(mapping, nums);
    vector<int> expected = { 338,38,991 };
    check.checkIntVector(expected, actual);

    mapping = { 0,1,2,3,4,5,6,7,8,9 };
    nums = { 789,456,123 };
    actual = o.sortJumbled(mapping, nums);
    expected = { 123,456,789 };
    check.checkIntVector(expected, actual);

    mapping = { 9,8,7,6,5,4,3,2,1,0 };
    nums = { 0,1,2,3,4,5,6,7,8,9 };
    actual = o.sortJumbled(mapping, nums);
    expected = { 9,8,7,6,5,4,3,2,1,0 };
    check.checkIntVector(expected, actual);

    mapping = { 9,8,7,6,5,4,3,2,1,0 };
    nums = { 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9 };
    actual = o.sortJumbled(mapping, nums);
    expected = { 9,9,8,8,7,7,6,6,5,5,4,4,3,3,2,2,1,1,0,0 };
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
