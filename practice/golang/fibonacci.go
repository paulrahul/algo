package main

import (
  "fmt"
)

func fibonacci() func () int {
  prev := 0;
  next := 1;
  fmt.Printf("0 1 ")

  return func() int {
    sum := prev + next
    prev = next
    next = sum
    return sum
  }
}


func main() {
  f := fibonacci()
  for i := 0; i < 10; i++ {
    fmt.Printf("%d ", f());
  }
}
