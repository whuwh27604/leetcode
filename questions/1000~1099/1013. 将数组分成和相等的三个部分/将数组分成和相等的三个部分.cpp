/* 将数组分成和相等的三个部分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

 

示例 1：

输入：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
示例 2：

输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
示例 3：

输入：[3,3,6,5,-2,2,5,1,-9,4]
输出：true
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 

提示：

3 <= A.length <= 50000
-10^4 <= A[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int i, sum = 0, tmpSum = 0, len = A.size();

        for (i = 0; i < len; i++) {
            sum += A[i];
        }

        int oneThirdSum = (sum / 3);
        if ((oneThirdSum * 3) != sum) {
            return false;
        }

        for (i = 0; i < len; i++) {
            tmpSum += A[i];
            if (tmpSum == oneThirdSum) {
                break;
            }
        }

        if (i == len) {
            return false;
        }

        tmpSum = 0;
        for (i = (i + 1); i < len; i++) {
            tmpSum += A[i];
            if (tmpSum == oneThirdSum) {
                break;
            }
        }

        return (i < (len - 1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 0,2,1,-6,6,-7,9,1,2,0,1 };
    check.checkBool(true, o.canThreePartsEqualSum(A));

    A = { 0,2,1,-6,6,7,9,-1,2,0,1 };
    check.checkBool(false, o.canThreePartsEqualSum(A));

    A = { 3,3,6,5,-2,2,5,1,-9,4 };
    check.checkBool(true, o.canThreePartsEqualSum(A));

    A = { 1,2,3 };
    check.checkBool(false, o.canThreePartsEqualSum(A));

    A = { 2,2,3 };
    check.checkBool(false, o.canThreePartsEqualSum(A));

    A = { 3,3,6 };
    check.checkBool(false, o.canThreePartsEqualSum(A));

    A = { 3,3,3 };
    check.checkBool(true, o.canThreePartsEqualSum(A));

    A = { 1,-1,1,-1 };
    check.checkBool(false, o.canThreePartsEqualSum(A));

    A = { 6,1,1,13,-1,0,-10,20 };
    check.checkBool(false, o.canThreePartsEqualSum(A));
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
