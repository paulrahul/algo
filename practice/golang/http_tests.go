/*
	Will try out HTTP package with some function wrappers.
*/

package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"sync/atomic"
)

var count uint64

func siteStatsHandler(originalHandler http.HandlerFunc) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		if r.URL.Path != "/favicon.ico" {
			log.Println("Adding to count")
			atomic.AddUint64(&count, 1)
		}

		originalHandler(w, r)
	}
}

func mainPageHandler(w http.ResponseWriter, r *http.Request) {
	log.Println("In mainPageHandler")
	fmt.Fprintln(w, "Main Page")
}

func countPageHandler(w http.ResponseWriter, r *http.Request) {
	log.Println("In countPageHandler")
	fmt.Fprintf(w, "Visit count: %d\n", count)
}

func main() {
	log.SetOutput(ioutil.Discard)

	http.HandleFunc("/", siteStatsHandler(mainPageHandler))
	http.HandleFunc("/stats", siteStatsHandler(countPageHandler))

	err := http.ListenAndServe(":3000", nil)
	if err != nil {
		fmt.Println(err)
	}
}
