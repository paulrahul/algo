package main

import (
  "bufio"
  "encoding/csv"
  "flag"
  "fmt"
  "github.com/dbudworth/greak"
  "io"
  "log"
  "os"
  "strings"
  "sync"
  "time"
)

var score int
var score_mutex sync.Mutex

func quiz(questions map[string]string, r io.Reader, done chan bool) (int, error) {
  var ans string

  score = 0
  i := 1
  for k, v := range questions {
    fmt.Printf("[%d] %s: ", i, k)
    fmt.Fscanf(r, "%s\n", &ans)

    if strings.EqualFold(ans, v) {
      score_mutex.Lock()
      score++
      score_mutex.Unlock()
      fmt.Printf("Correct!\n")
    } else {
      fmt.Printf("Wrong :(. The right answer is %s\n", v)
    }
  }

  done <- true

  return score, nil
}

func timer(duration_secs int, done chan bool) {
  time.Sleep(time.Duration(duration_secs) * 1000 * time.Millisecond)
  done <- false
}

func ExecuteQuiz(m map[string]string, timer_secs int, r io.Reader) {
  base := greak.New()

  done := make(chan bool)
  go quiz(m, r, done)
  go timer(timer_secs, done)

  v, _ := <-done
  if !v {
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

  ExecuteQuiz(m, *timerFlag, os.Stdin)
}
