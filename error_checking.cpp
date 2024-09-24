//-----------------------------------------------------------
//  Purpose:    Demonstrate error checking when reading int or float
//              read_integer1 - read integer and return 0 if invalid
//              read_float1 - read float and return 0 if invalid
//              read_integer2 - read until valid integer entered
//              read_float2 - read until valid float entered
// 
//-----------------------------------------------------------
#include <iostream>
using namespace std;

//-----------------------------------------------------------
int read_integer1(string prompt)
//-----------------------------------------------------------
{
   cout << prompt;
   string input;
   cin >> input;
   int num = atoi(input.c_str());
   return num;
}

//-----------------------------------------------------------
float read_float1(string prompt)
//-----------------------------------------------------------
{
   cout << prompt;
   string input;
   cin >> input;
   float num = 0;
   try
      { num = stof(input); }
   catch (...) 
      { num = 0; }
   return num;
}

//-----------------------------------------------------------
int read_integer2(string prompt1, string prompt2)
//-----------------------------------------------------------
{
   cout << prompt1;
   int num;
   cin >> num;
   while (cin.fail())
   {
      cin.clear();
      string skip;
      getline(cin, skip);
      cout << prompt2;
      cin >> num;
   }
   return num;
}

//-----------------------------------------------------------
float read_float2(string prompt1, string prompt2)
//-----------------------------------------------------------
{
   cout << prompt1;
   float num;
   while (!(cin >> num))
   {
      cin.clear();
      string skip;
      cin >> skip;
      cout << prompt2;
   }
   return num;
}

//-----------------------------------------------------------
int main()
//-----------------------------------------------------------
{
   int num1 = read_integer1("Enter integer: ");
   cout << "num1=" << num1 << endl;

   float num2 = read_float1("Enter float: ");
   cout << "num2=" << num2 << endl;

   int num3 = read_integer2("Enter integer: ", "Error try again: ");
   cout << "num3=" << num3 << endl;

   float num4 = read_float2("Enter float: ", "Error try again: ");
   cout << "num4=" << num4 << endl;

   return 0;
}