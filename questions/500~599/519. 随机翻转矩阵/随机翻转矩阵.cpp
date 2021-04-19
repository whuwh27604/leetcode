/* 随机翻转矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
题中给出一个 n_rows 行 n_cols 列的二维矩阵，且所有值被初始化为 0。要求编写一个 flip 函数，均匀随机的将矩阵中的 0 变为 1，并返回该值的位置下标 [row_id,col_id]；同样编写一个 reset 函数，将所有的值都重新置为 0。尽量最少调用随机函数 Math.random()，并且优化时间和空间复杂度。

注意:

1 <= n_rows, n_cols <= 10000
0 <= row.id < n_rows 并且 0 <= col.id < n_cols
当矩阵中没有值为 0 时，不可以调用 flip 函数
调用 flip 和 reset 函数的次数加起来不会超过 1000 次
示例 1：

输入:
["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]
输出: [null,[0,1],[1,2],[1,0],[1,1]]
示例 2：

输入:
["Solution","flip","flip","reset","flip"]
[[1,2],[],[],[],[]]
输出: [null,[0,0],[0,1],null,[0,0]]
输入语法解释：

输入包含两个列表：被调用的子程序和他们的参数。Solution 的构造函数有两个参数，分别为 n_rows 和 n_cols。flip 和 reset 没有参数，参数总会以列表形式给出，哪怕该列表为空

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-flip-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution(int n_rows, int n_cols) {
        row = n_rows;
        column = n_cols;
        size = n_rows * n_cols;
    }

    vector<int> flip() {
        int rnum = rd() % size--, pos;  // 随机选择一个位置

        // 如果这个位置还没有被翻转，那么翻转它；如果已经被翻转了，那么翻转它映射的位置
        pos = flipped.count(rnum) == 0 ? rnum : flipped[rnum];

        // 将选中的这个位置映射到最后一个位置，如果最后一个位置已经翻转了，那么映射到它翻转时映射的位置
        flipped[rnum] = flipped.count(size) == 0 ? size : flipped[size];
        
        return { pos / column, pos % column };
    }

    void reset() {
        flipped.clear();
        size = row * column;
    }

private:
    random_device rd;
    unordered_map<int, int> flipped;
    int row;
    int column;
    int size;
};

int main()
{
    CheckResult check;

    Solution o1(2, 3);
    vector<vector<int>> expected = { {0,0},{0,1},{0,2},{1,0},{1,1},{1,2} };
    vector<vector<int>> actual;
    for (int i = 0; i < 6; ++i) {
        actual.push_back(o1.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);
    o1.reset();
    actual.clear();
    for (int i = 0; i < 6; ++i) {
        actual.push_back(o1.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    Solution o2(1, 2);
    expected = { {0,0},{0,1} };
    actual.clear();
    for (int i = 0; i < 2; ++i) {
        actual.push_back(o2.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);
    o2.reset();
    actual.clear();
    for (int i = 0; i < 2; ++i) {
        actual.push_back(o2.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    Solution o3(1, 1);
    expected = { {0,0} };
    actual.clear();
    for (int i = 0; i < 1; ++i) {
        actual.push_back(o3.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);
    o3.reset();
    actual.clear();
    for (int i = 0; i < 1; ++i) {
        actual.push_back(o3.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    Solution o4(3, 4);
    expected = { {0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3} };
    actual.clear();
    for (int i = 0; i < 12; ++i) {
        actual.push_back(o4.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);
    o4.reset();
    actual.clear();
    for (int i = 0; i < 12; ++i) {
        actual.push_back(o4.flip());
    }
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);
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
