package main

import (
  "bufio"
  "fmt"
  "os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func main() {
  defer writer.Flush()

  var t, n int
  var tmp int

  scanf("%d\n", &t)

  for i := 0; i < t; i++ {
    scanf("%d\n", &n)
    sum := 0
    for j := 0; j < n; j++ {
      scanf("%d ", &tmp)
      sum += tmp
    }

    if sum % 2 == 0 {
      printf("1\n")
    } else {
      printf("2\n")
    }
  }
}
