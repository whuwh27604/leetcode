/* 距离相等的条形码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。

 

示例 1：

输入：[1,1,1,2,2,2]
输出：[2,1,2,1,2,1]
示例 2：

输入：[1,1,1,1,2,2,3,3]
输出：[1,3,1,3,2,1,2,1]
 

提示：

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distant-barcodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int, int>> barcodesCount;
        countBarcodes(barcodes, barcodesCount);

        int size = barcodes.size(), count = 0, barcode = 0;
        vector<int> rearranged(size, 0);
        
        // 贪心算法，始终把最多的barcode放在偶数位，一直到数组最后，然后再填上奇数位的空位
        placeBarcodes(barcodesCount, 0, size, count, barcode, rearranged);
        placeBarcodes(barcodesCount, 1, size, count, barcode, rearranged);

        return rearranged;
    }

    void countBarcodes(vector<int>& barcodes, priority_queue<pair<int, int>>& barcodesCount) {
        unordered_map<int, int> count;

        for (int barcode : barcodes) {
            ++count[barcode];
        }

        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            barcodesCount.push({ iter->second, iter->first });
        }
    }

    void placeBarcodes(priority_queue<pair<int, int>>& barcodesCount, int start, int size, int& count, int& barcode, vector<int>& rearranged) {
        for (int i = start; i < size; i += 2) {
            if (count == 0) {
                count = barcodesCount.top().first;
                barcode = barcodesCount.top().second;
                barcodesCount.pop();
            }
            
            rearranged[i] = barcode;
            --count;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> barcodes = { 1,1,1,2,2,2 };
    vector<int> actual = o.rearrangeBarcodes(barcodes);
    vector<int> expected = { 2,1,2,1,2,1 };
    check.checkIntVector(expected, actual);

    barcodes = { 1,1,1,1,2,2,3,3 };
    actual = o.rearrangeBarcodes(barcodes);
    expected = { 1,3,1,3,1,2,1,2 };
    check.checkIntVector(expected, actual);

    barcodes = { 1,1,1,1,3,3,3,2,2,4 };
    actual = o.rearrangeBarcodes(barcodes);
    expected = { 1,3,1,3,1,2,1,2,3,4 };
    check.checkIntVector(expected, actual);

    barcodes = { 5 };
    actual = o.rearrangeBarcodes(barcodes);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    barcodes = { 5,6 };
    actual = o.rearrangeBarcodes(barcodes);
    expected = { 6,5 };
    check.checkIntVector(expected, actual);

    barcodes = { 7,7,7,8,5,7,5,5,5,8 };
    actual = o.rearrangeBarcodes(barcodes);
    expected = { 7,5,7,5,7,5,7,8,5,8 };
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
