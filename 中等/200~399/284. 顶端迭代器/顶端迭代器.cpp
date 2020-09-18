/* 顶端迭代器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个迭代器类的接口，接口包含两个方法： next() 和 hasNext()。设计并实现一个支持 peek() 操作的顶端迭代器 -- 其本质就是把原本应由 next() 方法返回的元素 peek() 出来。

示例:

假设迭代器被初始化为列表 [1,2,3]。

调用 next() 返回 1，得到列表中的第一个元素。
现在调用 peek() 返回 2，下一个元素。在此之后调用 next() 仍然返回 2。
最后一次调用 next() 返回 3，末尾元素。在此之后调用 hasNext() 应该返回 false。
进阶：你将如何拓展你的设计？使之变得通用化，从而适应所有的类型，而不只是整数型？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/peeking-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/Iterator.h"
#include "../check/CheckResult.h"

using namespace std;

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		nextCache = 0;
		cached = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!cached) {
			nextCache = Iterator::next();
			cached = true;
		}

		return nextCache;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (cached) {
			cached = false;
			return nextCache;
		}
		else {
			return Iterator::next();
		}
	}

	bool hasNext() const {
		if (cached) {
			return true;
		}
		else {
			return Iterator::hasNext();
		}
	}

	int nextCache;
	bool cached;
};

int main()
{
    CheckResult check;

	vector<int> nums = {};
	PeekingIterator o1(nums);
	check.checkBool(false, o1.hasNext());

	nums = { 5 };
	PeekingIterator o2(nums);
	check.checkBool(true, o2.hasNext());
	check.checkInt(5, o2.peek());
	check.checkInt(5, o2.peek());
	check.checkInt(5, o2.next());
	check.checkBool(false, o2.hasNext());

	nums = { 1,2,3 };
	PeekingIterator o3(nums);
	check.checkBool(true, o3.hasNext());
	check.checkInt(1, o3.next());
	check.checkInt(2, o3.peek());
	check.checkInt(2, o3.peek());
	check.checkInt(2, o3.next());
	check.checkInt(3, o3.peek());
	check.checkInt(3, o3.peek());
	check.checkInt(3, o3.peek());
	check.checkBool(true, o3.hasNext());
	check.checkInt(3, o3.next());
	check.checkBool(false, o3.hasNext());
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
