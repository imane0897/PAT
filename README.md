# PAT

[TOC]

* 1022

  重点在于字符串的读入
  * getline(cin, line)
  * keywords 的按 word 读入
* 1052

   https://www.sigmainfy.com/blog/pat-1052-linked-list-soring.html

   注意
   * 虽然 n  正整数，但是链表可能为空，即头结点为 NULL
   * memory中的全部结点并不一定属于同一个链表
* 1054

   hash
* 1039

   由于 MAXN 和 MAXM 都比较大，内存不够，需要用vector

   string, cout, cin 会导致超时

   由于 name 是格式固定的字符串，映射成 int 类型时可以采用“进制”的思想。
   e.g. $ABC1 -> (((A*26)+B)*26+C)*26+1$
* 1042

   copy char array
``` cpp
#include <cstring>
char *a = " ";
char *b = " ";
strcpy(a, b)
```
​	Note that plain array is not assignable.
 	copy string or plain array
```cpp
memset(a, b, sizeof(a))
```
​	can be used when a, b are 2D arrays or strings

## 笔记

### C++ String
Operations

- empty( )    bool

- size( )         unsigned int

- substr()

  ```cpp
  #include <iostream>
  #include <string>
  std::string str = "We think in generalities, but we live in detials.";
  std::string str2 = str.subtr(3, 5); // "think"
  std::size_t pos = str.find("live"); // position of "live" in str
  std::string str3 = str.substr(pos); // get from "live" to the end, "think live in details."

  ```

  ​


- compare strings

  == , !=, <, <=, >, >=

- add two strings

  +, +=, +" ..."

- reverse

  ```cpp
  #include <algorithm>
  std::reverse(mystring.begin(), mystring.end());
  ```



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



### C++ Array

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



### <climits>

INT_MIN

INT_MAX



### convert int to string

```cpp
s = std::to_string(i)
```



### sort

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



### memset

```cpp
#include <cstring>
memset(array_name, value, size);
```



### Palindromic Number

字符串存储数字，利用 C++ 的 reverse 进行反转，用字符串相等判断是否为回文数。

```cpp
#include <algorithm>
std::reverse(mystring.begin(), mystring.end());
```

reverse 的操作对象是 BidirectionalIterator



### 超时的可能原因

1. 死循环
2. 调用函数造成过大开销。可以通过传实参的方法进行优化。
3. 遍历累加。利用好原点。(PAT 1046)



### vector



| Operations         | Explanations                             |
| ------------------ | ---------------------------------------- |
| v.empty()          | Returns true if v is empty               |
| v.size()           | Returns the number of elements in v      |
| v.push_back(t)     | Adds an element with value t to end of v |
| v[n]               | Returns a reference to the element at position in v |
| v1 = v2            | Replaces the elements in v1 with a copy of the elements in v2 |
| v1 = {a, b, c ...} | Replaces the elements in v1 with a copy of the elements in the comma-separated list. |
| v1 == v2           | v1 and v2 are equal if they have the same number of elements and each element in v1 is equal to the corresonding element in v2 |
| v1 != v2           |                                          |
| <, <=, >, >=       | Have their normal meanings using dictionary ordering. |

 

### dictionary order rule

1. If two strings have different lengths and if every character in the shorter string is equal to the corresponding character of the longer string, then the shorter string is less than the longer one.
2. If any characters at corresponding positions in the two strings differ, then the result of the string comparison is the result of comparing the first character at which the strings differ.

```cpp
string str = "Hello"; 
string phrase = "Hello World"; 
string slang = "Hiya";

// Using rule 1, we see that str is less than phrase. By applying rule 2, we see that slang is greater than both str and phrase.
```



### iterator

Ways to initialize a `vector`

```cpp
vector<T> v1;
vector<T> v2(v1);
vector<T> v2 = v1;
vector<T> v3(n, val);
vector<T> v4(n);
vector<T> v5{a, b, c};
vector<T> v5 = {a, b, c ...};
```



| Operations     | Explanations                             |
| -------------- | ---------------------------------------- |
| *iter          | Returns a reference to the element denoted by the iterator iter. |
| iter->mem      | Dereferences iter and fetches the member named mem from the underlying element. Equivalent to (*iter).mem. |
| ++iter         | Increments iter to refer to the next element in the container. |
| —iter          | Decrements iter to refer to the previous elements in the container. |
| iter1 == iter2 | Compares two iterators for equality(inequality). Two iterators are equal if they denote the same element or if they are the off-the-end iterator for the same container. |
| iter1 != iter2 |                                          |



### 指针

```cpp
string s = "some strings";
if (s.begin() != s.end()) {
	auto it = s.begin();
    *it = toupper(*it);
}
```



### C指针与C++引用

```c
#include <stdio.h>
void swap(int* a, int* b) {
  int t = *a; *a = *b; *b = t;
}
int main(void) {
  int a = 3, b = 4;
  swap(&a, &b);
}
```

```cpp
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
  int t = a; a = b; b = t; 
}
int main(void) {
  int a = 3, b = 4;
  swap(a, b);
}
```



### C++ Queue

| Function | Explaination        |
| -------- | ------------------- |
| empty    |                     |
| size     |                     |
| front    | Access next element |
| back     | Access last element |
| push     | push back           |
| pop      | pop front           |