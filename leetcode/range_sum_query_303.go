package main

import "fmt"

type NumArray struct {
	nums []int
	sums []int
}

func Constructor(nums []int) NumArray {
	n := len(nums)

	sums := make([]int, n)
	sums[0] = nums[0]
	for i := 1; i < n; i++ {
		sums[i] = sums[i-1] + nums[i]
	}

	return NumArray{nums, sums}
}

func (this *NumArray) SumRange(left int, right int) int {
	return this.sums[right] - this.sums[left] + this.nums[left]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */

func main() {
	obj := Constructor([]int{-2, 0, 3, -5, 2, -1})
	fmt.Println(obj.SumRange(0, 2))
	fmt.Println(obj.SumRange(2, 5))
	fmt.Println(obj.SumRange(0, 5))
}
