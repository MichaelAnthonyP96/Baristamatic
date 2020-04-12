//
// Created by Michael Anthony Pope on 4/8/20.
//

#include "CoffeeMachine.h"
#include "Inventory.h"
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

const std::map<DRINKS, std::vector<INGREDIENTS> > createDrinks() {
  std::vector<INGREDIENTS> coffeeIngredients{
      INGREDIENTS::Coffee, INGREDIENTS::Coffee, INGREDIENTS::Coffee,
      INGREDIENTS::Sugar, INGREDIENTS::Cream};
  std::vector<INGREDIENTS> decafCoffeeIngredients{
      INGREDIENTS::DecafCoffee, INGREDIENTS::DecafCoffee,
      INGREDIENTS::DecafCoffee, INGREDIENTS::Sugar, INGREDIENTS::Cream};
  std::vector<INGREDIENTS> caffeeLatteeIngredients{
      INGREDIENTS::Espresso, INGREDIENTS::Espresso, INGREDIENTS::SteamedMilk};
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

std::string drink2string(DRINKS d) {
  switch (d) {
  case DRINKS::coffee: {
    return "Coffee";
  }
  case DRINKS::decafCoffee: {
    return "Decaf Coffee";
  }
  case DRINKS::caffeLatte: {
    return "Caffe Latte";
  }
  case DRINKS::caffeAmericano: {
    return "Caffe Americano";
  }
  case DRINKS::caffeeMocha: {
    return "Caffe Mocha";
  }
  case DRINKS::cappuccino: {
    return "Cappuccino";
  }
  default:
    throw std::exception();
  }
}

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

double CoffeeMachine::calcPrice(DRINKS d) const {
  double price = 0.;
  auto currentRecipe = recipes.find(d)->second;
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
//  std::vector<std::string> tempVec(DRINKS_SIZE);
//  int idx = 0;
//  for (auto it = recipes.begin(); it != recipes.end(); ++it, ++idx) {
//    tempVec[idx] = drink2string(it->first);
//  }
//  std::sort(tempVec.begin(), tempVec.end());

  // cannot pre-reserve vec size and use assignment operator because price and
  // name variables are named const
  int idx = 0;
  for (auto it = recipes.begin(); it != recipes.end(); ++it, ++idx) {
    this->drinks.emplace_back(Drink(calcPrice(it->first), drink2string(it->first)));
    this->drinks[idx].setRecipe(it->second);
  }

  // display inventory and menu on machine startup
  this->displayInventory();
  this->displayMenu();
}

CoffeeMachine::~CoffeeMachine() {
  // delete[] drinks;
}

CoffeeMachine::CoffeeMachine(CoffeeMachine const &other) {

}

void CoffeeMachine::processInput(const std::string& userInput) {
  if (userInput == "r") {
    this->restock();
  } else if (userInput == "q") {
    exit(0);
  } else {
    switch (std::atoi(userInput.c_str())) {
    case 1: {
      this->makeDrink(DRINKS::coffee);
      break;
    }
    case 2: {
      this->makeDrink(DRINKS::decafCoffee);
      break;
    }
    case 3: {
      this->makeDrink(DRINKS::caffeLatte);
      break;
    }
    case 4: {
      this->makeDrink(DRINKS::caffeAmericano);
      break;
    }
    case 5: {
      this->makeDrink(DRINKS::caffeeMocha);
      break;
    }
    case 6: {
      this->makeDrink(DRINKS::cappuccino);
      break;
    }
    default:
      // TODO(mapope): determine if string input is a valid number
      std::cout << "Invalid selection: " << userInput << std::endl;
    }
  }
}

void CoffeeMachine::makeDrink(DRINKS d) {
  std::string myString = drink2string(d);
  auto it =
      find_if(drinks.begin(), drinks.end(), [&myString](const Drink &obj) {
        return obj.getName() == myString;
      });
  if (isStocked(*it)) {
    std::cout << "Dispensing: " << drink2string(d) << std::endl;
    // get the vector of the ingredients which are needed by the drink
    auto currentRecipe = recipes.find(d)->second;
    // remove the ingredients from the inventory
    for (auto it = currentRecipe.begin(); it != currentRecipe.end(); ++it) {
      Inventory[*it]--;
    }
    this->displayInventory();
    this->displayMenu();
  } else {
    std::cout << "Out of stock: " << drink2string(d) << std::endl;
  }
}

void CoffeeMachine::restock() {
  for (auto it = Inventory.begin(); it != Inventory.end(); ++it) {
    // restock all inventory levels to 10 parts each
    it->second = 10;
  }
}

void CoffeeMachine::displayInventory() {
  std::cout << "Inventory:\n";
  std::vector<std::string> ingredientNames;
  for (auto it = Inventory.begin(); it != Inventory.end(); ++it) {
    // display all ingredient names and quantity
    ingredientNames.push_back(ingredient2string(it->first) + "," + std::to_string(it->second));
  }
  std::sort(ingredientNames.begin(), ingredientNames.end());
  for (auto it = ingredientNames.begin(); it != ingredientNames.end(); ++it) {
    std::cout << *it;
    if ((it + 1) != ingredientNames.end())
      std::cout << "\n";
  }
  // flush buffer
  std::cout << std::endl;
}

void CoffeeMachine::displayMenu() {
  std::cout << "Menu:";
  // <drink number>,<drink name>,<cost>,<in-stock>
  int idx = 1;
  std::vector<std::string> menuItems;
  std::stringstream ss;
  for (auto it = drinks.begin(); it != drinks.end(); ++it) {
    // display all ingredient names and quantity
    ss << std::setprecision(2) << std::fixed << it->getName() << ",$" << it->getPrice() <<
        "," << (this->isStocked(*it) ? "true" : "false");
    menuItems.push_back(ss.str());
    ss.str(std::string());
  }
  std::sort(menuItems.begin(), menuItems.end());
  for (auto &&it : menuItems) {
    // display all ingredient names and quantity
    std::cout << "\n" << idx++ << "," << it;
  }
  // flush the buffer
  std::cout << std::endl;
}

bool CoffeeMachine::isStocked(Drink &d) {
  for( auto &&it : d.getRecipe()) {
    if((it.second > this->Inventory[it.first]) ) {
      return false;
    }
  }
  return true;
}
