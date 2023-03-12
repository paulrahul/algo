/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import (
	"sort"
)

var levelSum map[int]int64

// R - O(N)
// S - O(logN)
func traverse(root *TreeNode, level int) {
	_, ok := levelSum[level]
	if !ok {
		levelSum[level] = int64(root.Val)
	} else {
		levelSum[level] += int64(root.Val)
	}

	if root.Left != nil {
		traverse(root.Left, level+1)
	}

	if root.Right != nil {
		traverse(root.Right, level+1)
	}
}

func kthLargestLevelSum(root *TreeNode, k int) int64 {
	levelSum = make(map[int]int64)
	// R - O(N)
	// S - O(logN)
	if root != nil {
		traverse(root, 1)
	}

	n := len(levelSum)
	if k > n {
		return -1
	}

	// R - O(logN)
	ls := make([]int64, n)
	for _, v := range levelSum {
		ls = append(ls, v)
	}

	// Now sort the values in levelSum
	// R - O(MlogM) where M = logN
	sort.Slice(ls, func(i, j int) bool {
		return ls[i] > ls[j]
	})

	// Return the kth value
	// O(1)
	return ls[k-1]
}