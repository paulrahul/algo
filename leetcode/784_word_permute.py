from typing import List

class Solution:
    ans = []
    
    def clear(self):
        self.ans = []

    def permute(self, s: str, idx: int):
        l = len(s)
        if idx >= l:
            return
        
        self.permute(s, idx + 1)
        
        n = len(self.ans)
        ch = s[idx]
        if ch >= '0' and ch <= '9':
            if idx == l - 1:
                self.ans.append(ch)
            else:
                for i in range(n):
                    self.ans[i] = ch + self.ans[i]
                
            return

        ch2 = ch
        if ch >= 'a' and ch <= 'z':
            ch2 = ch.upper()
        else:
            ch2 = ch.lower()

        if idx == l - 1:
            self.ans.append(ch)
            self.ans.append(ch2)
        else:   
            for i in range(n):
                prev = self.ans[i]
                self.ans[i] = ch + prev
                self.ans.append(ch2 + prev)
    
    def letterCasePermutation(self, s: str) -> List[str]:
        self.clear()
        self.permute(s, 0)
        return self.ans

if __name__ == "__main__":
    o = Solution()
    print(o.letterCasePermutation("a1b2"))
    print(o.letterCasePermutation("3z4"))
    print(o.letterCasePermutation("1"))
    print(o.letterCasePermutation("1111"))
    print(o.letterCasePermutation("a"))
    print(o.letterCasePermutation("aaaa"))
    print(o.letterCasePermutation("aB"))
    print(o.letterCasePermutation("1aaaaaaa"))                           