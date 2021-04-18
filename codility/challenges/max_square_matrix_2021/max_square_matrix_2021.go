// https://app.codility.com/programmers/task/max_square_on_matrix/
//
// Find the side length of the biggest black square in a matrix.
// In each column, black cells start at the bottom of the matrix and count up.

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func min(x, y int) int {
	if x < y {
		return x
	}

	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}

	return y
}

func Solution(arr []int) int {
	n := len(arr)

	// We now want to compute the miniumer tower size for every subrange of the
	// input array starting from [0, 1], [1, 2] till [0, n- 1]. To compute this,
	// we will use DP. Our DP algo goes as follows:
	//
	// 1. dp[i][i] = arr[i] for all 0 <= i < n
	// 2. dp[i][j] = n + 1 or inconsequential for all [i, j] where j < i
	// 3. dp[i][j] = min(dp[i][j-1], dp[i+1][j]) for all [i, j] where i < j
	//
	// Hence, our DP data structure is a variable sized 2D slice consisting of
	// cells dpMin[i, j] where j > i and j <= n - 1. i.e.
	// [0, 0], [0, 1], [0, 2], .... [0, n - 1]
	// [1, 1], [1, 2], .... [1, n - 1]
	// ...
	// [n - 1, n - 1]

	dpMin := make([][]int, n)
	for i := 0; i < n; i++ {
		dpMin[i] = make([]int, n)
	}

	// Step 1. i.e. dp[i][i] = arr[i] for all 0 <= i < n
	for i := 0; i < n; i++ {
		dpMin[i][i] = arr[i]
	}

	// Step 2. i.e. dp[i][j] = 0 or inconsequential for all [i, j] where j < i
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			// Input guarantees that every array element will be <= n. Hence,
			// setting these elements to n + 1 so that they are always larger
			// than any actual input element, and hence, inconsequential.
			dpMin[i][j] = n + 1
		}
	}

	// Step 3. i.e. dp[i][j] = min(dp[i][j-1], dp[i+1][j]) for all [i, j]
	// where i < j
	ans := 1
	for l := 2; l <= n; l++ {
		for i := 0; i <= n-l; i++ {
			j := i + l - 1
			dpMin[i][j] = min(dpMin[i][j-1], dpMin[i+1][j])

			if j-i+1 <= dpMin[i][j] {
				ans = max(ans, j-i+1)
			}
		}
	}

	return ans
}

func main() {
	defer writer.Flush()

	fmt.Println(Solution([]int{1, 2, 5, 3, 1, 3}))
	fmt.Println(Solution([]int{3, 3, 3, 5, 4}))
	fmt.Println(Solution([]int{6, 5, 5, 6, 2, 2}))
	fmt.Println(Solution([]int{6, 6, 6, 6, 6}))
}
