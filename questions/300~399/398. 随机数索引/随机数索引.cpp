/* 随机数索引.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Number {
public:
    Number() : size(0), current(0) {}

    void add(int index) {
        indices.push_back(index);
        ++size, ++current;
    }

    int pick() {
        if (current == 0) {
            reset();
        }

        int rnum = rd() % current--;

        // 随机选择一个位置，如果这个位置还没有被挑选过，那么挑选它；如果已经被挑选了，那么挑选它映射的位置
        int pos = picked.count(rnum) == 0 ? rnum : picked[rnum];

        // 将选中的这个位置映射到最后一个位置，如果最后一个位置已经挑选了，那么映射到它挑选时映射的位置
        picked[rnum] = picked.count(current) == 0 ? current : picked[current];

        return indices[pos];
    }

    void reset() {
        picked.clear();
        current = size;
    }

private:
    vector<int> indices;
    random_device rd;
    unordered_map<int, int> picked;
    int size;
    int current;
};

class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            numbers[nums[i]].add(i);
        }
    }

    int pick(int target) {
        return numbers[target].pick();
    }

private:
    unordered_map<int, Number> numbers;
};

int main()
{
    CheckResult check;

    vector<int> nums = { 1,2,3,3,3 };
    Solution o1(nums);
    vector<int> actual = { o1.pick(1), o1.pick(1), o1.pick(1), o1.pick(1), o1.pick(1) };
    vector<int> expected = { 0,0,0,0,0 };
    check.checkIntVectorRandomOrder(expected, actual);
    actual = { o1.pick(2), o1.pick(2), o1.pick(2), o1.pick(2), o1.pick(2) };
    expected = { 1,1,1,1,1 };
    check.checkIntVectorRandomOrder(expected, actual);
    actual = { o1.pick(3), o1.pick(3), o1.pick(3), o1.pick(3), o1.pick(3), o1.pick(3), o1.pick(3), o1.pick(3), o1.pick(3) };
    expected = { 2,2,2,3,3,3,4,4,4 };
    check.checkIntVectorRandomOrder(expected, actual);
    for (int i = 0; i < 5; ++i) {
        actual = { o1.pick(3), o1.pick(3), o1.pick(3) };
        expected = { 2,3,4 };
        check.checkIntVectorRandomOrder(expected, actual);
    }
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
