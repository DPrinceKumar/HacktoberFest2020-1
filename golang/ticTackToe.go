package main

import (
	"fmt"
	"strings"
)

func main() {
	board := [][]string{
		{"_", "_", "_"},
		{"_", "_", "_"},
		{"_", "_", "_"},
	}
	board[0][0] = "X"
	board[1][1] = "X"
	board[0][2] = "O"
	board[1][2] = "O"
	board[2][2] = "X"

	for i := 0; i < len(board); i++ {
		fmt.Println(strings.Join(board[i], " "))
	}

}
