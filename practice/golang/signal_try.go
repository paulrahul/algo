package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	sigs := make(chan os.Signal)

	signal.Notify(sigs, syscall.SIGINT, syscall.SIGTERM)
	fmt.Println("Now will wait for the signals..")
	sig := <-sigs
	fmt.Println(sig)
	fmt.Println("Got the signal, now exiting.")
}
