package main

var visited map[int]bool
var ans [][]int
var curr []int

func permuteInternal(nums []int, idx int) {
	for _, n := range nums {
		ok, v := visited[n]
		if ok && v {
			continue
		}

		visited[n] = true
		curr[idx] = n

		if idx == len(nums)-1 {
			newSol := append(make([]int, 0, len(curr)), curr...)
			ans = append(ans, newSol)
		} else {
			permuteInternal(nums, idx+1)
		}

		visited[n] = false
	}
}

func permute(nums []int) [][]int {
	l := len(nums)
	if l == 1 {
		return [][]int{{nums[0]}}
	}

	ans = make([][]int, 0)
	curr = make([]int, l)
	for _, v := range nums {
		visited = make(map[int]bool)

		visited[v] = true
		curr[0] = v
		permuteInternal(nums, 1)
	}

	return ans
}
