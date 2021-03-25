package main

import (
  "fmt"
  "math"
)

type NegativeErr int

func Root(x int) (float64, error) {
  if x < 0 {
    return -1, NegativeErr(x)
  }

  return math.Sqrt(float64(x)), nil
}


func (e NegativeErr) Error() string {
  return fmt.Sprintf("Can't find root of negative number %d\n", e)
}

func main() {
  arr := [2]int{4, -4}

  for i := 0; i < 2; i++ {
    r, err := Root(arr[i])
    if err != nil {
      fmt.Printf("Error encountered: %s\n", err)
    } else {
      fmt.Printf("Root is %f\n", r)
    }
  }
}
