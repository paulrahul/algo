package main

import (
	"fmt"
)

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

type RangeAns struct {
	ans      int
	numKUsed int
}

func Solution(arr []int, k int) int {
	n := len(arr)

	numIndices := make(map[int][]int)
	for i, num := range arr {
		numIndices[num] = append(numIndices[num], i)
	}

	ans := 1
	numAns := make([][]RangeAns, n)
	// Now for each number in the original array, get the max possible answer.
	// For each number, we analyse the number of gaps that are there in the
	// original array and then see how many of them can be filled up to make
	// the maximum consecutive sequence of that number.
	for num := range numIndices {
		// First, initialise the DP array for this number.
		for i := 0; i < n; i++ {
			numAns[i] = make([]RangeAns, n)
			if arr[i] == num {
				numAns[i][i] = RangeAns{1, 0}
			} else {
				if k > 0 {
					numAns[i][i] = RangeAns{1, 1}
				} else {
					numAns[i][i] = RangeAns{0, 0}
				}
			}
		}
		// fmt.Printf("%d: %v\n", num, numAns)

		// Now build the DP upwards using the following logic:
		// numAns[p, q] = max(numAns[p, r].ans + numAns[r + 1, q].ans) for any
		// r >= p and <= q, such that
		// numAns[p, r].numKUsed + numAns[r + 1, q].numKUsed <= k
		for l := 1; l < n; l++ {
			for p := 0; p < n-l; p++ {
				q := p + l
				for r := p; r < q; r++ {
					tmpAns := numAns[p][r].ans + numAns[r+1][q].ans
					tmpKUsed := numAns[p][r].numKUsed + numAns[r+1][q].numKUsed

					if tmpKUsed > k {
						surplus := tmpKUsed - k
						tmpAns -= surplus
						tmpKUsed = k
					}

					if tmpAns < numAns[p][q].ans {
						continue
					}

					if tmpAns == numAns[p][q].ans && tmpKUsed >= numAns[p][q].numKUsed {
						continue
					}

					numAns[p][q].ans = tmpAns
					numAns[p][q].numKUsed = tmpKUsed

					ans = max(ans, tmpAns)
				} // for r
			} //for p
		} // for l

		// fmt.Printf("%d: %v\n", num, numAns)
	} // for num

	return ans
}

func main() {
	inp := []struct {
		arr []int
		k   int
	}{
		{[]int{1, 1, 3, 4, 3, 3, 4}, 2},
		{[]int{4, 5, 5, 4, 2, 2, 4}, 0},
		{[]int{1, 3, 3, 2}, 2},
		{[]int{1}, 2},
		{[]int{1, 1, 1, 1}, 2},
		{[]int{1, 2, 2, 2}, 2},
		{[]int{1, 2, 2, 2}, 0},
		{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2},
	}

	for _, v := range inp {
		fmt.Printf("%v: %d\n", v, Solution(v.arr, v.k))
	}
}
