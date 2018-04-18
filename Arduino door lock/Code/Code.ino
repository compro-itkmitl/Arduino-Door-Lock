#include <Keypad.h> 
#include <LiquidCrystal_I2C.h>

const byte rows = 4;
const byte columns = 4;

char hexaKeys[rows][columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte row_pins[rows] = {9, 8, 7, 6};
byte column_pins[columns] = {5, 4, 3, 2};

Keypad keypad_key = Keypad( makeKeymap(hexaKeys), row_pins, column_pins, rows, columns);
