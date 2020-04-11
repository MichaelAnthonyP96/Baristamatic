//
// Created by Michael Anthony Pope on 4/8/20.
//

#ifndef BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
#define BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_

#include <string>
#include <map>
#include "Drink.h"

enum INGREDIENTS {
  Coffee,
  DecafCoffee,
  Sugar,
  Cream,
  SteamedMilk,
  FoamedMilk,
  Espresso,
  Cocoa,
  WhippedCream
};

// TODO(mapope): add namespace to avoid collision between DRINKS::coffee
// and INGREDIENTS::coffee

enum DRINKS {
  coffee,
  decafCoffee,
  caffeLatte,
  caffeAmericano,
  caffeeMocha,
  cappuccino
};

class CoffeeMachine {
public:
  CoffeeMachine();
  ~CoffeeMachine();

  void makeDrink(Drink *d);
  void displayInventory();
  void displayMenu();
  void restock();
  void processInput(std::string userInput);

private:
  Drink *drinks;
  std::map<INGREDIENTS, int> Inventory;
  static const std::map<DRINKS , std::vector<INGREDIENTS>> recipes;
  static const std::map<INGREDIENTS , double> ingredientPrices;
};

const std::map<INGREDIENTS, double> createPriceMap();

#endif // BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
