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

TEST(MakeDrink, DecafCoffee) {

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
  c.makeDrink(DRINKS::decafCoffee);
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Decaf Coffee\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,9\n"
             "Decaf Coffee,7\n"
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

TEST(MakeDrink, CaffeLatte) {

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
  c.makeDrink(DRINKS::caffeLatte);
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Caffe Latte\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,8\n"
             "Foamed Milk,10\n"
             "Steamed Milk,9\n"
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
}

TEST(MakeDrink, CaffeAmericano) {

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
  c.makeDrink(DRINKS::caffeAmericano);
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Caffe Americano\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,7\n"
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
}

TEST(MakeDrink, CaffeMocha) {

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
  c.makeDrink(DRINKS::caffeeMocha);
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Caffe Mocha\n"
             "Inventory:\n"
             "Cocoa,9\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,9\n"
             "Foamed Milk,10\n"
             "Steamed Milk,9\n"
             "Sugar,10\n"
             "Whipped Cream,9\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(MakeDrink, Cappuccino) {

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
  c.makeDrink(DRINKS::cappuccino);
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Cappuccino\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,8\n"
             "Foamed Milk,9\n"
             "Steamed Milk,9\n"
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
}