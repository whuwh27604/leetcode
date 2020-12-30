/* 设计哈希映射.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
不使用任何内建的哈希表库设计一个哈希映射

具体地说，你的设计应该包含以下的功能

put(key, value)：向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。
get(key)：返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
remove(key)：如果映射中存在这个键，删除这个数值对。

示例：

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);        
hashMap.get(1);            // 返回 1
hashMap.get(3);            // 返回 -1 (未找到)
hashMap.put(2, 1);         // 更新已有的值
hashMap.get(2);            // 返回 1
hashMap.remove(2);         // 删除键为2的数据
hashMap.get(2);            // 返回 -1 (未找到)

注意：

所有的值都在 [0, 1000000]的范围内。
操作的总数目在[1, 10000]范围内。
不要使用内建的哈希库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashmap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        self = 997;
        buckets = new list<pair<int, int>>[self];
    }

    ~MyHashMap() {
        delete[] buckets;
    }

    int hash(int key) {
        return key % self;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashValue = hash(key);
        list<pair<int, int>>& bucket = buckets[hashValue];
        for (auto iter = bucket.begin(); iter != bucket.end(); iter++) {
            if ((*iter).first == key) {
                (*iter).second = value;
                return;
            }
        }

        bucket.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashValue = hash(key);
        list<pair<int, int>>& bucket = buckets[hashValue];
        for (auto iter = bucket.begin(); iter != bucket.end(); iter++) {
            if ((*iter).first == key) {
                return (*iter).second;
            }
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashValue = hash(key);
        list<pair<int, int>>& bucket = buckets[hashValue];
        for (auto iter = bucket.begin(); iter != bucket.end(); iter++) {
            if ((*iter).first == key) {
                bucket.erase(iter);
                return;
            }
        }
    }

    int self;
    list<pair<int, int>>* buckets;
};

int main()
{
    CheckResult check;
    MyHashMap o;

    o.put(1, 1);
    check.checkInt(1, o.get(1));
    o.put(2, 2);
    check.checkInt(2, o.get(2));
    check.checkInt(-1, o.get(3));
    o.put(2, 1);
    check.checkInt(1, o.get(2));
    o.remove(2);
    check.checkInt(-1, o.get(2));

    o.put(0, 0);
    check.checkInt(0, o.get(0));
    o.put(997, 1);
    check.checkInt(1, o.get(997));
    o.put(997, 2);
    check.checkInt(2, o.get(997));
    o.put(997, 2);
    check.checkInt(2, o.get(997));
    o.remove(997);
    check.checkInt(-1, o.get(997));
    o.remove(997);
    check.checkInt(-1, o.get(997));
    o.remove(0);
    check.checkInt(-1, o.get(0));
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
