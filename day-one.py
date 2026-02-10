from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
==============================
        IMPLEMENT
==============================
"""

def removeNthFromEnd(head: Optional[ListNode], n: int) -> Optional[ListNode]:
    # TODO
    return head


def reverseList(head: Optional[ListNode]) -> Optional[ListNode]:
    # TODO
    return head


def middleNode(head: Optional[ListNode]) -> Optional[ListNode]:
    # TODO
    return head


def deleteMiddle(head: Optional[ListNode]) -> Optional[ListNode]:
    # TODO
    return head


def isPalindrome(head: Optional[ListNode]) -> bool:
    # TODO
    return False


"""
==============================
        HELPERS
==============================
"""

def build(arr: List[int]) -> Optional[ListNode]:
    if not arr:
        return None
    head = ListNode(arr[0])
    cur = head
    for x in arr[1:]:
        cur.next = ListNode(x)
        cur = cur.next
    return head


def to_list(head: Optional[ListNode]) -> List[int]:
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res


def has_cycle(head: Optional[ListNode]) -> bool:
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False


def assert_safe(head: Optional[ListNode], expected_len: int):
    assert not has_cycle(head)
    assert len(to_list(head)) == expected_len


"""
==============================
            TESTS
==============================
"""

def test_removeNth():
    a = removeNthFromEnd(build([10]), 1)
    assert to_list(a) == []
    assert_safe(a, 0)

    b = removeNthFromEnd(build([1,2,3]), 3)
    assert to_list(b) == [2,3]
    assert_safe(b, 2)

    v = list(range(1, 41))
    exp = v.copy()
    exp.pop(len(v) - 17)
    c = removeNthFromEnd(build(v), 17)
    assert to_list(c) == exp
    assert_safe(c, len(exp))


def test_reverse():
    a = reverseList(None)
    assert to_list(a) == []
    assert_safe(a, 0)

    b = reverseList(build([1,2,3,4]))
    assert to_list(b) == [4,3,2,1]
    assert_safe(b, 4)

    # reverse again
    c = reverseList(b)
    assert to_list(c) == [1,2,3,4]
    assert_safe(c, 4)


def test_middle():
    assert middleNode(build([1])).val == 1
    assert middleNode(build([1,2])).val == 2
    assert middleNode(build([1,2,3,4,5,6])).val == 4


def test_deleteMiddle():
    a = deleteMiddle(build([1]))
    assert to_list(a) == []
    assert_safe(a, 0)

    b = deleteMiddle(build([1,2,3,4,5]))
    assert to_list(b) == [1,2,4,5]
    assert_safe(b, 4)


def test_palindrome():
    a = build([1,2,3,2,1])
    assert isPalindrome(a) is True
    assert_safe(a, 5)

    b = build([1,2,3,4])
    assert isPalindrome(b) is False
    assert_safe(b, 4)


if __name__ == "__main__":
    test_removeNth()
    test_reverse()
    test_middle()
    test_deleteMiddle()
    test_palindrome()

    print("ALL TESTS PASSED 🚀")
