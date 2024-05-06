# CMakeDemo

一个简单易懂的CMake教程，主要包含：

1. 在项目中添加自定义的共享库
2. 在项目中引用第三方开源库

## 命令
编译可执行文件**my_math_test**
```bash
mkdir build
cd build
cmake ..
make -j 4
```
or 
```bash
cmake -B build
cmake --build build
```
安装**my_math_test**
```bash
make install
```
or 
```bash
 sudo cmake  --build build -- install
```

执行测试用例
```bash
$ cmake --build build -- test
Running tests...
Test project /data/jmtang/codes/CMakeDemos/build
    Start 1: example_test
1/1 Test #1: example_test .....................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
```
```bash
$ ./build/test/simple_test 
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from MyMathTest
[ RUN      ] MyMathTest.vector_sum
[       OK ] MyMathTest.vector_sum (0 ms)
[----------] 1 test from MyMathTest (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```

## 文字版教程

[CMake引用自定义库和第三方库](https://zhuanlan.zhihu.com/p/687058798)
