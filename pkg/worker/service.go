package worker

import (
	"fmt"
	"sync"
	"unsafe"

	"example.com/lazyloading/executor"
	"example.com/lazyloading/pkg/ffi"
)


func StartProcess(path string, dataAddr unsafe.Pointer, lockAddr unsafe.Pointer, size int32) {
	// spin two golang routines.
	var wg sync.WaitGroup

	fmt.Println("Spinning threads...")
	wg.Add(2)
	go executor.Execute(&wg, dataAddr, lockAddr, size)
	go ffi.Load_data(&wg, path, dataAddr, lockAddr, size)
	wg.Wait()
}