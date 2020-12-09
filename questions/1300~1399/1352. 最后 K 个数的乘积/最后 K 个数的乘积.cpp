/* 最后 K 个数的乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你实现一个「数字乘积类」ProductOfNumbers，要求支持下述两种方法：

1. add(int num)

将数字 num 添加到当前数字列表的最后面。
2. getProduct(int k)

返回当前数字列表中，最后 k 个数字的乘积。
你可以假设当前列表中始终 至少 包含 k 个数字。
题目数据保证：任何时候，任一连续数字序列的乘积都在 32-bit 整数范围内，不会溢出。

 

示例：

输入：
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

输出：
[null,null,null,null,null,null,20,40,0,null,32]

解释：
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32
 

提示：

add 和 getProduct 两种操作加起来总共不会超过 40000 次。
0 <= num <= 100
1 <= k <= 40000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-the-last-k-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        preProduct.push_back(1);
        count = 0;
    }

    void add(int num) {
        if (num == 0) {
            preProduct.clear();
            preProduct.push_back(1);
            count = 0;
        }
        else {
            preProduct.push_back(num * preProduct.back());
            ++count;
        }
    }

    int getProduct(int k) {
        if (k > count) {
            return 0;
        }

        return preProduct.back() / preProduct[preProduct.size() - k - 1];
    }

private:
    vector<int> preProduct;
    int count;
};

int main()
{
    CheckResult check;

    ProductOfNumbers o1;
    o1.add(3);
    o1.add(0);
    o1.add(2);
    o1.add(5);
    o1.add(4);
    check.checkInt(20, o1.getProduct(2));
    check.checkInt(40, o1.getProduct(3));
    check.checkInt(0, o1.getProduct(4));
    o1.add(8);
    check.checkInt(32, o1.getProduct(2));
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
