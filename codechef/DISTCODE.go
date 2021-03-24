package main

import (
  "fmt"
)

func main() {
  var t int
  fmt.Scanf("%d\n", &t)

  var inp string
  for i := 0; i < t; i++ {
    fmt.Scanf("%s\n", &inp)

    var codes [26][26]bool
    l := len(inp)
    ans := 0
    for j := 0; j < l - 1; j++ {
      first_idx := inp[j] - 'A'
      second_idx := inp[j + 1] - 'A'

      if !codes[first_idx][second_idx] {
        ans++
      }
      codes[first_idx][second_idx] = true
    }

    fmt.Println(ans)
  }
}
