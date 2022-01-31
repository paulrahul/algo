package main

import (
	"fmt"
	"sort"
)

func containsDuplicate(nums []int) bool {
	sort.Ints(nums)

	l := len(nums)
	for i := 1; i < l; i++ {
		if nums[i] == nums[i-1] {
			return true
		}
	}

	return false
}

func main() {
	fmt.Println(containsDuplicate([]int{1, 2, 3, 1}))
	fmt.Println(containsDuplicate([]int{1, 2, 3, 4}))
	fmt.Println(containsDuplicate([]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}))
	fmt.Println(containsDuplicate([]int{1}))
	fmt.Println(containsDuplicate([]int{1, 2}))
}
