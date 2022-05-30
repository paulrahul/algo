from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])

        gap = 0
        side = 0 # 0: T, 1: R, 2: B, 3: L
        
        sz = m * n
        ret = [None] * sz
        idx = 0
        
        while idx < sz:
            # 0 and 2 are rows
            fixed_row = True if side % 2 == 0 else False
                
            if fixed_row:
                if side == 0:
                    row = gap
                    start = gap
                    end = n - gap - 1
                else:
                    row = m - gap - 1
                    start = n - gap - 2
                    end = gap
            else:
                if side == 1:
                    col = n - gap - 1
                    start = gap + 1
                    end = m - gap - 1
                else:
                    col = gap
                    start = m - gap - 2
                    end = gap + 1

            num_elements = min(abs(end - start) + 1, sz - idx)
            
            if fixed_row:
                if end >= start:
                    for i in range(num_elements):
                        ret[idx + i] = matrix[row][start + i]
                else:
                    for i in range(num_elements):
                        ret[idx + i] = matrix[row][start - i]
            else:
                if end >= start:
                    for i in range(num_elements):
                        ret[idx + i] = matrix[start + i][col]
                else:
                    for i in range(num_elements):
                        ret[idx + i] = matrix[start - i][col]
                                
            idx += num_elements
            # print(side, gap, idx)
            side = (side + 1) % 4
            if side == 0:
                gap += 1
                
        return ret

if __name__ == "__main__":
    o = Solution()

    print(o.spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))
    print(o.spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))