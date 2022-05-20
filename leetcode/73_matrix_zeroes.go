package main

func setZeroes(matrix [][]int) {
	m := len(matrix)
	n := len(matrix[0])
	var isFirstColZero bool

	for i := 0; i < m; i++ {
		for j, v := range matrix[i] {
			if v == 0 {
				matrix[i][0] = 0
				if j == 0 {
					isFirstColZero = true
				}
				break
			}
		}
	}

	for j := 1; j < n; j++ {
		for i := 0; i < m; i++ {
			if matrix[i][j] == 0 {
				matrix[0][j] = 0
				break
			}
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][0] == 0 || matrix[0][j] == 0 {
				matrix[i][j] = 0
			}
		}
	}

	if matrix[0][0] == 0 {
		for j := 0; j < n; j++ {
			matrix[0][j] = 0
		}
	}

	if isFirstColZero {
		for i := 0; i < m; i++ {
			matrix[i][0] = 0
		}
	}
}
