#include <LiquidCrystal.h>
#include <Keypad.h>
 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  // setting the expander address, number of lcd columns, number of lcd rows

long first = 0;
long second = 0;
double total = 0;
int posit = 0 ;
char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = { // define keypad equivalents
  {'1','2','3','/'},
  {'4','5','6','*'},
  {'7','8','9','-'},
  {'C','0','=','+'}
};
byte rowPins[ROWS] = {7 ,6 ,5 ,4}; // connect rows from keypad to Arduino
byte colPins[COLS] = {3, 2, 1, 0}; // connect columns from keypad to Arduino

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); // class Keypad instance initialization

void setup(){
  lcd.begin(16,2);
  lcd.setCursor(5,0);
  lcd.print("Alkitab");
  lcd.setCursor(3,1);
  lcd.print("University");
  delay(3000);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Baisc Calculator");
  lcd.setCursor(4,1);
  lcd.print("Arduino");
  delay(2000);
  lcd.clear(); //clears the LCD screen and positions the cursor in the upper-left corner. 
}
void loop()
{
  customKey = customKeypad.getKey();
  switch(customKey) 
  {
  case '0' ... '9': // get first value for calculation
    lcd.setCursor(0,0);
    first = first * 10 + (customKey - '0');
    lcd.print(first);
    posit++;
    break;

  case '+':
    first = (total != 0 ? total : first);
    lcd.setCursor(posit,0);
    lcd.print("+");
    posit++;
    second = SecondNumber(); // get second number
    total = first + second;
    lcd.setCursor(1,1);
    lcd.print(total);
    first = 0, second = 0; // reset the values
    posit=0;
    break;

  case '-':
    first = (total != 0 ? total : first);
    lcd.setCursor(posit,0);
    lcd.print("-");
    posit++;
    second = SecondNumber();
    total = first - second;
    lcd.setCursor(1,1);
    lcd.print(total);
    first = 0, second = 0;
    posit=0;
    break;

  case '*':
    first = (total != 0 ? total : first);
    lcd.setCursor(posit,0);
    lcd.print("*");
    posit++;
    second = SecondNumber();
    total = first * second;
    lcd.setCursor(1,1);
    lcd.print(total);
    first = 0, second = 0;
    posit=0;
    break;

  case '/':
    first = (total != 0 ? total : first);
    lcd.setCursor(posit,0);
    lcd.print("/");
    posit++;
    second = SecondNumber();
    lcd.setCursor(1,1);

    second == 0 ? lcd.print("Error") : total = (float)first / (float)second;

    lcd.print(total);
    first = 0, second = 0;
    posit=0;
    break;

  case 'C':
    total = 0;
    first = 0;
    second = 0;
    posit = 0;
    lcd.clear();
    break;
  }
}

long SecondNumber()
{
  while( 1 )
  {
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9')
    {
      second = second * 10 + (customKey - '0');
      lcd.setCursor(posit,0);
      lcd.print(second);
    }
    if(customKey == 'C') {
      total = 0;
      first = 0;
      second = 0;
      posit = 0;
      lcd.clear();
      break;
    }

    if(customKey == '='){
      lcd.setCursor(0,1);
          lcd.print("=");
      
      posit = total;
      lcd.clear();
   lcd.setCursor(0,1);
          lcd.print("=");
      break;
    }
  }
 return second;} 
