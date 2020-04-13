BARISTAMATIC
------------

Prototype coffee machine library and command-line interface

## Version ##
Version 1.0.0

## Build Instructions ##

### Build BARISTAMATIC ###
**NOTE** Currently BARISTAMATIC is only tested on Mac_OS_X clang compilers.

```
$ cd BARISTAMATIC
$ mkdir build && cd build
$ cmake -DENABLE_TESTS=ON ..
$ make -j$(nproc)
$ make test
$  ./bin/runCoffeeMaker
```

Executing the above commands will build all libraries and executables (testing executables included). Testing can be enable by adding `-DENABLE_TESTS=ON`, by default it is turned off. Documentation can be built from scratch using doxygen and graphviz by adding `-DBUILD_DOCUMENTATION`, currently a document already exists at doc `$BARISTAMATIC_HOME_DIR/docs/refman.pdf`. 
