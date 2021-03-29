/*
	A random program to practice some simple algo and runes and stuff.
	Program which returns the character with the last longest continuous
	subsequence in a given string. Input strings are guaranteed to contain
	at least one character.
*/

package main

import (
	"fmt"
)

func find_max_continous_seq(inp string) (string, int) {
	ans := 1
	prev_idx := 0
	ans_ch := rune(inp[prev_idx])

	for i, c := range inp {
		if c != rune(inp[prev_idx]) {
			l := i - prev_idx
			if l >= ans {
				ans = l
				ans_ch = rune(inp[prev_idx])
			}
			prev_idx = i
		}
	}

	// Process for the last character.
	l := len(inp) - prev_idx
	if l >= ans {
		ans = l
		ans_ch = rune(inp[prev_idx])
	}

	return string(ans_ch), ans
}

func main() {
	inp := []string{"rahul", "paul", "abba", "a", "aaaa", "abbb", "aaab", "aaabbb"}

	for _, v := range inp {
		c, cnt := find_max_continous_seq(v)
		fmt.Printf("%s: %s %d\n", v, c, cnt)
	}
}