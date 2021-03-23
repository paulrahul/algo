package main

import (
  "bufio"
  "encoding/csv"
  "flag"
  "fmt"
  "log"
  "os"
  "strings"
)

func quiz(questions map[string]string) (int, error) {
  var ans string

  score := 0
  i := 1
  for k, v := range questions {
    fmt.Printf("[%d] %s: ", i, k)
    fmt.Scanf("%s\n", &ans)

    if strings.EqualFold(ans, v) {
      score++
      fmt.Printf("Correct!\n")
    } else {
      fmt.Printf("Wrong :(. The right answer is %s\n", v)
    }
  }

  return score, nil
}


func main() {
  log.SetFlags(log.Lshortfile);

  var pathFlag = flag.String(
    "path", "problems.csv", "Path of the quiz file")
  flag.Parse()

  f, err := os.Open(*pathFlag)
  if err != nil {
    log.Fatal(err)
  }

  r := csv.NewReader(bufio.NewReader(f))
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
