#include <iostream>

using namespace std;

int main()
{
  int a, b;
  int sum = 0;

  cout << "Enter two numbers: " << endl;

  cin >> a >> b;
  sum = a + b;

  cout << "The sum of two numbers is: " << sum << endl;

  if (sum < 5)
  {
    for (int i = 0; sum <= 10; i++)
    {
      cout << "Happy Coding " << sum++ << endl;
    }
  }

  else
  {
    cout << "Please enter the numbers in range!" << endl;
  }

  cout << "Happy Coding!" << endl;

  return 0;
}