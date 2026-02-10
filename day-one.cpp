#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
==============================
        IMPLEMENT
==============================
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // TODO
    return head;
}

ListNode* reverseList(ListNode* head) {
    // TODO
    return head;
}

ListNode* middleNode(ListNode* head) {
    // TODO
    return head;
}

ListNode* deleteMiddle(ListNode* head) {
    // TODO
    return head;
}

bool isPalindrome(ListNode* head) {
    // TODO
    return false;
}

/*
==============================
        HELPERS
==============================
*/

ListNode* build(const vector<int>& v) {
    if (v.empty()) return NULL;
    ListNode* head = new ListNode(v[0]);
    ListNode* cur = head;
    for (int i = 1; i < v.size(); i++) {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }
    return head;
}

vector<int> toVec(ListNode* head) {
    vector<int> res;
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void assertSafe(ListNode* head, int expected_len) {
    assert(!hasCycle(head));
    assert((int)toVec(head).size() == expected_len);
}

void assertVec(const vector<int>& got, const vector<int>& exp) {
    if (got != exp) {
        cout << "\nExpected: ";
        for (auto x : exp) cout << x << " ";
        cout << "\nGot: ";
        for (auto x : got) cout << x << " ";
        cout << endl;
        assert(false);
    }
}

/*
==============================
            TESTS
==============================
*/

void test_removeNth() {
    auto ans1 = removeNthFromEnd(build({10}), 1);
    assertVec(toVec(ans1), {});
    assertSafe(ans1, 0);

    auto ans2 = removeNthFromEnd(build({1,2,3}), 3);
    assertVec(toVec(ans2), {2,3});
    assertSafe(ans2, 2);

    auto ans3 = removeNthFromEnd(build({1,2,3}), 1);
    assertVec(toVec(ans3), {1,2});
    assertSafe(ans3, 2);

    vector<int> v(40);
    iota(v.begin(), v.end(), 1);
    auto ans4 = removeNthFromEnd(build(v), 17);
    v.erase(v.begin() + (40-17));
    assertVec(toVec(ans4), v);
    assertSafe(ans4, v.size());
}

void test_reverse() {
    auto a = reverseList(NULL);
    assertVec(toVec(a), {});
    assertSafe(a, 0);

    auto b = reverseList(build({1}));
    assertVec(toVec(b), {1});
    assertSafe(b, 1);

    auto c = reverseList(build({1,2,3,4}));
    assertVec(toVec(c), {4,3,2,1});
    assertSafe(c, 4);

    // repeat reverse to catch corruption
    auto d = reverseList(c);
    assertVec(toVec(d), {1,2,3,4});
    assertSafe(d, 4);
}

void test_middle() {
    assert(middleNode(build({1}))->val == 1);
    assert(middleNode(build({1,2}))->val == 2);
    assert(middleNode(build({1,2,3,4,5,6}))->val == 4);
}

void test_deleteMiddle() {
    auto a = deleteMiddle(build({1}));
    assertVec(toVec(a), {});
    assertSafe(a, 0);

    auto b = deleteMiddle(build({1,2,3,4,5}));
    assertVec(toVec(b), {1,2,4,5});
    assertSafe(b, 4);
}

void test_palindrome() {
    auto a = build({1,2,3,2,1});
    assert(isPalindrome(a) == true);
    assertSafe(a, 5);  // ensure not destroyed

    auto b = build({1,2,3,4});
    assert(isPalindrome(b) == false);
    assertSafe(b, 4);
}

int main() {
    test_removeNth();
    test_reverse();
    test_middle();
    test_deleteMiddle();
    test_palindrome();

    cout << "ALL TESTS PASSED 🚀" << endl;
}
