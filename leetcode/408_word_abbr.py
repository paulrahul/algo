class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        sl = len(word)
        al = len(abbr)
        
        s_idx = a_idx = 0
        
        while a_idx < al and s_idx < sl:            
            ch =  abbr[a_idx]
            
            if ch == '0':
                return False
            
            if ch >= '1' and ch <= '9':
                # parse number
                num_s = ""
                while a_idx < al and abbr[a_idx] >= '0' and abbr[a_idx] <= '9':
                    num_s += abbr[a_idx]
                    a_idx += 1
                    
                num = int(num_s)
                s_idx += num
            else:
                if ch != word[s_idx]:
                    return False
                a_idx += 1
                s_idx += 1
                
        return a_idx == al and s_idx == sl
        