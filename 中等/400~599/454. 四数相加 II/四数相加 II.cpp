/* 四数相加 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AB, CD;
        twoSum(A, B, AB);
        twoSum(C, D, CD);

        int count = 0;
        for (auto iter = AB.begin(); iter != AB.end(); iter++) {
            auto it = CD.find(-(iter->first));
            if (it != CD.end()) {
                count += (iter->second * it->second);
            }
        }

        return count;
    }

    void twoSum(vector<int>& one, vector<int>& two, unordered_map<int, int>& sumCount) {
        for (int a : one) {
            for (int b : two) {
                int sum = a + b;
                auto iter = sumCount.find(sum);
                if (iter == sumCount.end()) {
                    sumCount[sum] = 1;
                }
                else {
                    iter->second++;
                }
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2 };
    vector<int> B = { -2,-1 };
    vector<int> C = { -1,2 };
    vector<int> D = { 0,2 };
    check.checkInt(2, o.fourSumCount(A, B, C, D));

    A = {  };
    B = {  };
    C = {  };
    D = {  };
    check.checkInt(0, o.fourSumCount(A, B, C, D));

    A = { 1 };
    B = { 1 };
    C = { 1 };
    D = { 1 };
    check.checkInt(0, o.fourSumCount(A, B, C, D));

    A = { 1 };
    B = { 1 };
    C = { -1 };
    D = { -1 };
    check.checkInt(1, o.fourSumCount(A, B, C, D));

    A = { 1,2,10 };
    B = { 2,1,10 };
    C = { 0,-1,-2 };
    D = { -3,-2,-1 };
    check.checkInt(10, o.fourSumCount(A, B, C, D));
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
