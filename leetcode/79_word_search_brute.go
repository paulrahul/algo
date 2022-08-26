package main

import "fmt"

var isVisited [][]bool

func tryCell(board *[][]byte, word *string, r, c, currIdx int) bool {
	// fmt.Printf("Trying %d, %d\n", r, c)
	l := len(*word)
	if currIdx == l-1 {
		return true
	}

	isVisited[r][c] = true
	m := len(*board)
	n := len((*board)[0])

	// Try all four directions.

	// Up
	if r > 0 && !isVisited[r-1][c] && (*board)[r-1][c] == (*word)[currIdx+1] {
		if tryCell(board, word, r-1, c, currIdx+1) {
			return true
		}
	}

	// Right
	if c < n-1 && !isVisited[r][c+1] && (*board)[r][c+1] == (*word)[currIdx+1] {
		if tryCell(board, word, r, c+1, currIdx+1) {
			return true
		}
	}

	// Down
	if r < m-1 && !isVisited[r+1][c] && (*board)[r+1][c] == (*word)[currIdx+1] {
		if tryCell(board, word, r+1, c, currIdx+1) {
			return true
		}
	}

	// Left
	if c > 0 && !isVisited[r][c-1] && (*board)[r][c-1] == (*word)[currIdx+1] {
		if tryCell(board, word, r, c-1, currIdx+1) {
			return true
		}
	}

	// None of the paths from r, c onwards worked.
	// fmt.Printf("%d, %d failed\n", r, c)
	isVisited[r][c] = false
	return false
}

func exist(board [][]byte, word string) bool {
	m := len(board)
	n := len(board[0])

	isVisited = make([][]bool, m)
	for r := 0; r < m; r++ {
		isVisited[r] = make([]bool, n)
	}

	for r := 0; r < m; r++ {
		for c := 0; c < n; c++ {
			if board[r][c] == word[0] {
				if tryCell(&board, &word, r, c, 0) {
					return true
				}
			}
		}
	}

	return false
}

func callExist(board []string, word string) {
	m := len(board)
	n := len(board[0])
	newBoard := make([][]byte, m)

	for i := 0; i < m; i++ {
		newBoard[i] = make([]byte, n)
		newBoard[i] = []byte(board[i])
	}

	fmt.Println(exist(newBoard, word))
}

func main() {
	// callExist([]string{"ABCE", "SFCS", "ADEE"}, "ABCCED")
	// callExist([]string{"ABCE", "SFCS", "ADEE"}, "SEE")
	callExist([]string{"ABCE", "SFCS", "ADEE"}, "ABCB")
}
