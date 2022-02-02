package main

import "fmt"

func findDisappearedNumbers(nums []int) []int {
	// All actual numbers in the array are supposed to be with [1, n]
	// So any index having value >= n + 1 indicates that that index number
	// is present in the input. So for every number in the input array, we mark
	// the corresponding index with the higher value and later, we just scan the
	// array and see which index does not have a higher value.

	n := len(nums)
	higherStart := n + 1

	var indexValue int
	for _, v := range nums {
		indexValue = v
		if indexValue > n {
			indexValue = indexValue - n - 1
		}

		// Make sure we don't set a higher value more than once.
		if nums[indexValue-1] > n {
			continue
		}

		nums[indexValue-1] = nums[indexValue-1] + higherStart
	}

	var ret []int
	for i, v := range nums {
		if v <= n {
			ret = append(ret, i+1)
		}
	}

	return ret
}

func main() {
	fmt.Println(findDisappearedNumbers([]int{4, 3, 2, 7, 8, 2, 3, 1}))
	fmt.Println(findDisappearedNumbers([]int{1, 1}))
}
