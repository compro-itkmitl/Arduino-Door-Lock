#include <Keypad.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <EEPROM.h>

#define servo_lock 1
#define servo_unlock 180

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;


int i = 0;
char factory_password[] = {48, 48, 48, 48, 48, 48};
char password[6];
char present_password[6];
char input_key = 0;
char fctpass[7];



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


void setup(){
  Serial.begin(9600);
  servo.attach(12);
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("  Arduino Door");
  lcd.setCursor(0, 1);
  lcd.print("  Lock Project");
  delay(1700);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  lcd.setCursor(0, 1);
  
  for (int j = 0; j < 4; j++){
      EEPROM.write(j, 55);
  }
  for (int j = 0; j < 4; j++){
      present_password[j] = EEPROM.read(j);
  }
}


void loop(){
  lock();
  input_key = keypad_key.getKey();
  if (input_key) {
    password[i++] = input_key;
    lcd.setCursor(i-1, 1);
    lcd.print(input_key);
  }
  if (i == 4) {
    delay(200);
    if (!(strncmp(password, present_password, 4)))
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pass Accepted");
      unlock();
      delay(5000);
      lcd.setCursor(0, 1);
      lcd.print("Pres # to change");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password:");
      lcd.setCursor(0, 1);
      i = 0;
    }
    else {
      lock();
      lcd.clear();
      lcd.print("Wrong Password");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password");
      lcd.setCursor(0, 1);
      i = 0;
    }
  }
}

void lock(){
  servo.write(servo_lock);
}

void unlock(){
  servo.write(servo_unlock);
}


void factoryWrite() {  //777777
  EEPROM.write(0, 55);
  EEPROM.write(1, 55);
  EEPROM.write(2, 55);
  EEPROM.write(3, 55);
  EEPROM.write(4, 55);
  EEPROM.write(5, 55);
}

void factoryRead() {  //777777
  fctpass[0] = EEPROM.read(0);
  fctpass[1] = EEPROM.read(1);
  fctpass[2] = EEPROM.read(2);
  fctpass[3] = EEPROM.read(3);
  fctpass[4] = EEPROM.read(4);
  fctpass[5] = EEPROM.read(5);
}



