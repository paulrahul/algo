package main

import (
	"fmt"
	"sort"
)

type Interval struct {
	S, E int
}

func countMaxOverlappingInterval(arr []Interval) int {
	// Iterate over the points and for each coordinate, record
	// a. whether it is start or end, b. the coordinate value.

	n := len(arr)

	type Point struct {
		IsStart bool
		X       int
	}
	points := make([]Point, n*2)

	i := 0
	for _, interval := range arr {
		points[i].IsStart = true
		points[i].X = interval.S

		points[i+1].IsStart = false
		points[i+1].X = interval.E

		i += 2
	}

	// Now sort the points based on:
	// 1. the X position (ascending)
	// 2. start before end
	sort.Slice(points, func(i, j int) bool {
		if points[i].X < points[j].X {
			return true
		}

		if points[i].X == points[j].X {
			return points[i].IsStart
		}

		return false
	})

	// Now iterate over the points and keep increasing the count as start
	// points are encountered, and decreasing the count as end points are
	// encountered.
	ans := 0

	count := 0
	for _, p := range points {
		if p.IsStart {
			count += 1
			if count > ans {
				ans = count
			}
		} else {
			count -= 1
		}
	}

	return ans
}

func main() {
	fmt.Println(countMaxOverlappingInterval([]Interval{
		{1, 2}, {2, 4}, {3, 6},
	}))

	fmt.Println(countMaxOverlappingInterval([]Interval{
		{1, 8}, {2, 5}, {5, 6}, {3, 7},
	}))

	fmt.Println(countMaxOverlappingInterval([]Interval{
		{1, 2}, {3, 4}, {5, 6},
	}))
}
