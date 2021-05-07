package main

import (
	"bufio"
	"fmt"
	"os"
)

var stdin = bufio.NewReader(os.Stdin)

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		solve()
	}
}

func solve() {
	var n int
	fmt.Fscan(stdin, &n)

	cnt := make(map[int]int64, n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscan(stdin, &a)
		cnt[a-i]++
	}

	var sum int64 = 0
	for _, c := range cnt {
		if c == 1 {
			continue
		}
		c--
		sum += (1 + c) * c / 2
	}
	fmt.Println(sum)
}
