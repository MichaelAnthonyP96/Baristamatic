//
// Created by Michael Anthony Pope on 4/8/20.
//

#include "CoffeeMachine.h"
#include <iomanip>
#include <iostream>
#include <sstream>
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

std::vector<INGREDIENTS> defineDrink(int numIngredients, ...) {
  std::vector<INGREDIENTS> v;
  va_list vaList;
  va_start(vaList, numIngredients); // initialize vaList for num number of arguments
  // can't pre-allocate vector size, enums are all converted to lowest value
  for (int i = 0; i < numIngredients; ++i) {
    v.push_back(va_arg(vaList, INGREDIENTS));
  }
  va_end(vaList); // clean memory reserved for vaList
  return v;
}

const std::map<std::string, std::vector<INGREDIENTS>> createDrinks() {
  const std::map<std::string, std::vector<INGREDIENTS>> recipes = {
      {"Coffee", defineDrink(5, INGREDIENTS::Coffee, INGREDIENTS::Coffee,
                             INGREDIENTS::Coffee, INGREDIENTS::Sugar,
                             INGREDIENTS::Cream)},
      {"Decaf Coffee",
       defineDrink(5, INGREDIENTS::DecafCoffee, INGREDIENTS::DecafCoffee,
                   INGREDIENTS::DecafCoffee, INGREDIENTS::Sugar,
                   INGREDIENTS::Cream)},
      {"Caffe Latte",
       defineDrink(3, INGREDIENTS::Espresso, INGREDIENTS::Espresso,
                   INGREDIENTS::SteamedMilk)},
      {"Caffe Americano",
       defineDrink(3, INGREDIENTS::Espresso, INGREDIENTS::Espresso,
                   INGREDIENTS::Espresso)},
      {"Caffe Mocha",
       defineDrink(4, INGREDIENTS::Espresso, INGREDIENTS::Cocoa,
                   INGREDIENTS::SteamedMilk, INGREDIENTS::WhippedCream)},
      {"Cappuccino",
       defineDrink(4, INGREDIENTS::Espresso, INGREDIENTS::Espresso,
                   INGREDIENTS::SteamedMilk, INGREDIENTS::FoamedMilk)}};
#define DRINKS_SIZE recipes.size()
  return recipes;
}

const std::map<std::string, std::vector<INGREDIENTS>> CoffeeMachine::recipes = createDrinks();

const std::map<INGREDIENTS, double> CoffeeMachine::ingredientPrices =
    createPriceMap();

double CoffeeMachine::calcPrice(std::string drinkName) const {
  double price = 0.;
  auto currentRecipe = recipes.find(drinkName)->second;
  for (auto &&it : currentRecipe) {
    price += ingredientPrices.find(it)->second;
  }
  return price;
}

CoffeeMachine::CoffeeMachine() {
  // stock all inventory levels to 10 parts each
  for (auto placeholder = ingredientPrices.begin();
       placeholder != ingredientPrices.end(); ++placeholder) {
    Inventory.insert(std::pair<INGREDIENTS, int>(placeholder->first, 10));
  }
  // iterate over DRINKS enum, create drinks obj for each
  std::vector<std::string> tempVec(DRINKS_SIZE);
  int idx = 0;
  for (auto it = recipes.begin(); it != recipes.end(); ++it, ++idx) {
    tempVec[idx] = it->first;
  }
  std::sort(tempVec.begin(), tempVec.end());

  // cannot pre-reserve vec size and use assignment operator because price and
  // name variables are named const
  idx = 0;
  for (auto it = recipes.begin(); it != recipes.end(); ++it, ++idx) {
    this->drinks.emplace_back(Drink(calcPrice(it->first), it->first));
    this->drinks[idx].setRecipe(it->second);
  }

  // display inventory and menu on machine startup
  this->displayInventory();
  this->displayMenu();
}

CoffeeMachine::~CoffeeMachine() {
  // delete[] drinks;
}

CoffeeMachine::CoffeeMachine(CoffeeMachine const &other)
    : drinks(other.drinks), Inventory(other.Inventory) {}

void CoffeeMachine::processInput(const std::string &userInput) {
  if (userInput == "r" || userInput == "R") {
    this->restock();
  } else if (userInput == "q" || userInput == "Q") {
    exit(0);
  } else {
    try {
      char *end;
      long attemptedConversion = std::strtol(userInput.c_str(), &end, 10);
      if (attemptedConversion <= 0 || attemptedConversion > DRINKS_SIZE) {
        throw std::out_of_range(
            "User input is either out of bounds, or an invalid character");
      }
      this->makeDrink(attemptedConversion);
    } catch (...) {
      std::cout << "Invalid selection: " << userInput << std::endl;
      this->displayInventory();
      this->displayMenu();
    }
  }
}

void CoffeeMachine::makeDrink(long i) {
  // menu is 1-based indexing, hence why using i-1
  if (isStocked(drinks[i-1])) {
    std::cout << "Dispensing: " << drinks[i-1].getName() << std::endl;
    // get the vector of the ingredients which are needed by the drink
    auto currentRecipe = drinks[i-1].getRecipe();
    // remove the ingredients from the inventory
    for (auto it = currentRecipe.begin(); it != currentRecipe.end(); ++it) {
      Inventory[it->first] -= it->second;
    }
  } else {
    std::cout << "Out of stock: " << drinks[i-1].getName() << std::endl;
  }
  // display inventory and menu whether drink is successfully made or not
  this->displayInventory();
  this->displayMenu();
}

void CoffeeMachine::restock() {
  for (auto it = Inventory.begin(); it != Inventory.end(); ++it) {
    // restock all inventory levels to 10 parts each
    it->second = 10;
  }
  this->displayInventory();
  this->displayMenu();
}

void CoffeeMachine::displayInventory() {
  std::cout << "Inventory:";
  std::vector<std::string> ingredientNames;
  // sort the ingredient names
  for (auto it = Inventory.begin(); it != Inventory.end(); ++it) {
    ingredientNames.push_back(ingredient2string(it->first) + "," + std::to_string(it->second));
  }
  std::sort(ingredientNames.begin(), ingredientNames.end());
  // print out the sorted list
  for (auto it = ingredientNames.begin(); it != ingredientNames.end(); ++it) {
    std::cout << "\n" << *it;
  }
  // flush buffer
  std::cout << std::endl;
}

void CoffeeMachine::displayMenu() {
  // Drinks are already sorted by name
  int idx = 1;
  std::cout << "Menu:";
  for (auto it = drinks.begin(); it != drinks.end(); ++it) {
    // <drink number>,<drink name>,<cost>,<in-stock>
    std::cout << "\n"
              << idx++ << "," << std::setprecision(2) << std::fixed
              << it->getName() << ",$" << it->getPrice() << ","
              << (this->isStocked(*it) ? "true" : "false");
  }
  // flush the buffer
  std::cout << std::endl;
}

bool CoffeeMachine::isStocked(Drink &d) {
  for( auto &&it : d.getRecipe()) {
    // if the required quantity is greater than the current stock, return false
    if((it.second > this->Inventory[it.first]) ) {
      return false;
    }
  }
  return true;
}

void CoffeeMachine::run() {
  std::string userInput;
  // endless loop which will only terminate if the user provides a q or Q
  do {
    std::cin >> userInput;
    std::transform(userInput.begin(), userInput.end(), userInput.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    this->processInput(userInput);
    this->displayInventory();
    this->displayMenu();
  } while (true);
}
