# Self-taught C & C++

Playground for my C & C++ journey

I am currently learning C++ with [LEARN C++](https://www.learncpp.com) & C++ Programmer 3rd edition by Wiley. Therefore, this playground will consists of exercises provided from these resources.

---

## iostream library

Most commonly used library for data input & output.

```cpp
#include <iostream> // for std::cout

int main()
{
    std::cout << "Hello" << " world!"; // << is insertion operator

    int x{ }; // define variable x to hold user input (and zero-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x
    // >> is extraction operator
 
    std::cout << "Entered Number " << x << std::endl; // std::endl will cause the cursor to move to the next line of the console
    std::cout << "Hi!\n"; // \n is preferred as it does 1 job rather than 2 jobs where std::endl add newline & flushes buffer, user '\n' when it is by itself as char type
    return 0;
}
```
