/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	currVal := -200

	var prev *ListNode
	curr := head

	for {
		if curr == nil {
			break
		}

		if curr.Val != currVal {
			// New unique value.
			if prev == nil {
				prev = head
			} else {
				prev.Next = curr
				prev = curr
			}
			currVal = prev.Val
		}

		curr = curr.Next
	}

	if prev != nil {
		prev.Next = nil
	}

	return head
}