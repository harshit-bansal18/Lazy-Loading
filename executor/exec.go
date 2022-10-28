package executor

//#include "exec.h"
import "C"

import (
	"fmt"
	"sync"
	"unsafe"
)

func Execute(wg *sync.WaitGroup, data_addr unsafe.Pointer, lock_addr unsafe.Pointer, size int32) {

	defer wg.Done()
	fmt.Println("Executing the data processsor...")
	C.execute(data_addr, lock_addr, C.int(size))
}
