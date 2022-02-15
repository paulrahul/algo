/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func add(tail *ListNode, node *ListNode) *ListNode {
	if tail == nil {
		tail = node
	} else {
		tail.Next = node
		tail = tail.Next
	}

	return tail
}

func addRest(tail *ListNode, ll *ListNode) *ListNode {
	if tail == nil {
		tail = ll
	} else {
		tail.Next = ll
	}

	return tail
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	curr1 := list1
	curr2 := list2

	var head *ListNode
	var tail *ListNode

	for {
		if curr1 == nil || curr2 == nil {
			break
		}

		if curr1.Val <= curr2.Val {
			tail = add(tail, curr1)
			curr1 = curr1.Next
		} else {
			tail = add(tail, curr2)
			curr2 = curr2.Next
		}

		if head == nil {
			head = tail
		}
	}

	if curr1 != nil {
		tail = addRest(tail, curr1)
	} else if curr2 != nil {
		tail = addRest(tail, curr2)
	}

	if head == nil {
		head = tail
	}

	return head
}