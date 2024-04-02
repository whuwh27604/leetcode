/* 将元素分配到两个数组中 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 1 开始、长度为 n 的整数数组 nums 。

现定义函数 greaterCount ，使得 greaterCount(arr, val) 返回数组 arr 中 严格大于 val 的元素数量。

你需要使用 n 次操作，将 nums 的所有元素分配到两个数组 arr1 和 arr2 中。在第一次操作中，将 nums[1] 追加到 arr1 。在第二次操作中，将 nums[2] 追加到 arr2 。之后，在第 i 次操作中：

如果 greaterCount(arr1, nums[i]) > greaterCount(arr2, nums[i]) ，将 nums[i] 追加到 arr1 。
如果 greaterCount(arr1, nums[i]) < greaterCount(arr2, nums[i]) ，将 nums[i] 追加到 arr2 。
如果 greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i]) ，将 nums[i] 追加到元素数量较少的数组中。
如果仍然相等，那么将 nums[i] 追加到 arr1 。
连接数组 arr1 和 arr2 形成数组 result 。例如，如果 arr1 == [1,2,3] 且 arr2 == [4,5,6] ，那么 result = [1,2,3,4,5,6] 。

返回整数数组 result 。



示例 1：

输入：nums = [2,1,3,3]
输出：[2,3,1,3]
解释：在前两次操作后，arr1 = [2] ，arr2 = [1] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是零，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，两个数组中大于 3 的元素数量都是零，但 arr2 的长度较小，因此，将 nums[4] 追加到 arr2 。
在 4 次操作后，arr1 = [2,3] ，arr2 = [1,3] 。
因此，连接形成的数组 result 是 [2,3,1,3] 。
示例 2：

输入：nums = [5,14,3,1,2]
输出：[5,3,1,2,14]
解释：在前两次操作后，arr1 = [5] ，arr2 = [14] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是一，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，arr1 中大于 1 的元素数量大于 arr2 中的数量（2 > 1），因此，将 nums[4] 追加到 arr1 。
在第 5 次操作中，arr1 中大于 2 的元素数量大于 arr2 中的数量（2 > 1），因此，将 nums[5] 追加到 arr1 。
在 5 次操作后，arr1 = [5,3,1,2] ，arr2 = [14] 。
因此，连接形成的数组 result 是 [5,3,1,2,14] 。
示例 3：

输入：nums = [3,3,3,3]
输出：[3,3,3,3]
解释：在 4 次操作后，arr1 = [3,3] ，arr2 = [3,3] 。
因此，连接形成的数组 result 是 [3,3,3,3] 。


提示：

3 <= n <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> index2nums(n);
		int maxNum = discretize(n, nums, index2nums);
        BIT bit1(maxNum), bit2(maxNum);
        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        bit1.update(index2nums[0], 1);
        arr2.push_back(nums[1]);
        bit2.update(index2nums[1], 1);

        for (int i = 2; i < n; ++i) {
            int num = nums[i], discretized = index2nums[i];
            int count1 = (int)arr1.size() - bit1.query(discretized);
            int count2 = (int)arr2.size() - bit2.query(discretized);

            if (count1 > count2) {
                arr1.push_back(num);
                bit1.update(discretized, 1);
            }
            else if (count1 < count2) {
                arr2.push_back(num);
                bit2.update(discretized, 1);
            }
            else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(num);
                    bit1.update(discretized, 1);
                }
                else {
                    arr2.push_back(num);
                    bit2.update(discretized, 1);
                }
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }

	int discretize(int n, vector<int>& nums, vector<int>& index2nums) {
		vector<pair<int, int>> numIndices(n);

		for (int i = 0; i < n; ++i) {
			numIndices[i] = { nums[i],i };
		}

		sort(numIndices.begin(), numIndices.end());
		int num = 1;
		index2nums[numIndices[0].second] = num;

		for (int i = 1; i < n; ++i) {
			if (numIndices[i].first != numIndices[i - 1].first) {
				++num;
			}
			index2nums[numIndices[i].second] = num;
		}

        return num;
	}
};

int main()
{
	Solution o;
	CheckResult check;

    vector<int> nums = { 2,1,3,3 };
    vector<int> actual = o.resultArray(nums);
    vector<int> expected = { 2,3,1,3 };
    check.checkIntVector(expected, actual);

    nums = { 5,14,3,1,2 };
    actual = o.resultArray(nums);
    expected = { 5,3,1,2,14 };
    check.checkIntVector(expected, actual);

    nums = { 3,3,3,3 };
    actual = o.resultArray(nums);
    expected = { 3,3,3,3 };
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
