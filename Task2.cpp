#include<iostream>
using namespace std;
float addition(float x, float y)
{
	return x + y;
}
float subtraction(float x, float y)
{
	return x - y;
}
float multiplication(float x, float y)
{
	return x * y;
}
float division(float x, float y)
{
	return x / y;
}

void main()
{
	int choice;
	do {
		float number1 = 0, number2 = 0;
		
		cout << "For addition Press 1" << endl;
		cout << "For subtraction Press 2" << endl;
		cout << "For Multiplication Press 3" << endl;
		cout << "For Division Press 4" << endl;
		cout << "To Exit Press 0" << endl;
		cout << "Enter the choice: ";
		cin >> choice;
		cout << "Enter the number 1: ";
		cin >> number1;
		cout << "Enter the number 2: ";
		cin >> number2;
		if (choice == 1)
		{
			cout<<"Sum is: "<<addition(number1, number2)<<endl;
		}
		if (choice == 2)
		{
			cout<<"Subtracted Value is: "<<subtraction(number1, number2) << endl;
		}
		if (choice == 3)
		{
			cout<<"Multiplicated value is: "<<multiplication(number1, number2) << endl;
		}
		if (choice == 4)
		{
			cout<<"Divided value is: "<<division(number1, number2) << endl;
		}
		if (choice == 0)
		{
			cout << "Exiting" << endl;
			break;
		}
		if (choice > 4)
		{
			cout << "Invalid choice" << endl;
		}
		cout << "To Enter numbers again press y to exit press n" << endl;
		char a;
		cin >> a;
		
		 if (a = 'n')
		{
			cout << "Exiting";
			break;
		}
		
	
	} while (choice != 0);
}