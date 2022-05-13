package main

import "fmt"

func findDuplicates(nums []int) []int {
	// Let's do the logic as follows:
	// 0. We iterate left to right. For every index (currIndex), we:
	// 1. First check if nums[currIdx] = currIdx + 1
	// 1a. If yes, then currIdx already has the right number, move on.
	// 1b. If no, then we need to move nums[currIdx] to nums[currIdx] - 1
	// 2. If nums[currIdx] - 1 < currIdx, then this is a duplicate since
	// all previous indexes will already be having the right number.
	// 2a. Else, swap nums[nums[currIdx] - 1] & nums[currIdx] and repeat 1.

	ans := make([]int, 0)
	n := len(nums)

	var swapIdx int
	var v int
	currIdx := 0
	// fmt.Println(nums)
	for {
		if currIdx >= n {
			break
		}

		v = nums[currIdx]

		if v == -1 {
			currIdx++
			continue
		}

		if v == currIdx+1 {
			// fmt.Printf("Index %d already set correctly\n", currIdx+1)
			currIdx++
			continue
		}

		swapIdx = v - 1
		if v == nums[swapIdx] {
			// fmt.Printf("Found duplicate %d in index %d\n", v, currIdx+1)
			ans = append(ans, v)
			nums[currIdx] = -1
			currIdx++
			continue
		}

		// fmt.Printf("Attempting to swap %d and %d\n", swapIdx, currIdx)
		nums[currIdx] = nums[swapIdx]
		nums[swapIdx] = v
		// fmt.Printf("currIdx: %d\n", currIdx)
		// fmt.Println(nums)
	}

	return ans
}

func main() {
	fmt.Println(findDuplicates([]int{1, 1, 2}))
	fmt.Println(findDuplicates([]int{4, 3, 2, 7, 8, 2, 3, 1}))
	fmt.Println(findDuplicates([]int{3, 11, 8, 16, 4, 15, 4, 17, 14, 14, 6, 6, 2, 8, 3, 12, 15, 20, 20, 5}))
}
