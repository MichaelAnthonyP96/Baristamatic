#include "gtest/gtest.h"
#include "CoffeeMachine.h"
#include "Drink.h"

TEST(MakeDrink, MakeCoffee) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.makeDrink(DRINKS::coffee);
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Coffee\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,7\n"
             "Cream,9\n"
             "Decaf Coffee,10\n"
             "Espresso,10\n"
             "Foamed Milk,10\n"
             "Steamed Milk,10\n"
             "Sugar,9\n"
             "Whipped Cream,10\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}