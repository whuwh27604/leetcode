/* 二叉树寻路.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。

如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；

而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。



给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。

 

示例 1：

输入：label = 14
输出：[1,3,4,14]
示例 2：

输入：label = 26
输出：[1,2,6,10,26]
 

提示：

1 <= label <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int direction = 0, end = 1;

        while (end < label) {
            end = (end << 1) | 1;
            direction ^= 1;
        }

        vector<int> path;
        int start = (end + 1) >> 1;
        int target = (direction == 0) ? label : mirror(label, start, end);
        int root = 1, left = start, right = end;
        path.push_back(root);
        direction = 0;
        start = end = 1;

        while (root != target) {
            start <<= 1;
            end = (end << 1) | 1;
            direction ^= 1;
            root <<= 1;
            int middle = (left + right + 1) / 2;
            if (target < middle) {
                right = middle - 1;
            }
            else {
                left = middle;
                root += 1;
            }
            path.push_back(direction == 0 ? root : mirror(root, start, end));
        }

        return path;
    }

    int mirror(int label, int start, int end) {
        return start + end - label;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.pathInZigZagTree(14);
    vector<int> expected = { 1,3,4,14 };
    check.checkIntVector(expected, actual);

    actual = o.pathInZigZagTree(26);
    expected = { 1,2,6,10,26 };
    check.checkIntVector(expected, actual);

    actual = o.pathInZigZagTree(1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    actual = o.pathInZigZagTree(2);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    actual = o.pathInZigZagTree(3);
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    actual = o.pathInZigZagTree(16);
    expected = { 1,3,4,15,16 };
    check.checkIntVector(expected, actual);

    actual = o.pathInZigZagTree(31);
    expected = { 1,2,7,8,31 };
    check.checkIntVector(expected, actual);

    actual = o.pathInZigZagTree(1000000);
    expected = { 1,3,4,15,17,61,69,244,279,976,1118,3906,4475,15625,17901,62500,71607,250000,286431,1000000 };
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
