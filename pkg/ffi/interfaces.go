package ffi

import (
	"sync"
	"unsafe"
)

/*
#cgo LDFLAGS: -L${SRCDIR}
#cgo CFLAGS: -I${SRCDIR}
#include "include/interfaces.h"
*/
import "C"

func Load_data(wg *sync.WaitGroup, path string, dataAddr unsafe.Pointer, lockAddr unsafe.Pointer, size int32) {
	defer wg.Done()
	C.load_data(C.CString(path), dataAddr, lockAddr, C.int(size))
}