/* 皇位继承顺序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个王国里住着国王、他的孩子们、他的孙子们等等。每一个时间点，这个家庭里有人出生也有人死亡。

这个王国有一个明确规定的皇位继承顺序，第一继承人总是国王自己。我们定义递归函数 Successor(x, curOrder) ，给定一个人 x 和当前的继承顺序，该函数返回 x 的下一继承人。

Successor(x, curOrder):
    如果 x 没有孩子或者所有 x 的孩子都在 curOrder 中：
        如果 x 是国王，那么返回 null
        否则，返回 Successor(x 的父亲, curOrder)
    否则，返回 x 不在 curOrder 中最年长的孩子
比方说，假设王国由国王，他的孩子 Alice 和 Bob （Alice 比 Bob 年长）和 Alice 的孩子 Jack 组成。

一开始， curOrder 为 ["king"].
调用 Successor(king, curOrder) ，返回 Alice ，所以我们将 Alice 放入 curOrder 中，得到 ["king", "Alice"] 。
调用 Successor(Alice, curOrder) ，返回 Jack ，所以我们将 Jack 放入 curOrder 中，得到 ["king", "Alice", "Jack"] 。
调用 Successor(Jack, curOrder) ，返回 Bob ，所以我们将 Bob 放入 curOrder 中，得到 ["king", "Alice", "Jack", "Bob"] 。
调用 Successor(Bob, curOrder) ，返回 null 。最终得到继承顺序为 ["king", "Alice", "Jack", "Bob"] 。
通过以上的函数，我们总是能得到一个唯一的继承顺序。

请你实现 ThroneInheritance 类：

ThroneInheritance(string kingName) 初始化一个 ThroneInheritance 类的对象。国王的名字作为构造函数的参数传入。
void birth(string parentName, string childName) 表示 parentName 新拥有了一个名为 childName 的孩子。
void death(string name) 表示名为 name 的人死亡。一个人的死亡不会影响 Successor 函数，也不会影响当前的继承顺序。你可以只将这个人标记为死亡状态。
string[] getInheritanceOrder() 返回 除去 死亡人员的当前继承顺序列表。
 

示例：

输入：
["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
[["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]
输出：
[null, null, null, null, null, null, null, ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", "alex", "asha", "catherine"]]

解释：
ThroneInheritance t= new ThroneInheritance("king"); // 继承顺序：king
t.birth("king", "andy"); // 继承顺序：king > andy
t.birth("king", "bob"); // 继承顺序：king > andy > bob
t.birth("king", "catherine"); // 继承顺序：king > andy > bob > catherine
t.birth("andy", "matthew"); // 继承顺序：king > andy > matthew > bob > catherine
t.birth("bob", "alex"); // 继承顺序：king > andy > matthew > bob > alex > catherine
t.birth("bob", "asha"); // 继承顺序：king > andy > matthew > bob > alex > asha > catherine
t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
t.death("bob"); // 继承顺序：king > andy > matthew > bob（已经去世）> alex > asha > catherine
t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
 

提示：

1 <= kingName.length, parentName.length, childName.length, name.length <= 15
kingName，parentName， childName 和 name 仅包含小写英文字母。
所有的参数 childName 和 kingName 互不相同。
所有 death 函数中的死亡名字 name 要么是国王，要么是已经出生了的人员名字。
每次调用 birth(parentName, childName) 时，测试用例都保证 parentName 对应的人员是活着的。
最多调用 105 次birth 和 death 。
最多调用 10 次 getInheritanceOrder 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/throne-inheritance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Person {
public:
    Person(int _id, string& _name) : id(_id), name(_name), isDead(false) {}
    int id;
    string name;
    vector<int> children;
    bool isDead;
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        Person king(0, kingName);
        nameIds[kingName] = 0;
        persons.push_back(king);
        id = 0;
    }

    void birth(string parentName, string childName) {
        Person child(++id, childName);
        nameIds[childName] = id;
        persons.push_back(child);
        persons[nameIds[parentName]].children.push_back(id);
    }

    void death(string name) {
        persons[nameIds[name]].isDead = true;
    }

    vector<string> getInheritanceOrder() {
        vector<string> curOrder;

        Successor(0, curOrder);

        return curOrder;
    }

    void Successor(int id, vector<string>& curOrder) {
        // Successor函数翻译为人话就是孩子有优先继承权，如果所有孩子都没有了，再从兄弟里面找
        Person& person = persons[id];

        if (!person.isDead) {
            curOrder.push_back(person.name);
        }

        for (int child : person.children) {
            Successor(child, curOrder);
        }
    }

private:
    vector<Person> persons;
    unordered_map<string, int> nameIds;
    int id;
};

int main()
{
    CheckResult check;

    ThroneInheritance o1("king");
    o1.birth("king", "andy");
    o1.birth("king", "bob");
    o1.birth("king", "catherine");
    o1.birth("andy", "matthew");
    o1.birth("bob", "alex");
    o1.birth("bob", "asha");
    vector<string> actual = o1.getInheritanceOrder();
    vector<string> expected = { "king", "andy", "matthew", "bob", "alex", "asha", "catherine" };
    check.checkStringVector(expected, actual);
    o1.death("bob");
    actual = o1.getInheritanceOrder();
    expected = { "king", "andy", "matthew", "alex", "asha", "catherine" };
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
