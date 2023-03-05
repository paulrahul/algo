class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        l = len(s)

        ans = ""
        r = 1
        while r <= numRows and r <= l:
            i = r - 1
            ans += s[i]

            # Compute gap.
            # Gap will be equal to number of rows below, added twice
            # or number of rows above, added twice. Below and above will
            # keep alternating, starting with below.

            below = True
            while True:
                if (below and r != numRows) or r == 1:
                    gap = numRows - r
                    if gap > 1:
                        gap += gap - 1
                else:
                    gap = r - 1
                    if r - 1 > 1:
                        gap += r - 2

                if i + gap + 1 < l:
                    i = i + gap + 1
                    ans += s[i]
                else:
                    break

                below = not below

            r += 1

        return ans

if __name__ == "__main__":
    o = Solution()

    print(o.convert("PAYPALISHIRING", 3))
    print(o.convert("PAYPALISHIRING", 4))
    print(o.convert("A", 1))    
    print(o.convert("A", 2))    