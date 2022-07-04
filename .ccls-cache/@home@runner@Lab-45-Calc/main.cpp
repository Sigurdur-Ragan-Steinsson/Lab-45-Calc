#include <iostream>
#include <string>

using namespace std;

class Ti_84C
{
  public:
    Ti_84C (float userNum1, float userNum2);
    float calc();
  private:
    float num1;
    float num2;
    bool errorFree = true;
};

Ti_84C::Ti_84C(float userNum1, float userNum2)
{
  num1 = userNum1;
  num2 = userNum2;
}

// If the number 1 + number 2 > 32,768 it can't be correct since integer values only go to 32768 throw an error

// If the number 1 - number 2 = a negative number let me know you can't subtract the 2 numbers throw an error

// If the number 1 * number 2 > 32,768 it can't be correct since integer values only go to 32768 throw an error

// If the number 1 / number 2 and number 2 = 0 then throw an error about dividing by zero.

// If the data is valid display all the correct math answers

float Ti_84C::calc()
{
  try{
  if(num1 + num2 > 32768 || num1 * num2 > 32768)
    {
    errorFree = false;
    throw(32768);
    } 
  }
    catch(int x)
  {
    cout << "Error number " << x << " integer value exceeds 32,768" << endl;
    return 0;
  }
  try
  {
    if(num1 - num2 < 0)
    {
    errorFree = false;
    throw(-1);
    }
  }
    catch(int x)
    {
      cout << "Error number " << x << " value < 0, can't subtract the 2 numbers" << endl;
      return 0;
    }
  try
  {
    if(num2 == 0)
    {
      errorFree = false;
      throw(0);
    }
  }
  catch(int x)
  {
    cout << "Error number " << x << " denominator = 0, can't divide the 2 numbers" << endl;
    return 0;
  }
  if(errorFree){
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 + num2 << endl; 
    cout << num1 << " * " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " / " << num2 << " = " << num1 + num2 << endl;
  }
}



int main() {
  float number1, number2;
  cout << "Please enter the first number" << endl;
  cin >> number1;
  cout << "Please enter the second number" << endl;
  cin >> number2;
  Ti_84C myCalc(number1,number2);
  myCalc.calc();
}