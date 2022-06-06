class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        '''
        Algo:
            1. Go over every "concentric" loop, starting from the outermost one.
            2. Loop size starts with N and then decreases by 2 every iteration.
            3. Each element, arr[i][j], is spatially placed at i + j
            4. For each iteration, we'll rotate in the order TRBL
        '''
        
        n = len(matrix)
        loop = 0
        
        lim =  n / 2 - 1 if n % 2 == 0 else n / 2
        while loop <= lim:
            for i in range(n - 2 * loop - 1):
                # T
                tmp_in = matrix[loop + i][n - loop - 1]
                matrix[loop + i][n - loop - 1] = matrix[loop][loop + i]
                
                # R
                tmp_out = matrix[n - loop - 1][n - loop - 1 - i]
                matrix[n - loop - 1][n - loop - 1 - i] = tmp_in
                tmp_in = tmp_out
                
                # B
                tmp_out = matrix[n - loop - 1 - i][loop]
                matrix[n - loop - 1 - i][loop] = tmp_in                
                tmp_in = tmp_out
                
                # L
                matrix[loop][loop + i] = tmp_in
                
            loop += 1
        
                
                
                
        