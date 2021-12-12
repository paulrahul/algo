package main

import (
	"fmt"
)

type I interface {
	foo() string
	// bar() string  // Leads to compile error as it forces the subtypes to implement this.
}

type MyInt int32
type MyFloat float64

func (i MyInt) foo() string {
	// if i == nil  {
	//   fmt.Println("MyInt value not set yet!")
	//   return ""
	// }

	return "Hey " + describe(i)
}

func (f MyFloat) foo() string {
	return "Hey " + describe(f)
}

func describe(v I) string {
	s := fmt.Sprintf("%T %v", v, v)
	return s
}

func main() {
	var mi MyInt
	fmt.Println(mi.foo())

	var mf MyFloat
	fmt.Println(mf.foo())

	var ei interface{}
	ei = 12312

	v, ok := ei.(string)
	fmt.Println(v, ok)
}
