package main

import (
  "fmt"
)

func adder() func (x int) int {
  sum := 0;
  return func(x int) int {
    return sum + x
  }
}


func main() {
  fmt.Printf("Hello World!\n");

  pos, neg := adder(), adder()

  for i := 0; i < 10; i++ {
    fmt.Printf("%d %d\n", pos(i), neg(-2*i));
  }

  var m map[int]string
  m = make(map[int]string)

  m[1] = "one"
  fmt.Println(m)

  if v, ok := m[1]; ok {
    fmt.Println(v)
  }

  m1 := map[int]string{1: "abc", 2: "def"}
  fmt.Println(m1)

  var arr [4]int
  arr = []int{6, 7, 8, 9}
  fmt.Println(arr)
}
