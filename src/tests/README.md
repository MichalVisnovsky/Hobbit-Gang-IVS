# Math library tests

These tests check the functionality of the math library used for the Hobbit calculator. It was created using the [Google Test](https://github.com/google/googletest) framework.

## How to run the tests

Please install [CMake](https://cmake.org/) to configure and build the project.
### Step 1 - build folder
If the **build** folder exists, change the directory and delete all existing files in the **build** folder:
```bash
cd build
rm -r *
```
If the folder doesn't exist, create it:
```bash
mkdir build
cd build
```

### Step 2 - configuring the project
In the **build** folder, run the following command (Unix\ Makefiles being the CMake generator). This will configure the project and download all the dependencies. 
```bash
cmake -G Unix\ Makefiles ..
```

### Step 3 - building the project
In the **build** folder, run the following command. This will build the project.
```bash
cmake --build . --config Debug
```

### Step 4 - running the tests
The tests are ready to run now. Use the following command in the **build** folder:
```bash
./CalculatorTests
```
