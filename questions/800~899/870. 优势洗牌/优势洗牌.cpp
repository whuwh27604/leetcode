/* 优势洗牌.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个大小相等的数组 A 和 B，A 相对于 B 的优势可以用满足 A[i] > B[i] 的索引 i 的数目来描述。

返回 A 的任意排列，使其相对于 B 的优势最大化。

 

示例 1：

输入：A = [2,7,11,15], B = [1,10,4,11]
输出：[2,11,7,15]
示例 2：

输入：A = [12,24,8,32], B = [13,25,32,11]
输出：[24,32,8,12]
 

提示：

1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/advantage-shuffle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multimap<int, int> sortedB;
        sortB(B, sortedB);
        sort(A.begin(), A.end());

        int index = 0, size = A.size();
        vector<int> permutatedA(size, 0);

        auto iter = sortedB.begin();
        for (; iter != sortedB.end(); ++iter) {
            while ((index < size) && (A[index] <= iter->first)) {
                ++index;
            }

            if (index >= size) {
                break;
            }

            permutatedA[iter->second] = A[index];
            A[index++] = -1;
        }

        index = 0;
        for (; iter != sortedB.end(); ++iter) {
            while (A[index] == -1) {
                ++index;
            }

            permutatedA[iter->second] = A[index++];
        }

        return permutatedA;
    }

    void sortB(vector<int>& B, multimap<int, int>& sortedB) {
        for (int i = 0; i < (int)B.size(); ++i) {
            sortedB.insert({ B[i],i });
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 2,7,11,15 };
    vector<int> B = { 1,10,4,11 };
    vector<int> actual = o.advantageCount(A, B);
    vector<int> expected = { 2,11,7,15 };
    check.checkIntVector(expected, actual);

    A = { 12,24,8,32 };
    B = { 13,25,32,11 };
    actual = o.advantageCount(A, B);
    expected = { 24,32,8,12 };
    check.checkIntVector(expected, actual);

    A = { 2,0,4,1,2 };
    B = { 1,3,0,0,2 };
    actual = o.advantageCount(A, B);
    expected = { 2,0,1,2,4 };
    check.checkIntVector(expected, actual);

    A = { 5621,1743,5532,3549,9581 };
    B = { 913,9787,4121,5039,1481 };
    actual = o.advantageCount(A, B);
    expected = { 1743,9581,5532,5621,3549 };
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
