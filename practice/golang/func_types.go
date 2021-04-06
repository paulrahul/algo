package main

import "fmt"

type MyFunc func(int) string

func (f MyFunc) ToString(x int) {
	fmt.Printf("MyFunc output: %s\n", f(x))
}

func main() {
	var f MyFunc
	f = func(x int) string {
		return fmt.Sprintf("%d", x)
	}

	f(10)
	f.ToString(10)
}
