package main

import (
	"fmt"
	"sort"
)

type Meeting struct {
	Start int
	End   int
}

func swapVal(val1, val2 *int) {
	tmp := *val1
	*val1 = *val2
	*val2 = tmp
}

func swapMeeting(meeting1, meeting2 *Meeting) {
	// fmt.Printf("Sorting called between %v and %v\n", meeting1, meeting2)
	swapVal(&meeting1.Start, &meeting2.Start)
	swapVal(&meeting1.End, &meeting2.End)
}

// func checkAvailability(meetings []Meeting) bool {
// 	// Sort the meetings and bail out the moment you find a meeting overlapping.
// 	n := len(meetings)

// 	var start1 int
// 	var start2 int
// 	for i := 0; i < n; i++ {
// 		start1 = meetings[i].Start
// 		for j := i + 1; j < n; j++ {
// 			start2 = meetings[j].Start

// 			if start2 > start1 {
// 				continue
// 			}

// 			if start2 == start1 && meetings[j].End >= meetings[i].End {
// 				continue
// 			}

// 			// Swap the two meetings.
// 			swapMeeting(&meetings[i], &meetings[j])
// 		}
// 	}

// 	// fmt.Printf("After sorting: %v\n", meetings)

// 	// Now iterate over the sorted list looking for any overlap.
// 	for i := 1; i < n; i++ {
// 		if meetings[i-1].End > meetings[i].Start {
// 			return false
// 		}
// 	}

// 	return true
// }

type By []Meeting

func (m By) Len() int      { return len(m) }
func (m By) Swap(i, j int) { m[i], m[j] = m[j], m[i] }
func (m By) Less(i, j int) bool {
	return m[i].Start < m[j].Start ||
		(m[i].Start == m[j].Start && m[i].End < m[j].End)
}

func checkAvailability(meetings []Meeting) bool {
	// Sort the meetings and bail out the moment you find a meeting overlapping.
	sort.Sort(By(meetings))

	// fmt.Printf("After sorting: %v\n", meetings)

	n := len(meetings)
	// Now iterate over the sorted list looking for any overlap.
	for i := 1; i < n; i++ {
		if meetings[i-1].End > meetings[i].Start {
			return false
		}
	}

	return true
}

func printAvailability(meetings []Meeting) {
	fmt.Printf("%v: %v\n", meetings, checkAvailability(meetings))
}

func main() {
	printAvailability([]Meeting{{0, 30}, {5, 10}, {15, 20}})
	printAvailability([]Meeting{{7, 10}, {2, 4}})
	printAvailability([]Meeting{{7, 10}, {2, 8}})
}
