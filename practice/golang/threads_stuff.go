package main

import (
	"fmt"
	"sync"
	"time"
)

type LockObject struct {
	m    map[string]string
	lock sync.Mutex
}

var globalObj LockObject

type ThreadFunc func()
type ThreadBarrier chan int

func threadExecutor(f ThreadFunc, name string, done ThreadBarrier) {
	go func(done ThreadBarrier) {
		fmt.Printf("Inside thread %s\n", name)

		f()

		fmt.Printf("Exiting thread %s\n", name)

		done <- 1
	}(done)
}

func ExecuteThreads(functions []ThreadFunc) {
	n := len(functions)
	done := make(ThreadBarrier, n)

	for i, f := range functions {
		threadExecutor(f, fmt.Sprintf("T%d", i+1), done)
	}

	for i := 0; i < n; i++ {
		<-done
	}
}

func main() {
	globalObj = LockObject{}
	globalObj.m = make(map[string]string)

	functions := []ThreadFunc{

		// T1: Thread which holds the lock to globalObj and sleeps on the lock.
		func() {
			defer globalObj.lock.Unlock()
			globalObj.lock.Lock()

			globalObj.m["1"] = "rahul"
			globalObj.m["2"] = "paul"

			time.Sleep(2)
		},

		// T2: Thread which simply tries to read globalObj without waiting to
		// get the lock.
		func() {
			fmt.Printf("In thread T2 %v\n", globalObj.m)
		},

		// T3: Thread which reads globalObj in a thread-safe manner.
		func() {
			defer globalObj.lock.Unlock()
			globalObj.lock.Lock()

			fmt.Printf("In thread T3 %v\n", globalObj.m)
		},
	}

	ExecuteThreads(functions)
}
