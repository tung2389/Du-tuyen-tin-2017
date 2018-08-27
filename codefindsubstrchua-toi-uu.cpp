#include <string>
#include <iostream>
int main()
{
	std::string a,b;
	std::string::size_type pos = 0;
	std::cin >> a >> b;
   int occurrences = 0;
 while ((pos = a.find(b, pos )) != std::string::npos)  {
   	occurrences++;
   	if((pos = a.find(b, pos )) != std::string::npos)
   	std::cout << occurrences << " ";
    pos+=1;
   }
}
