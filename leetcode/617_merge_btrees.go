/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func merge(root1 *TreeNode, root2 *TreeNode, newRoot *TreeNode) *TreeNode {
	val := 0

	if root2 == nil {
		val = root1.Val
	} else if root1 == nil {
		val = root2.Val
	} else {
		val = root1.Val + root2.Val
	}

	newRoot.Val = val

	var leftRoot1 *TreeNode
	var leftRoot2 *TreeNode
	if root1 != nil && root1.Left != nil {
		leftRoot1 = root1.Left
	}
	if root2 != nil && root2.Left != nil {
		leftRoot2 = root2.Left
	}

	if leftRoot1 != nil || leftRoot2 != nil {
		newRoot.Left = &TreeNode{0, nil, nil}
		merge(leftRoot1, leftRoot2, newRoot.Left)
	}

	var rightRoot1 *TreeNode
	var rightRoot2 *TreeNode
	if root1 != nil && root1.Right != nil {
		rightRoot1 = root1.Right
	}
	if root2 != nil && root2.Right != nil {
		rightRoot2 = root2.Right
	}

	if rightRoot1 != nil || rightRoot2 != nil {
		newRoot.Right = &TreeNode{0, nil, nil}
		merge(rightRoot1, rightRoot2, newRoot.Right)
	}

	return newRoot
}

func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil && root2 == nil {
		return nil
	}

	return merge(root1, root2, &TreeNode{0, nil, nil})
}