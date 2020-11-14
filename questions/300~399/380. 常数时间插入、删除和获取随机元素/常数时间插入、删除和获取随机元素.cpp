/* 常数时间插入、删除和获取随机元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
示例 :

// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto iter = keyIndexs.find(val);
        if (iter != keyIndexs.end()) {
            return false;
        }

        keys.push_back(val);
        keyIndexs[val] = keys.size() - 1;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = keyIndexs.find(val);
        if (iter == keyIndexs.end()) {
            return false;
        }

        keyIndexs[keys.back()] = iter->second;
        swap(keys[iter->second], keys.back());
        keys.pop_back();
        keyIndexs.erase(iter);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (keys.empty()) {
            return 0;
        }

        int index = rd() % keys.size();
        return keys[index];
    }

    unordered_map<int, int> keyIndexs;
    vector<int> keys;
    random_device rd;
};

int main()
{
    RandomizedSet o;
    CheckResult check;

    check.checkBool(false, o.remove(1));
    check.checkBool(true, o.insert(1));
    check.checkBool(false, o.insert(1));
    check.checkInt(1, o.getRandom());
    check.checkBool(false, o.remove(2));
    check.checkBool(true, o.insert(2));
    check.checkBool(false, o.insert(2));
    check.checkBool(true, o.insert(3));
    check.checkBool(true, o.insert(4));
    check.checkBool(true, o.insert(5));
    check.checkBool(true, o.insert(6));
    check.checkBool(true, o.insert(7));
    check.checkBool(true, o.insert(8));
    check.checkBool(true, o.insert(9));
    for (int i = 0; i < 20; i++) {
        cout << o.getRandom() << " ";
    }
    cout << endl;
    check.checkBool(true, o.remove(3));
    check.checkBool(true, o.remove(4));
    check.checkBool(true, o.remove(5));
    check.checkBool(true, o.remove(6));
    check.checkBool(true, o.remove(7));
    check.checkBool(true, o.remove(8));
    check.checkBool(true, o.remove(9));
    check.checkBool(true, o.remove(2));
    check.checkBool(true, o.remove(1));
    check.checkBool(false, o.remove(1));
    check.checkBool(false, o.remove(2));
    check.checkBool(false, o.remove(3));
    check.checkBool(false, o.remove(4));
    check.checkBool(false, o.remove(5));
    check.checkBool(false, o.remove(6));
    check.checkBool(false, o.remove(7));
    check.checkBool(false, o.remove(8));
    check.checkBool(false, o.remove(9));
    check.checkBool(false, o.remove(10));
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
