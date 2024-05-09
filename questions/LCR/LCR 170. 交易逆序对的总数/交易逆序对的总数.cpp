/* 交易逆序对的总数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的「交易逆序对」总数。



示例 1:

输入：record = [9, 7, 5, 4, 6]
输出：8
解释：交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)。


限制：

0 <= record.length <= 50000
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
	int reversePairs(vector<int>& record) {
        int n = (int)record.size(), pairs = 0;
        if (n == 0) {
            return 0;
        }

        vector<int> index2nums(n);
        int maxNum = discretize(n, record, index2nums);
        BIT bit(maxNum);

        for (int i = 0; i < n; ++i) {
            int num = index2nums[i];
            pairs += (i - bit.query(num));
            bit.update(num, 1);
        }

        return pairs;
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

    vector<int> record = { 9,7,5,4,6 };
    check.checkInt(8, o.reversePairs(record));

    record = {  };
    check.checkInt(0, o.reversePairs(record));

    record = { 1 };
    check.checkInt(0, o.reversePairs(record));

    record = { 2,1 };
    check.checkInt(1, o.reversePairs(record));
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
