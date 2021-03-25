package main

import (
  "fmt"
)

func main() {

  whatami := func(i interface{}) string {
    switch i.(type) {
    case bool:
      return "Bool type"
    case int:
      return "Int type"
    default:
      return "whatever"
    }
  }

  fmt.Println(whatami(true))
  whatami(5)
  whatami("hey")
}
