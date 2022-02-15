# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        curr = head
        prev = None
        
        while curr:
            if curr.val != val:
                if not prev:
                    head = curr
                else:
                    prev.next = curr
                prev = curr
            
            curr = curr.next
            
        if prev:
            prev.next = None
        else:
            head = None
            
        return head

                
                
            