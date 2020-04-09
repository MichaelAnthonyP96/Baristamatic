//
// Created by Michael Anthony Pope on 4/8/20.
//

#include "CoffeeMachine.h"
#include <vector>

const std::map<INGREDIENTS, double> createPriceMap() {
  const std::map<INGREDIENTS , double> ingredientPriceMap = {
      {INGREDIENTS::Coffee, 0.75},
      {INGREDIENTS::DecafCoffee, 0.75},
      {INGREDIENTS::Sugar, 0.25},
      {INGREDIENTS::Cream, 0.25},
      {INGREDIENTS::SteamedMilk, 0.35},
      {INGREDIENTS::FoamedMilk, 0.35},
      {INGREDIENTS::Espresso, 1.10},
      {INGREDIENTS::Cocoa, 0.9},
      {INGREDIENTS::WhippedCream, 1.00}
  };
  return ingredientPriceMap;
}

const std::map<DRINKS, std::vector<INGREDIENTS> > createDrinks() {
  std::vector<INGREDIENTS> coffeeIngredients{
      INGREDIENTS::Coffee, INGREDIENTS::Coffee, INGREDIENTS::Coffee,
      INGREDIENTS::Sugar, INGREDIENTS::Cream};
  std::vector<INGREDIENTS> decafCoffeeIngredients{
      INGREDIENTS::DecafCoffee, INGREDIENTS::DecafCoffee,
      INGREDIENTS::DecafCoffee, INGREDIENTS::Sugar, INGREDIENTS::Cream};
  std::vector<INGREDIENTS> caffeeLatteeIngredients{
      INGREDIENTS::DecafCoffee, INGREDIENTS::DecafCoffee,
      INGREDIENTS::DecafCoffee, INGREDIENTS::Sugar, INGREDIENTS::Cream};
  std::vector<INGREDIENTS> caffeeAmericanoIngredients{
      INGREDIENTS::Espresso, INGREDIENTS::Espresso, INGREDIENTS::Espresso};
  std::vector<INGREDIENTS> caffeeMochaIngredients{
      INGREDIENTS::Espresso, INGREDIENTS::Cocoa, INGREDIENTS::SteamedMilk,
      INGREDIENTS::WhippedCream};
  std::vector<INGREDIENTS> cappucinoIngredients{
      INGREDIENTS::Espresso, INGREDIENTS::Espresso, INGREDIENTS::SteamedMilk,
      INGREDIENTS::FoamedMilk};

  const std::map<DRINKS, std::vector<INGREDIENTS>> recipes = {
      {DRINKS::coffee, coffeeIngredients},
      {DRINKS::decafCoffee, decafCoffeeIngredients},
      {DRINKS::caffeLatte, caffeeLatteeIngredients},
      {DRINKS::caffeAmericano, caffeeAmericanoIngredients},
      {DRINKS::caffeeMocha, caffeeMochaIngredients},
      {DRINKS::cappuccino, cappucinoIngredients}
      };
  return recipes;
}

const std::map<DRINKS, std::vector<INGREDIENTS>> CoffeeMachine::recipes = createDrinks();

const std::map<INGREDIENTS, double> CoffeeMachine::ingredientPrices =
    createPriceMap();

CoffeeMachine::CoffeeMachine() {

  /*this->drinks = new Drink[6];
  for () {

  }*/
}

CoffeeMachine::~CoffeeMachine() {

  /*this->drinks = new Drink[6];
  for () {

  }*/
}

void CoffeeMachine::displayInventory() {
  /*for (Drink* d : drinks) {
    d->print();
  }*/
}

void CoffeeMachine::restock() const {

}
