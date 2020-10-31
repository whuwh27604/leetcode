/* O(1) 时间插入、删除和获取随机元素 - 允许重复.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。

注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
示例:

// 初始化一个空的集合。
RandomizedCollection collection = new RandomizedCollection();

// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);

// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(1);

// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.insert(2);

// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.getRandom();

// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.remove(1);

// getRandom 应有相同概率返回 1 和 2 。
collection.getRandom();

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include "../check/CheckResult.h"

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        indices[val].insert(nums.size() - 1);

        return indices[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (indices[val].empty()) {
            return false;
        }

        int index = *indices[val].begin();
        int lastIndex = nums.size() - 1;
        int lastNum = nums[lastIndex];

        if (val == lastNum) {
            index = lastIndex;
        }
        else {
            indices[lastNum].erase(lastIndex);
            indices[lastNum].insert(index);
            swap(nums[index], nums[lastIndex]);
        }

        indices[val].erase(index);
        nums.pop_back();

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rd() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> indices;
    random_device rd;
};

int main()
{
    CheckResult check;

    RandomizedCollection o1;
    check.checkBool(false, o1.remove(1));
    check.checkBool(true, o1.insert(1));
    check.checkBool(false, o1.insert(1));
    check.checkBool(true, o1.insert(2));
    cout << o1.getRandom() << endl;
    cout << o1.getRandom() << endl;
    cout << o1.getRandom() << endl;
    check.checkBool(true, o1.remove(1));
    cout << o1.getRandom() << endl;
    cout << o1.getRandom() << endl;

    RandomizedCollection o2;
    check.checkBool(true, o2.insert(1));
    check.checkBool(false, o2.insert(1));
    check.checkBool(true, o2.insert(2));
    check.checkBool(false, o2.insert(1));
    check.checkBool(false, o2.insert(2));
    check.checkBool(false, o2.insert(2));
    check.checkBool(true, o2.remove(1));
    check.checkBool(true, o2.remove(2));
    check.checkBool(true, o2.remove(2));
    check.checkBool(true, o2.remove(2));
    cout << o2.getRandom() << endl;
    cout << o2.getRandom() << endl;
    cout << o2.getRandom() << endl;
    cout << o2.getRandom() << endl;
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
