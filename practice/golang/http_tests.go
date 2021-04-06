/*
	Will try out HTTP package with some function wrappers.
*/

package main

import (
	"fmt"
	"log"
	"net/http"
	"sync/atomic"
)

var count uint64

func siteStatsHandler(originalHandler http.HandlerFunc) http.HandlerFunc {
	// THIS IS A BUGGY IMPLEMENTATION! Here, instead of wrapping the method, we
	// are simply adding to the count and returning the original method. Which
	// means that when siteStatsHandler is initially called -- while registering
	// the handler -- the count will be incremented once and the original
	// handler will be registered to the given URL path. But what we want is
	// that the count be increased everytime the URL is visited and then, the
	// original handler be returned. Which means that we have to register a new,
	// wrapper function which does both these operations. In the next version
	// of this code, we will do that. When this code is executed, the count will
	// always be 2 no matter how many times we visit the main page (or even the
	// stats page).
	log.Println("Adding to count")
	atomic.AddUint64(&count, 1)
	return originalHandler
}

func mainPageHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, "Main Page")
}

func countPageHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Visit count: %d\n", count)
}

func main() {
	http.HandleFunc("/", siteStatsHandler(mainPageHandler))
	http.HandleFunc("/stats", siteStatsHandler(countPageHandler))
	err := http.ListenAndServe(":3000", nil)
	if err != nil {
		fmt.Println(err)
	}
}
