/* 扁平化嵌套列表迭代器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

 

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-nested-list-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/NestedInteger.h"
#include "../check/CheckResult.h"

using namespace std;

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        while (!nestedList.empty()) {
            NestedInteger integer = nestedList.back();
            nestedList.pop_back();

            if (integer.isInteger()) {
                singleIntegers.push(integer.getInteger());
            }
            else {
                vector<NestedInteger> list = integer.getList();
                for (NestedInteger i : list) {
                    nestedList.push_back(i);
                }
            }
        }
    }

    int next() {
        int n = singleIntegers.top();
        singleIntegers.pop();
        return n;
    }

    bool hasNext() {
        return !singleIntegers.empty();
    }

    stack<int> singleIntegers;
};

int main()
{
    CheckResult check;

    NestedInteger I1(1, true);
    NestedInteger I2(1, true);
    NestedInteger I3(0, false);
    I3.add(I1);
    I3.add(I2);
    NestedInteger I4(2, true);
    NestedInteger I5(1, true);
    NestedInteger I6(1, true);
    NestedInteger I7(0, false);
    I7.add(I5);
    I7.add(I6);
    NestedInteger I8(0, false);
    I8.add(I3);
    I8.add(I4);
    I8.add(I7);
    vector<NestedInteger> nestedList = I8.getList();
    NestedIterator o(nestedList);
    check.checkBool(true, o.hasNext());
    check.checkInt(1, o.next());
    check.checkBool(true, o.hasNext());
    check.checkInt(1, o.next());
    check.checkBool(true, o.hasNext());
    check.checkInt(2, o.next());
    check.checkBool(true, o.hasNext());
    check.checkInt(1, o.next());
    check.checkBool(true, o.hasNext());
    check.checkInt(1, o.next());
    check.checkBool(false, o.hasNext());

    NestedInteger I21(6, true);
    NestedInteger I22(0, false);
    I22.add(I21);
    NestedInteger I23(4, true);
    NestedInteger I24(0, false);
    I24.add(I23);
    I24.add(I22);
    NestedInteger I25(1, true);
    NestedInteger I26(0, false);
    I26.add(I25);
    I26.add(I24);
    nestedList = I26.getList();
    NestedIterator o2(nestedList);
    check.checkBool(true, o2.hasNext());
    check.checkInt(1, o2.next());
    check.checkBool(true, o2.hasNext());
    check.checkInt(4, o2.next());
    check.checkBool(true, o2.hasNext());
    check.checkInt(6, o2.next());
    check.checkBool(false, o2.hasNext());

    nestedList = {};
    NestedIterator o3(nestedList);
    check.checkBool(false, o3.hasNext());

    NestedInteger I41(0, false);
    nestedList = I41.getList();
    NestedIterator o4(nestedList);
    check.checkBool(false, o4.hasNext());

    NestedInteger I51(5, true);
    NestedInteger I52(0, false);
    NestedInteger I53(0, false);
    I53.add(I52);
    I53.add(I51);
    nestedList = I53.getList();
    NestedIterator o5(nestedList);
    check.checkBool(true, o5.hasNext());
    check.checkInt(5, o5.next());
    check.checkBool(false, o5.hasNext());

    NestedInteger I61(3, true);
    NestedInteger I62(0, false);
    I62.add(I61);
    NestedInteger I63(9, true);
    NestedInteger I64(8, true);
    NestedInteger I65(0, false);
    I65.add(I63);
    I65.add(I61);
    I65.add(I64);
    NestedInteger I66(6, true);
    NestedInteger I67(7, true);
    NestedInteger I68(0, false);
    I68.add(I66);
    I68.add(I65);
    I68.add(I67);
    NestedInteger I69(4, true);
    NestedInteger I610(5, true);
    NestedInteger I611(0, false);
    I611.add(I69);
    I611.add(I68);
    I611.add(I610);
    NestedInteger I612(1, true);
    NestedInteger I613(2, true);
    NestedInteger I614(0, false);
    I614.add(I612);
    I614.add(I611);
    I614.add(I613);
    nestedList = I614.getList();
    NestedIterator o6(nestedList);
    check.checkBool(true, o6.hasNext());
    check.checkInt(1, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(4, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(6, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(9, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(3, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(8, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(7, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(5, o6.next());
    check.checkBool(true, o6.hasNext());
    check.checkInt(2, o6.next());
    check.checkBool(false, o6.hasNext());
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
