/* 设计哈希集合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
不使用任何内建的哈希表库设计一个哈希集合

具体地说，你的设计应该包含以下的功能

add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

示例:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);        
hashSet.add(2);        
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)

注意：

所有的值都在 [0, 1000000]的范围内。
操作的总数目在[1, 10000]范围内。
不要使用内建的哈希集合库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        self = 997;
        buckets = new list<int>[self]();
    }

    ~MyHashSet() {
        delete[] buckets;
    }

    int hash(int key) {
        return key % self;
    }

    void add(int key) {
        int hashValue = hash(key);
        list<int>& bucket = buckets[hashValue];
        for (auto iter = bucket.begin(); iter != bucket.end(); iter++) {
            if (*iter == key) {
                return;
            }
        }
        bucket.push_back(key);
    }

    void remove(int key) {
        int hashValue = hash(key);
        list<int>& bucket = buckets[hashValue];
        for (auto iter = bucket.begin(); iter != bucket.end(); iter++) {
            if (*iter == key) {
                bucket.erase(iter);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashValue = hash(key);
        list<int>& bucket = buckets[hashValue];
        for (auto iter = bucket.begin(); iter != bucket.end(); iter++) {
            if (*iter == key) {
                return true;
            }
        }
        return false;
    }

    int self;
    list<int>* buckets;
};

int main()
{
    CheckResult check;
    MyHashSet o;

    check.checkBool(false, o.contains(0));
    o.add(0);
    check.checkBool(true, o.contains(0));
    o.remove(0);
    check.checkBool(false, o.contains(0));

    check.checkBool(false, o.contains(1));
    o.add(1);
    check.checkBool(true, o.contains(1));
    o.add(1);
    check.checkBool(true, o.contains(1));
    o.remove(1);
    check.checkBool(false, o.contains(1));
    o.remove(1);
    check.checkBool(false, o.contains(1));

    check.checkBool(false, o.contains(2));
    o.add(2);
    check.checkBool(true, o.contains(2));
    o.add(3);
    check.checkBool(true, o.contains(3));
    o.add(999);
    check.checkBool(true, o.contains(999));
    o.add(1000);
    check.checkBool(true, o.contains(1000));
    o.remove(2);
    check.checkBool(false, o.contains(2));
    o.remove(3);
    check.checkBool(false, o.contains(3));
    o.remove(999);
    check.checkBool(false, o.contains(999));
    o.remove(1000);
    check.checkBool(false, o.contains(1000));
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
