#include <iostream>
#include <string>

int main ()
{
  std::string str="We are family";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (3);     // get from "live" to the end

  std::cout << str3  << '\n';

  return 0;
}
