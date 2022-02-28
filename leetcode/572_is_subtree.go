/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isSame(root *TreeNode, subRoot *TreeNode) bool {
	if root != nil && subRoot == nil {
		return false
	}

	if root == nil && subRoot != nil {
		return false
	}

	if root == nil {
		return true
	}

	if root.Val != subRoot.Val {
		return false
	}

	return isSame(root.Left, subRoot.Left) && isSame(root.Right, subRoot.Right)
}

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	if root == nil {
		return false
	}

	check := isSame(root, subRoot)

	if !check {
		return isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
	}

	return true
}