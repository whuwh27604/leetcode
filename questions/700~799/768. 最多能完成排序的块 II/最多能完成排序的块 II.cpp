/* 最多能完成排序的块 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
这个问题和“最多能完成排序的块”相似，但给定数组中的元素可以重复，输入数组最大长度为2000，其中的元素最大为10**8。

arr是一个可能包含重复元素的整数数组，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。

我们最多能将数组分成多少块？

示例 1:

输入: arr = [5,4,3,2,1]
输出: 1
解释:
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。 
示例 2:

输入: arr = [2,1,3,4,4]
输出: 4
解释:
我们可以把它分成两块，例如 [2, 1], [3, 4, 4]。
然而，分成 [2, 1], [3], [4], [4] 可以得到最多的块数。 
注意:

arr的长度在[1, 2000]之间。
arr[i]的大小在[0, 10**8]之间。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/max-chunks-to-make-sorted-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i, size = arr.size(), prefixMax = 0, chunks = 0;
        vector<int> suffixMin(size + 1, INT_MAX);

        for (i = size - 1; i >= 0; --i) {
            suffixMin[i] = min(arr[i], suffixMin[i + 1]);
        }

        for (i = 0; i < size; ++i) {
            prefixMax = max(prefixMax, arr[i]);

            if (prefixMax <= suffixMin[i + 1]) {
                ++chunks;
            }
        }

        return chunks;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 5,4,3,2,1 };
    check.checkInt(1, o.maxChunksToSorted(arr));

    arr = { 2,1,3,4,4 };
    check.checkInt(4, o.maxChunksToSorted(arr));

    arr = { 100 };
    check.checkInt(1, o.maxChunksToSorted(arr));
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
