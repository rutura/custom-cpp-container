#include <iostream>
#include <algorithm>
#include <ranges>
#include "boxcontainer.h"
#include "point.h"


void print_view( auto& v){

    for(auto i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char **argv)
{
  BoxContainer<int> data;
  data.add(1);
  data.add(2);
  data.add(3);
  
  print_view(data);

  auto v = data | std::views::filter([](int n){return n%2!=0;})
                | std::views::transform([](int n){return n*10;})
                | std::views::reverse;
  print_view(v);
  
  //Blows up with the std::ranges::sort algorithm
  //std::ranges::sort(data,std::less<>{}); // Compiler error

	return 0;
}




