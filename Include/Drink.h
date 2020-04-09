//
// Created by Michael Anthony Pope on 4/8/20.
//

#ifndef BARISTAMATIC_INCLUDE_DRINK_H_
#define BARISTAMATIC_INCLUDE_DRINK_H_

#include <string>

class Drink {
public:
  Drink();
  virtual ~Drink() = default;
  Drink(const double price, std::string name);
  virtual void print() const = 0;
  const std::string getName() const;
private:
  const double price; ///< the price of the drink
  bool inStock; ///< whether or not the drink is currently available
  std::string name; ///< name of the drink
};

#endif // BARISTAMATIC_INCLUDE_DRINK_H_
