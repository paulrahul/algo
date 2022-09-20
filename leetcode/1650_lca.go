/**
 * Definition for Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Parent *Node
 * }
 */

func lowestCommonAncestor(p *Node, q *Node) *Node {
	m := make(map[int]bool)

	for {
		if p == nil {
			break
		}

		m[p.Val] = true
		p = p.Parent
	}

	for {
		if q == nil {
			break
		}

		if _, ok := m[q.Val]; ok {
			return q
		}

		q = q.Parent
	}

	return nil
}