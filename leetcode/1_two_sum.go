package main

import "fmt"

type TreeNode struct {
	Val   int
	Idx   int
	Left  *TreeNode
	Right *TreeNode
}

func insert(root *TreeNode, x int, idx int) *TreeNode {
	if root == nil {
		root = &TreeNode{x, idx, nil, nil}
	} else if x < root.Val {
		root.Left = insert(root.Left, x, idx)
	} else {
		root.Right = insert(root.Right, x, idx)
	}

	return root
}

func inorder(root *TreeNode) {
	if root == nil {
		return
	}

	inorder(root.Left)
	fmt.Printf("%d, ", root.Val)
	inorder(root.Right)
}

func search(root *TreeNode, x int) (bool, int) {
	if root == nil {
		return false, -1
	}

	if root.Val == x {
		return true, root.Idx
	} else if x < root.Val {
		return search(root.Left, x)
	} else {
		return search(root.Right, x)
	}
}

func twoSums(arr []int, target int) []int {
	root := insert(nil, arr[0], 0)
	for i, v := range arr {
		if i == 0 {
			continue
		}
		insert(root, v, i)
	}

	inorder(root)

	for i, v := range arr {
		found, idx := search(root, target-v)
		if found && idx != i {
			return []int{i, idx}
		}
	}

	return []int{0, 0}
}

func main() {
	fmt.Println(twoSums([]int{1, 2, 3}, 4))
	fmt.Println(twoSums([]int{1, 2, 3}, 6))
}
