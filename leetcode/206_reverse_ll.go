/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	var currNext *ListNode
	curr := head.Next
	head.Next = nil
	for {
		if curr == nil {
			break
		}

		currNext = curr.Next
		curr.Next = head
		head = curr
		curr = currNext
	}

	return head
}