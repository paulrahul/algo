package main

import "fmt"

type MyFunc func(string)

func (f MyFunc) ToString(x int) {
	f(fmt.Sprintf("ToString calling MyFunc with %d", x))
}

func main() {
	var f MyFunc
	f = func(s string) {
		fmt.Printf("MyFunc called with %s\n", s)
	}

	f("rahul")
	f.ToString(10)
}
