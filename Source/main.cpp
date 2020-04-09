#include <iostream>
#include "CoffeeMachine.h"
#include "Drink.h"
#include "Coffee.h"

int main() {
  CoffeeMachine c;

  std::string userInput;
   do {
     std::cin >> userInput;
     std::transform(userInput.begin(), userInput.end(), userInput.begin(),
                    [](unsigned char c) { return std::tolower(c); });
    if (userInput == "r") {
      c.restock();
    } else if (userInput == "q") {
      return 0;
    } else {
      switch (std::atoi(userInput.c_str())) {
      case 1: {
        break;
      }
      case 2: {
        break;
      }
      case 3: {
        break;
      }
      case 4: {
        break;
      }
      case 5: {
        break;
      }
      case 6: {
        break;
      }
      default:
        throw std::exception();
      }
    }
  } while (true);
}
