package main

import (
  "bufio"
  "encoding/csv"
  "flag"
  "fmt"
  "github.com/dbudworth/greak"
  "log"
  "os"
  "strings"
  "sync"
  "time"
)

var score int
var score_mutex sync.Mutex

func quiz(questions map[string]string) (int, error) {
  var ans string

  score = 0
  i := 1
  for k, v := range questions {
    fmt.Printf("[%d] %s: ", i, k)
    fmt.Scanf("%s\n", &ans)

    if strings.EqualFold(ans, v) {
      score_mutex.Lock()
      score++
      score_mutex.Unlock()
      fmt.Printf("Correct!\n")
    } else {
      fmt.Printf("Wrong :(. The right answer is %s\n", v)
    }
  }

  return score, nil
}

func executeQuiz(m map[string]string, timer_secs int) {
  base := greak.New()

  done := make(chan bool, 1)
  go func() {
    quiz(m)
    done <- true
  }()

  select {
  case <-done:
  case <-time.After(time.Duration(timer_secs) * 1000 * time.Millisecond):
    fmt.Printf("\nTime Up!\n")
  }

  score_mutex.Lock()
  s := score
  score_mutex.Unlock()
  fmt.Printf("Your score is: %d/%d\n", s, len(m))

  after := base.Check()
  fmt.Println("Sleeping goroutine should show here\n", after)
}

func main() {
  log.SetFlags(log.Lshortfile);

  var pathFlag = flag.String(
    "path", "problems.csv", "Path of the quiz file")
  var timerFlag = flag.Int(
    "timer_secs", 30, "Duration of the quiz in seconds.")
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

  // Ask user before starting timer.
  fmt.Printf("Quiz timer for %d seconds will start now. ", *timerFlag)
  fmt.Printf("Press any key to start the quiz timer\n")
  var ch string
  fmt.Scanf("%s", &ch)

  executeQuiz(m, *timerFlag)
}
