#include <Keypad.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <EEPROM.h>

#define servo_lock 1
#define servo_unlock 90

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;


int i = 0, j = 0, wpcount = 0, wptcount = 0; //wpcount = wrong password count, wpt = wrong password time count
char factory_password[] = {65, 48, 66, 48, 67, 48};
char password[6];
char present_password[6];
char input_key = 0;
char new_password[6];



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
  lcd.setCursor(4, 0);
  lcd.print("Welcome");
  delay(1500);
  lcd.setCursor(2, 0);
  lcd.print("Arduino Door");
  lcd.setCursor(2, 1);
  lcd.print("Lock Project");
  delay(1700);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Enter Password");
  lcd.setCursor(5, 1);
  
  for (int j = 0; j < 6; j++){
      present_password[j] = EEPROM.read(j);
  }
  j = 0;
}


void loop(){
  lock();
  if(wpcount < 3){
    input_key = keypad_key.getKey();
    if (input_key) {
      password[i++] = input_key;
      lcd.setCursor(i+4, 1);
      lcd.print("*");
    }
    if (i == 6) {
      delay(1000);
      if (!(strncmp(password, present_password, 6)))
      {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Pass Accepted");
        unlock();
        delay(5000);
        wptcount = 0;
        wpcount = 0;
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Enter Password");
        lcd.setCursor(5, 1);
        i = 0;
      }
      else if (!(strncmp(password, factory_password, 6)))
      {
        int j = 0;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Factory Password");
        lcd.setCursor(4, 1);
        lcd.print("Accepted");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set New Password");
        lcd.setCursor(5, 1);
        while( j < 6){
          char input_key = keypad_key.getKey();
          if (input_key) {
            lcd.print(input_key);
            EEPROM.write(j, input_key);
            j++;
          }
        }
        for (int j = 0; j < 6; j++){
          present_password[j] = EEPROM.read(j);
        }
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Password Changed");
        delay(2000);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Enter Password");
        lcd.setCursor(5, 1);
        i = 0;
      }
  
      else {
      lock();
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Wrong Password");
      delay(2000);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Enter Password");
      lcd.setCursor(5, 1);
      i = 0;
      wpcount++;
      }
    }
  }
  else{
    int count = 5000+wptcount*1000;
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Locked");
    lcd.setCursor(0, 1);
    lcd.print("Seconds:");
    lcd.setCursor(9, 1);
    lcd.print(count/1000);
    delay(5000+wptcount*1000);
    wpcount = 0;
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Enter Password");
    lcd.setCursor(5, 1);
    wptcount++;
  }
}
void lock(){
  servo.write(servo_lock);
}
void unlock(){
  servo.write(servo_unlock);
}


