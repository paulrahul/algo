package main

import "fmt"

var numMap map[int]int

func subsetsInternal(nums []int, idx int) [][]int {
	v := nums[idx]
	nc := numMap[v]

	ret := make([][]int, 0)
	if idx < len(nums)-1 {
		ret = subsetsInternal(nums, idx+1)

		l := len(ret)

		for i := 0; i < l; i++ {
			currRet := append(make([]int, 0, len(ret[i])), ret[i]...)
			for j := 0; j < nc; j++ {
				currRet = append(currRet, v)
				ret = append(ret, currRet)
			}
		}
	}

	curr := make([]int, 0)
	for i := 0; i < nc; i++ {
		curr = append(curr, v)
		ret = append(ret, curr)
	}

	return ret
}

func subsetsWithDup(nums []int) [][]int {
	numMap = make(map[int]int)
	newNums := make([]int, 0)

	for _, x := range nums {
		if _, ok := numMap[x]; !ok {
			numMap[x] = 0
			newNums = append(newNums, x)
		}

		numMap[x] = numMap[x] + 1
	}

	var ret [][]int
	if len(nums) == 1 {
		ret = [][]int{{nums[0]}}
	} else {
		ret = subsetsInternal(newNums, 0)
	}

	return append(ret, []int{})
}

func main() {
	fmt.Println(subsetsWithDup([]int{1, 1, 2, 2}))
}
