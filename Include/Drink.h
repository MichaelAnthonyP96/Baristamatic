//
// Created by Michael Anthony Pope on 4/8/20.
//

#ifndef BARISTAMATIC_INCLUDE_DRINK_H_
#define BARISTAMATIC_INCLUDE_DRINK_H_

#include "Inventory.h"
#include "DrinkList.h"
#include <map>
#include <string>

class Drink {
public:
  Drink();
  Drink(DRINKS d);
  ~Drink() = default;
  Drink(Drink const &) = default;
  Drink(const double price, std::string name);
  void print() const;
  const std::string getName() const;
  const double getPrice() const;
  void setRecipe(std::vector<INGREDIENTS> list);
  bool stocked() const;
  std::map<INGREDIENTS, int> getRecipe();

private:
  const double price;     ///< the price of the drink
  bool inStock;           ///< whether or not the drink is currently available
  const std::string name; ///< name of the drink
  std::map<INGREDIENTS, int>
      recipe; ///< Quantity of ingredients need to make drink
};

#endif // BARISTAMATIC_INCLUDE_DRINK_H_
