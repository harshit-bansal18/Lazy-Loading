# Lazy-Loading
An implementation of loading data lazily in Golang and C

## Requirements

* go1.18 or above
* gcc-11 or above
* Linux (Tested)

## Running

```
make clean
make
./build/main
```

## Implementation

I have implemented lazy loading using shared memory. One variable indicates the loader to load the next batch of data into shared memory and loader uses the same variable to indicate when it has completed the loading process.  
The executor and loader run on two seperate threads created in golang.