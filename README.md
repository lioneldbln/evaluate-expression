## Synopsis

`evaluate-expression` is a command-line application to evaluate an expression.  
Ignore whitespace and stop at the first non-valid character.  
Valid tokens are listed in the table below:  
0-9  :  Only integers are allowed in expressions  
( )  :  Nested expressions should be evaluated first  
+, -, *, /  :  Basic operators are addition, subtraction, multiplication and division  

## Prerequisites

The compiler needs to support C++11 features  
http://en.cppreference.com/w/cpp/compiler_support

## Build Instructions on Windows:

```
    $ git clone https://github.com/lioneldbln/evaluate-expression.git
    $ cd evaluate-expression
    $ mkdir build
```
  Running CMake for Windows and choose your configuration  
  https://cmake.org/runningcmake/

  Open the solution `evalexp.sln` from `build\` folder and then build solution

## Build Instructions on Linux:

```
    $ git clone https://github.com/lioneldbln/evaluate-expression.git
    $ cd evaluate-expression
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
```
## Running the tests

Unit tests are performed with `googletest`  
    
  **On Windows:**  
  Start `evalexptests` project  
  
  **On Linux:**
```
  $ ./build/tests/evalexptests
```

## How to use

Launch `evalexp` executable and follow the instructions

## Author

* **Lionel CHATAIN**

