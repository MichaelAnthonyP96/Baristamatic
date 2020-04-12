//
// Created by Michael Anthony Pope on 4/8/20.
//

#ifndef BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
#define BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_

#include "Drink.h"
#include "Inventory.h"
#include <map>
#include <string>
#include <vector>



// TODO(mapope): add namespace to avoid collision between DRINKS::coffee
//  and INGREDIENTS::coffee

constexpr auto DRINKS_BEGIN = __LINE__;
enum DRINKS {
  coffee,
  decafCoffee,
  caffeLatte,
  caffeAmericano,
  caffeeMocha,
  cappuccino
};
constexpr auto DRINKS_SIZE = __LINE__ - DRINKS_BEGIN - 3;

class CoffeeMachine {
public:
  CoffeeMachine();
  ~CoffeeMachine();

  void makeDrink(DRINKS d);
  void displayInventory();
  void displayMenu();
  void restock();
  void processInput(const std::string& userInput);

private:
  std::vector<Drink> drinks;
  std::map<INGREDIENTS, int> Inventory;
  static const std::map<DRINKS , std::vector<INGREDIENTS>> recipes;
  static const std::map<INGREDIENTS , double> ingredientPrices;
};

const std::map<INGREDIENTS, double> createPriceMap();

#endif // BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
