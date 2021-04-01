package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	defer writer.Flush()

	var t int
	scanf("%d\n", &t)

	var n int
	for t > 0 {
		scanf("%d\n", &n)
		t--

		arr := make([]int, n)
		for i := 0; i < n; i++ {
			scanf("%d ", &arr[i])
		}

		sort.Ints(arr)
		i := 0
		for i < n {
			if i < arr[i] {
				break
			}
			i++
		}

		printf("%d\n", i)
	}
}
