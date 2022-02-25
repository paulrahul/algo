/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func subTreeMax(root *TreeNode, depth int, ans *int) int {
	if root == nil {
		return 0
	}

	if root.Left == nil && root.Right == nil {
		return depth
	}

	lmax := subTreeMax(root.Left, depth+1, ans)
	rmax := subTreeMax(root.Right, depth+1, ans)

	*ans = max(*ans, lmax+rmax-2*depth)

	return max(lmax, rmax)
}

func diameterOfBinaryTree(root *TreeNode) int {
	ans := 0
	subTreeMax(root, 0, &ans)
	return ans
}