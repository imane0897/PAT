[TOC]

# C++ String
Operations

- empty( )    bool
- size( )         unsigned int

---

- compare strings

  == , !=, <, <=, >, >=

- add two strings

  +, +=, +" ..."



These functions are defined in `cctype` header.

| function    | return                                   |
| ----------- | ---------------------------------------- |
| isalnum(c)  | true if c is a letter or a digit         |
| isalpha(c)  | true if c is a letter                    |
| isdigit(c)  | true if c is a digit                     |
| islower(c)  | true if c is a lowercase letter          |
| isupper(c)  | true if c is a uppercase letter          |
| isxdigit(c) | true if c is a hexadecimal digit         |
| tolower(c)  | if c is an uppercase letter, return its lowercase |
| toupper(c)  | if c is an lowercase letter, return its uppercase |
| isspace(c)  | true if c is a whitespace                |



# C++ Array

```cpp
// Note to add header file 
#include <array>
std::array<int, 5> myarray;
// entire array is initialized to 0
```

| funtion             | return                                   |
| ------------------- | ---------------------------------------- |
| .at(size_type n)    | reference to the element at position n   |
| operator[]          | reference to the element at position n   |
| .back() \| .front() | reference to the last / first element    |
| .begin() \| .end()  | iterator pointing to the first / last element |
| .data()             | pointer to the first ele                 |
| .empty()            | bool value indicating empty or not       |
| .fill(val)          | sets *val* as the value for all the elements |
| .max_size()         | maximum number of elements the array can hold |
| .size()             | number of elements in the array container |
| .swap(array &x)     | exchanges the content  by *x*            |



```cpp
for (auto it = myarray.begin(); it != myarray.end(); ++it){
  std::cout << *it << '\n';
}
```



# <climits>

INT_MIN

INT_MAX



# convert int to string

```cpp
s = std::to_string(i)
```



# sort

```cpp
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               
  // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           	
  //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); 
  // 12 32 45 71(26 33 53 80)
 
  return 0;
}
```



# memset

```cpp
#include <cstring>
memset(array_name, value, size);
```

