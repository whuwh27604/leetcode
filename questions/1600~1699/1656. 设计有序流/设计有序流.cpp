/* 设计有序流.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个 (id, value) 对，其中 id 是 1 到 n 之间的一个整数，value 是一个字符串。不存在 id 相同的两个 (id, value) 对。

设计一个流，以 任意 顺序获取 n 个 (id, value) 对，并在多次调用时 按 id 递增的顺序 返回一些值。

实现 OrderedStream 类：

OrderedStream(int n) 构造一个能接收 n 个值的流，并将当前指针 ptr 设为 1 。
String[] insert(int id, String value) 向流中存储新的 (id, value) 对。存储后：
如果流存储有 id = ptr 的 (id, value) 对，则找出从 id = ptr 开始的 最长 id 连续递增序列 ，并 按顺序 返回与这些 id 关联的值的列表。然后，将 ptr 更新为最后那个  id + 1 。
否则，返回一个空列表。

 

示例：



输入
["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
输出
[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

解释
OrderedStream os= new OrderedStream(5);
os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
 

提示：

1 <= n <= 1000
1 <= id <= n
value.length == 5
value 仅由小写字母组成
每次调用 insert 都会使用一个唯一的 id
恰好调用 n 次 insert

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-an-ordered-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        pointer = 1;
        size = n + 2;
        data.resize(size);
    }

    vector<string> insert(int idKey, string value) {
        data[idKey] = value;

        vector<string> orderedStream;
        int ptr = pointer;

        while (!data[ptr].empty()) {
            orderedStream.push_back(data[ptr++]);
        }

        pointer = ptr;
        return orderedStream;
    }

private:
    vector<string> data;
    int size;
    int pointer;
};

int main()
{
    CheckResult check;

    OrderedStream o1(5);
    vector<string> actual = o1.insert(3, "ccccc");
    vector<string> expected = {};
    check.checkStringVector(expected, actual);
    actual = o1.insert(1, "aaaaa");
    expected = { "aaaaa" };
    check.checkStringVector(expected, actual);
    actual = o1.insert(2, "bbbbb");
    expected = { "bbbbb", "ccccc" };
    check.checkStringVector(expected, actual);
    actual = o1.insert(5, "eeeee");
    expected = {};
    check.checkStringVector(expected, actual);
    actual = o1.insert(4, "ddddd");
    expected = { "ddddd", "eeeee" };
    check.checkStringVector(expected, actual);

    OrderedStream o2(1);
    actual = o2.insert(1, "ddddd");
    expected = { "ddddd" };
    check.checkStringVector(expected, actual);
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
