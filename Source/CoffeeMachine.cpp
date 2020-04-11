//
// Created by Michael Anthony Pope on 4/8/20.
//

#include "CoffeeMachine.h"
#include <vector>
#include <iostream>

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

CoffeeMachine::CoffeeMachine() {
  // stock all inventory levels to 10 parts each
  for (auto placeholder = ingredientPrices.begin();
       placeholder != ingredientPrices.end(); ++placeholder) {
    Inventory.insert(std::pair<INGREDIENTS, int>(placeholder->first, 10));
  }
  // display inventory on machine startup
  this->displayInventory();
}

CoffeeMachine::~CoffeeMachine() {

  /*this->drinks = new Drink[6];
  for () {

  }*/
}

void CoffeeMachine::processInput(std::string userInput) {
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
  // TODO(mapope) : add check that the drink has enough ingredients
  std::cout << "Dispensing: " << drink2string(d)  << std::endl;
  // get the vector of the ingredients which are needed by the drink
  auto currentRecipe = recipes.find(d)->second;
  // remove the ingredients from the inventory
  for(auto it = currentRecipe.begin(); it != currentRecipe.end(); ++it) {
    Inventory[*it]--;
  }
}

}
