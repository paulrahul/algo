# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> (Optional[ListNode], int):
        ptr1 = ptr2 = head
        total_count = 1
        
        while ptr2.next:
            ptr1 = ptr1.next
            
            ptr2 = ptr2.next
            total_count += 1
            if ptr2.next:
                ptr2 = ptr2.next
                total_count += 1
                
        return ptr1, total_count
    
    def reverse(self, start: Optional[ListNode]) -> Optional[ListNode]:
        if not start:
            return start
        
        curr = start.next
        if not curr:
            return start
        
        start.next = None
        
        while curr:
            curr_next = curr.next
            curr.next = start
            start = curr
            curr = curr_next
            
        return start
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        mid, cnt = self.middleNode(head)
        
        if cnt % 2 == 1:
            mid = mid.next
            
        mid = self.reverse(mid)
        
        curr1 = head
        curr2 = mid
        while curr2:            
            if curr1.val != curr2.val:
                return False
            
            curr1 = curr1.next
            curr2 = curr2.next
            
        return True
