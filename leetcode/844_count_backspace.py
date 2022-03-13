class Solution:
    def checkEmpty(self, s: str, i: int, cnt: int) -> bool:
        print("%s %d" % (s, i))
        while i >= 0:
            if s[i] != '#':
                if cnt == 0:
                    # This letter can never be erased.
                    return False
                elif cnt > 0:
                    cnt -= 1
            else:
                cnt += 1
                
            i -= 1
            
        return True  
    
    def backspaceCompare(self, s: str, t: str) -> bool:
        # Scan from the end and extrapolate the # characters
        # based on their occurrence. Then scan back from left
        # retaining only the alphabets. Then compare.
        l1 = len(s)
        l2 = len(t)
        
        i = l1 - 1
        j = l2 - 1
        
        cnt1 = 0
        cnt2 = 0
        while i >= 0 and j >= 0:
            if s[i] != '#' and t[j] != '#':
                if cnt1 == 0 and cnt2 == 0:                
                    if s[i] != t[j]:
                        return False

                    i -= 1
                    j -= 1
                else:
                    if cnt1 > 0 :
                        cnt1 -= 1
                        i -= 1
                    if cnt2 > 0 :
                        cnt2 -= 1
                        j -= 1
                        
                continue
                
            if s[i] == '#':
                cnt1 += 1
                i -= 1
                
            if t[j] == '#':
                cnt2 += 1
                j -= 1
        
        if i >= 0 or j >= 0:
            if i >= 0:
                return self.checkEmpty(s, i, cnt1)
            if j >= 0:
                return self.checkEmpty(t, j, cnt2)            
        
        return True
            
            
        