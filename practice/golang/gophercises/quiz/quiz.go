package main

import (
  "fmt"
)

func quiz(questions map[string]string) (int, error) {
  var ans string

  score := 0
  i := 1
  for k, v := range questions {
    fmt.Printf("[%d] %s: ", i, k)
    fmt.Scanf("%s\n", &ans)

    if ans == v {
      score++
      fmt.Printf("Correct!\n")
    } else {
      fmt.Printf("Wrong :(\n")
    }
  }

  return score, nil
}


func main() {
  m := map[string]string{"5+5": "10", "7+3": "10"}
  s, err := quiz(m)
  if err != nil {
    fmt.Printf("Error: %v\n", err)
    return
  }

  fmt.Printf("Your score is: %d/%d\n", s, len(m))
}
