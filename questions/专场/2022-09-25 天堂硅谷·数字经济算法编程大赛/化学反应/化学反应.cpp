/* 化学反应.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实验室内有一些化学反应物，其中的任意两种反应物之间都能发生反应，且质量的消耗量为 1:1

已知初始 material[i] 表示第 i 种反应物的质量，每次进行实验时，会选出当前 质量最大 的两种反应物进行反应，假设反应物的重量分别为 i 和 j ，且 i <= j。反应的结果如下：

如果 i == j，那么两种化学反应物都将被消耗完；
如果 i < j，那么质量为 i 的反应物将会完全消耗，而质量为 j 的反应物质量变为 j - i 。
最后，最多只会剩下一种反应物，返回此反应物的质量。如果没有反应物剩下，返回 0。



示例 1：

输入：[10,2,6,1]
输出：1
解释：
先选出 10 和 6，得到 4，数组转换为 [4,2,1]，
再选出 4 和 2，得到 2，数组转换为 [2,1]，
最后选出 2 和 1，得到 1，最终数组转换为 [1]，这就是最后剩下反应物的质量。


示例 2：

输入：[6,4,10]
输出：0
解释：
先选出 10 和 6，得到 4，所以数组转换为 [4,4]，
再选出 4 和 4，得到 0，所以数组转换为 []
因为没有反应物剩下，返回 0。


提示：

1 <= material.length <= 30
1 <= material[i] <= 1000
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lastMaterial(vector<int>& material) {
        priority_queue<int> materials;

        for (int mat : material) {
            materials.push(mat);
        }

        while (materials.size() > 1) {
            int mat1 = materials.top();
            materials.pop();
            int mat2 = materials.top();
            materials.pop();

            if (mat1 != mat2) {
                materials.push(mat1 - mat2);
            }
        }

        return materials.empty() ? 0 : materials.top();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> material = { 10,2,6,1 };
    check.checkInt(1, o.lastMaterial(material));

    material = { 6,4,10 };
    check.checkInt(0, o.lastMaterial(material));
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
