//
// Created by Michael Anthony Pope on 4/8/20.
//

#ifndef BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
#define BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_

#include "Drink.h"
#include <map>
#include <string>
#include <vector>

// TODO(mapope): add namespace to avoid collision between DRINKS::coffee
//  and INGREDIENTS::coffee

//std::string drink2string(DRINKS d) {
//  switch (d) {
//  case DRINKS::coffee: {
//    return "Coffee";
//  }
//  case DRINKS::decafCoffee: {
//    return "Decaf Coffee";
//  }
//  case DRINKS::caffeLatte: {
//    return "Caffe Latte";
//  }
//  case DRINKS::caffeAmericano: {
//    return "Caffe Americano";
//  }
//  case DRINKS::caffeMocha: {
//    return "Caffe Mocha";
//  }
//  case DRINKS::cappuccino: {
//    return "Cappuccino";
//  }
//  default:
//    throw std::exception();
//  }
//}

std::string ingredient2string(INGREDIENTS i) {
  switch (i) {
  case INGREDIENTS::Coffee: {
    return "Coffee";
  }
  case INGREDIENTS::DecafCoffee: {
    return "Decaf Coffee";
  }
  case INGREDIENTS::WhippedCream: {
    return "Whipped Cream";
  }
  case INGREDIENTS::Cocoa: {
    return "Cocoa";
  }
  case INGREDIENTS::Espresso: {
    return "Espresso";
  }
  case INGREDIENTS::Sugar: {
    return "Sugar";
  }
  case INGREDIENTS::Cream: {
    return "Cream";
  }
  case INGREDIENTS::SteamedMilk: {
    return "Steamed Milk";
  }
  case INGREDIENTS::FoamedMilk: {
    return "Foamed Milk";
  }
  default:
    throw std::exception();
  }
}


class CoffeeMachine {
public:
  CoffeeMachine();
  ~CoffeeMachine();
  CoffeeMachine(CoffeeMachine const &other);
  void makeDrink(long i);
  bool isStocked(Drink &d);
  double calcPrice(std::string drinkName) const;
  void displayInventory();
  void displayMenu();
  void restock();
  void processInput(const std::string& userInput);

private:
  std::vector<Drink> drinks;
  std::map<INGREDIENTS, int> Inventory;
  static const std::map<std::string, std::vector<INGREDIENTS>> recipes;
  static const std::map<INGREDIENTS , double> ingredientPrices;
};

const std::map<INGREDIENTS, double> createPriceMap();

#endif // BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
