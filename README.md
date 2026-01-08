# leetcode

Passing [Data Structures and Algorithms](https://leetcode.com/explore/featured/card/leetcodes-interview-crash-course-data-structures-and-algorithms/) course on LeetCode.

# Install C++ compiler and build tools
brew install cmake
brew install llvm

# Verify installation
clang++ --version
cmake --version

# Compile and run directly
clang++ -std=c++17 problems/template.cpp -o build/template && ./build/template

# Or use the shortcut
clang++ -std=c++17 problems/template.cpp && ./a.out

# Copy template
cp problems/template.cpp problems/new_problem.cpp
