class LLNode:
    def __init__(self, val):
        self.val = val
        self.next = None

class LL:
    def __init__(self):
        self.head = None
        self.curr = None

    def add(self, n):
        if not self.head:
            self.head = LLNode(n)
            self.curr = self.head
        else:
            self.curr.next = LLNode(n)
            self.curr = self.curr.next

    def addArray(self, nums):
        for x in nums:
            self.add(x)

    def reverse(self):
        curr = self.head.next
        if not curr:
            return
        self.head.next = None
        
        while curr:
            curr_next = curr.next
            curr.next = self.head
            self.head = curr
            curr = curr_next

    def print(self):
        curr = self.head
        while curr:
            print("%d->" % curr.val, end='')
            curr = curr.next
        print()

if __name__ == "__main__":
    ll = LL()
    ll.addArray([1, 2, 3, 4, 5])
    ll.print()

    ll.reverse()
    ll.print()
        

    
