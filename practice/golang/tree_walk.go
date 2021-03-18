package main

import (
  "fmt"
  "log"
  "math/rand"
)

type Tree struct {
  Left *Tree
  Value int
  Right *Tree
}

func (t* Tree) Add(k int) {
  if k < t.Value {
    if l := t.Left; l != nil {
      l.Add(k)
    } else {
      t.Left = &Tree{nil, k, nil}
    }
  } else {
    if r := t.Right; r != nil {
      r.Add(k)
    } else {
      t.Right = &Tree{nil, k, nil}
    }
  }
}

func New(k int) *Tree {
  var arr [10]int
  for i := 1; i <= 10; i++ {
    arr[i - 1] =  i * k
  }

  rand.Shuffle(10, func(i, j int) {
    arr[i], arr[j] = arr[j], arr[i]
  })

  // Construct random BST with values k, 2k, 3k, ..., 10k

  // Root
  t := Tree{nil, arr[0], nil}

  for i := 1; i < 10; i++ {
    t.Add(arr[i])
  }

  return &t
}

func inorder_walk(t *Tree, ch chan int) {
  // Inorder traversal.

  if l := t.Left; l != nil {
    inorder_walk(l, ch)
  }

  ch <- t.Value

  if r := t.Right; r != nil {
    inorder_walk(r, ch)
  }
}

func Walk(t *Tree, ch chan int) {
  inorder_walk(t, ch)
  close(ch)
}

func Same(t1 *Tree, t2 *Tree) bool {
  ch1 := make(chan int)
  ch2 := make(chan int)

  var v1, v2 []int
  var lc1, lc2 int = -1, -1
  var one_closed_already bool

  go Walk(t1, ch1)
  go Walk(t2, ch2)

  outer:
  for {
    select {
    case v, ok := <-ch1:
      if !ok {
        if one_closed_already {
          log.Println("Breaking")
          break outer
        } else {
          one_closed_already = true
          ch1 = nil
          log.Println("Breaking")
          break
        }
      }

      v1 = append(v1, v)
      if lc1 + 1 < len(v1) && lc2 + 1 < len(v2) {
        lc1++
        lc2++
        if v1[lc1] != v2[lc2] {
          log.Println("Returning false")
          return false
        }
        log.Printf("Checked %d\n", v1[lc1])
      }
    case v, ok := <-ch2:
      if !ok {
        if one_closed_already {
          log.Println("Breaking")
          break outer
        } else {
          one_closed_already = true
          ch2 = nil
          log.Println("Breaking")
          break
        }
      }

      v2 = append(v2, v)
      if lc1 + 1 < len(v1) && lc2 + 1 < len(v2) {
        lc1++
        lc2++
        if v1[lc1] != v2[lc2] {
          log.Println("Returning false")
          return false
        }
        log.Printf("Checked %d\n", v1[lc1])
      }
    }  //select
  }  // for

  log.Printf("%v %d %v %d\n", v1, lc1, v2, lc2)
  return lc1 == lc2 && lc1 + 1 == len(v1)
} // same

func main() {
  log.SetFlags(log.Lshortfile);

  t1 := New(1)
  t2 := New(1)

  fmt.Println(Same(t1, t2))
}
