package main


import (
  "fmt"
)

type Coord struct {
  x, y int
}

// Function
func f(c *Coord) {
  fmt.Printf("[%d, %d]\n", c.x, c.y)
}

// Method
func (c *Coord) m() {
  fmt.Printf("[%d, %d]\n", c.x, c.y)
}

// Method
func (c Coord) m1() {
  fmt.Printf("[%d, %d]\n", c.x, c.y)
}

func main () {
  c := Coord{1, 2}

  var c1 Coord
  c1.x = 5
  c1.y = 6

  c2 := &c1

  // f(c)
  f(&c);
  c.m()

  // f(c1)
  f(&c1)
  c1.m()

  f(c2)
  // f(&c2)
  c2.m()

  c.m1()
  c1.m1()
  c2.m1()
}
