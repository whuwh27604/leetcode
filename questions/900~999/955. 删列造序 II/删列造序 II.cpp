/* 删列造序 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定由 N 个小写字母字符串组成的数组 A，其中每个字符串长度相等。

选取一个删除索引序列，对于 A 中的每个字符串，删除对应每个索引处的字符。

比如，有 A = ["abcdef", "uvwxyz"]，删除索引序列 {0, 2, 3}，删除后 A 为["bef", "vyz"]。

假设，我们选择了一组删除索引 D，那么在执行删除操作之后，最终得到的数组的元素是按 字典序（A[0] <= A[1] <= A[2] ... <= A[A.length - 1]）排列的，然后请你返回 D.length 的最小可能值。

 

示例 1：

输入：["ca","bb","ac"]
输出：1
解释：
删除第一列后，A = ["a", "b", "c"]。
现在 A 中元素是按字典排列的 (即，A[0] <= A[1] <= A[2])。
我们至少需要进行 1 次删除，因为最初 A 不是按字典序排列的，所以答案是 1。
示例 2：

输入：["xc","yb","za"]
输出：0
解释：
A 的列已经是按字典序排列了，所以我们不需要删除任何东西。
注意 A 的行不需要按字典序排列。
也就是说，A[0][0] <= A[0][1] <= ... 不一定成立。
示例 3：

输入：["zyx","wvu","tsr"]
输出：3
解释：
我们必须删掉每一列。
 

提示：

1 <= A.length <= 100
1 <= A[i].length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-columns-to-make-sorted-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int c, row = A.size(), column = A[0].size(), deleteCount = 0;
        vector<pair<int, int>> sameCharSegments = { {0, row - 1} }, newSegments;

        // 贪心算法，第一列必须是字典序，不是的就应该删掉。然后第一列中如果存在相同的字母，就需要继续比较后序的列在相同字母行的范围内是否是字典序，不是则需要删掉
        for (c = 0; c != column; ++c) {
            if (!isLexicographic(A, c, sameCharSegments, newSegments)) {
                deleteCount++;
            }
            else {
                if (newSegments.empty()) {
                    break;
                }

                sameCharSegments = newSegments;
            }

            newSegments.clear();
        }

        return deleteCount;
    }

    bool isLexicographic(vector<string>& A, int column, vector<pair<int, int>>& sameCharSegments, vector<pair<int, int>>& newSegments) {
        for (pair<int, int>& segment : sameCharSegments) {
            int r, start = segment.first;

            for (r = segment.first + 1; r <= segment.second; ++r) {
                if (A[r][column] < A[r - 1][column]) {
                    return false;
                }
                else if (A[r][column] > A[r - 1][column]) {
                    if (r - 1 != start) {
                        newSegments.push_back({ start, r - 1 });
                    }
                    start = r;
                }
            }

            if (r - 1 != start) {
                newSegments.push_back({ start, r - 1 });
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> A = { "ca","bb","ac" };
    check.checkInt(1, o.minDeletionSize(A));

    A = { "xc","yb","za" };
    check.checkInt(0, o.minDeletionSize(A));

    A = { "zyx","wvu","tsr" };
    check.checkInt(3, o.minDeletionSize(A));

    A = { "xga","xfb","yfa" };
    check.checkInt(1, o.minDeletionSize(A));

    A = { "jwkwdc","etukoz" };
    check.checkInt(2, o.minDeletionSize(A));

    A = { "xc","yb","za" };
    check.checkInt(0, o.minDeletionSize(A));

    A = { "ab","aa" };
    check.checkInt(1, o.minDeletionSize(A));

    A = { "a","b" };
    check.checkInt(0, o.minDeletionSize(A));

    A = { "b","a" };
    check.checkInt(1, o.minDeletionSize(A));

    A = { "bac","bab","aac" };
    check.checkInt(2, o.minDeletionSize(A));

    A = { "koccmoezl","hbccayhbd" };
    check.checkInt(3, o.minDeletionSize(A));
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
