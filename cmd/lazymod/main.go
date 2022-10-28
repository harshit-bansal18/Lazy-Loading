package main

import (
	"unsafe"

	"example.com/lazyloading/pkg/worker"
)

import "C"

//export run
func run(dataAddr *C.int, lockAddr *C.int, size C.int){
	worker.StartProcess("", unsafe.Pointer(dataAddr), unsafe.Pointer(lockAddr), int32(size));

}


func main() {}
