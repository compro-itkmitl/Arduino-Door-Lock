#include <Keypad.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define servo_lock 1
#define servo_unlock 180

int check = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

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
  servo.attach(13);
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

void loop(){
  lock();
  input_key = keypad1.getKey();
  if(input_key == '#'){
    change_password();
  }
  if(input_key) {
    password[i++] = input_key;
    lcd.setCursor(i, 1);
    lcd.print("*");
  }
  if(i == 6){
    for(int i = 0; i < 6; i++){
      present_password[i] = EEPROM.read(i);
    }
    if(strcmp(password, present_password) == 0){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pass Accepted");
      unlock();
      delay(7000);
      check = 1;
      i = 0;
    }
    else if(check = 0){
      if(strcmp(password, factory_password) == 0){
        change_password();
      }
    }
    else{
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
}
 
void check_password(){
  
}


void lock(){
  servo.write(servo_lock);
}

void unlock(){
  servo.write(servo_unlock);
}
