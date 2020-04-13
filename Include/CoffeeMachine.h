//
// Created by Michael Anthony Pope on 4/8/20.
//

#ifndef BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
#define BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_

#include "Drink.h"
#include <map>
#include <string>
#include <vector>

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
  /**
   * \brief: default constructor which initializes all possible drinks.
   *
   * Drink list is ordered by drink name
   */
  CoffeeMachine();

  /**
   * \brief: destructor which does not explicitly delete anything
   */
  ~CoffeeMachine();

  /**
   * \brief: Copy constructor which copies over all member variables
   * @param other
   */
  CoffeeMachine(CoffeeMachine const &other);

  /**
   * \brief: if possible, makeDrink i and update the inventory
   *
   * @param i index of the menu-item to be made
   */
  void makeDrink(long i);

  /**
   * \brief: determine if the drink can be made
   *
   * If the quantity of the requested ingredients is greater than the amount in
   * the Inventory, the drink can be made
   *
   * @param d drink which is being checked
   * @return true or false based on Inventory stock
   */
  bool isStocked(Drink &d);

  /**
   *\brief: calculate the price of the drink based on the ingredients
   *
   * @param drinkName name of the drink which will be used to find the recipe
   * @return price of the drink
   */
  double calcPrice(std::string drinkName) const;

  /**
   * \brief: print out the current Inventory in alphabetical order
   *
   * Since hash's cannot be ordered, the sorting is done every time the function
   * is called. This is potential room for improvement
   */
  void displayInventory();

  /**
   * \brief: print out the Menu in alphabetical order
   *
   * The function accounts for user added new drinks
   */
  void displayMenu();

  /**
   * \brief: restock the Inventory to 10 units for each ingredient
   */
  void restock();

  /**
   * \brief Process the user supplied input
   *
   * If a user supplies:
   *    r/R-> restock the machine
   *    q/Q -> quit the machine
   *    1....DRINKS_SIZE -> make drink * if the ingredients are available
   *    anything else -> print invalid argument
   *
   * @param userInput input argument take from the standard input stream
   */
  void processInput(const std::string &userInput);

  /**
   * \brief: run the machine, which handles all user input appropriately
   */
  void run();

private:
  std::vector<Drink> drinks; ///< vector of all possible drinks
  std::map<INGREDIENTS, int>
      Inventory; ///< Hash table for ingredients and their quantities
  static const std::map<std::string, std::vector<INGREDIENTS>>
      recipes; ///< Hash table for drinkNames and their required ingredients
  static const std::map<INGREDIENTS, double>
      ingredientPrices; ///< Hash table for ingredient and their prices
};

const std::map<INGREDIENTS, double> createPriceMap();
const std::map<std::string, std::vector<INGREDIENTS>> createDrinks();
std::vector<INGREDIENTS> defineDrink(int numIngredients, ...);

#endif // BARISTAMATIC_INCLUDE_COFFEEMACHINE_H_
