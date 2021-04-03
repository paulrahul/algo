package main

import (
	"bufio"
	"fmt"
	"os"
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
	var k int
	for t > 0 {
		scanf("%d ", &n)
		scanf("%d\n", &k)

		sum := 0
		arr := make([]int, n)
		for i := 0; i < n; i++ {
			scanf("%d ", &arr[i])
			sum += arr[i]
		}

		ans := 0
		for i := 0; i < n; i++ {
			if arr[i]+k > sum-arr[i] {
				ans++
			}
		}

		printf("%d\n", ans)
		t--
	}
}
