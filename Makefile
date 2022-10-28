GOBUILD=go build -buildmode=c-archive

all: build/liblazy.a build/main

build/main: build/liblazy.a
	gcc -L./build/ main.c build/liblazy.a -o $@	

build/liblazy.a:
	$(GOBUILD) -o $@ ./cmd/lazymod/main.go

clean:
	rm -rf build/lib* main
