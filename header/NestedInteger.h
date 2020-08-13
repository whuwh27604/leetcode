#ifndef __NESTED_INTEGER_H__
#define __NESTED_INTEGER_H__

#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger() : singleInteger(false) {}

    // Constructor initializes a single integer.
    NestedInteger(int _val) : val(_val), singleInteger(true) {}

    NestedInteger(int _val, bool _single) : val(_val), singleInteger(_single) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni);

private:
    int val;
    bool singleInteger;
    vector<NestedInteger> data;
};

bool NestedInteger::isInteger() const {
    return singleInteger;
}

int NestedInteger::getInteger() const {
    return val;
}

const vector<NestedInteger>& NestedInteger::getList() const {
    return data;
}

void NestedInteger::add(const NestedInteger& ni) {
    data.push_back(ni);
}

#endif