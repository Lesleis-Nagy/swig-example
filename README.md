Python/C++ Swig Example
=======================

This example shows how to wrap a simple c++ library for use in Python using 
swig. Things to note:

The example uses two different types of output

* `run_singles` will output three single (one) dimensional arrays containing output values,
* `run_combi` will output a single array containing output values.

You *MUST* be careful of exactly which python you link against hese can
be set in the Makefile by changing the following directories 

* `PYTHON_INCLUDE_DIR` - the include directory that should contain a file
  called `Python.h`.
* `PYTHON_LIB_DIR` - the python libraries directiory that should contains a 
  file called something like `libpython???` (the ??? referrs to some other
  stuff - usually a version number).
* `PYTHON_LIB` the name of the python library (*i.e.* the thing called
  `libpython???`).
* `NUMPY_INCLUDE_DIR` - the include directory that contains headers required
  by numpy (*i.e.* `numpy/arrayobject.h`).

You should set `CC` to the correct compiler.

