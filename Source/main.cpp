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
    c.processInput(userInput);
    } while (true);
}
