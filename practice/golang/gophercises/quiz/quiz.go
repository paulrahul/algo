package main

import (
  "encoding/csv"
  "fmt"
  "log"
  "strings"
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
  log.SetFlags(log.Lshortfile);

  in := `
  "5+5", "10"
  "7+3", "10"
  "8+3, bitte", "11"
  `
  r := csv.NewReader(strings.NewReader(in))
  r.LazyQuotes = true
  r.FieldsPerRecord = -1
  r.TrimLeadingSpace = true

  records, err := r.ReadAll()
  if err != nil {
    log.Fatal(err)
  }

  m := make(map[string]string)
  for _, r := range records {
    if len(r) == 2 {
      m[r[0]] = r[1]
    }
  }

  s, err := quiz(m)
  if err != nil {
    log.Fatal(err)
  }

  fmt.Printf("Your score is: %d/%d\n", s, len(m))
}
