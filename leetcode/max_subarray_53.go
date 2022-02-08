package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func maxSubArray(nums []int) int {
	n := len(nums)

	sum := make([]int, n)

	sum[0] = nums[0]
	for i := 1; i < n; i++ {
		sum[i] = sum[i-1] + nums[i]
	}

	ans := max(sum[n-1], nums[n-1])
	mx := sum[n-1]
	var candidate int
	for i := n - 2; i >= 0; i-- {
		mx = max(mx, sum[i+1])
		candidate = max(nums[i], mx-sum[i]+nums[i])
		ans = max(ans, candidate)

		// fmt.Printf("%d ans is %d\n", i, ans)
	}

	return ans
}

func main() {
	fmt.Println(maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
	fmt.Println(maxSubArray([]int{1}))
	fmt.Println(maxSubArray([]int{5, 4, -1, 7, 8}))
	fmt.Println(maxSubArray([]int{-1}))
	fmt.Println(maxSubArray([]int{-1, -2}))
}
