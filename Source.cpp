#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
	char name[256]; //primative datatype required for binary file writing
	int id;
	float weeklyHours;
	float rateOfPay;
} Employee;

Employee employee[20];
float GrossSalary(float , float);

/*void struct_putback(std::vector<Employee>& employee)
{
	Employee employee;
	cin.getline(employee.name[256], sizeof(employee);
	getline(cin, employee.id);
	getline(cin, employee.weeklyHours);
	getline(cin, employee.rateOfPay);
	employee.push_back(Employee);
}*/
//float GrossSalary(float x, float y);

int main()
{
	fstream project3File("project3.txt", ios::binary | ios::out | ios::in); //open and truncate for writing

	const int N = 2; // set number of employees for testing

	Employee employee[20]; // max number of employees
	
	project3File.open("project3.txt", ios::out | ios::app); // checks if file is functional then ouptut a message if true

	if (project3File)
	{
		cout << "file is open\n";
		project3File.write(reinterpret_cast<char*>(&employee), sizeof(employee));
	}
	else
		cout << "error";

	for (int i = 0; i < N; i++) // iterate over file N times and writes to i a max of 20 times
		{
			cout << "Please enter a name:\n";
			cin.get(employee[i].name, 256);
			cout << "Please enter the employee ID:\n";
			cin >> employee[i].id;
			cout << "Please enter the weekly hours:\n";
			cin >> employee[i].weeklyHours;
			cout << "Please enter the rate of pay:\n";
			cin >> employee[i].rateOfPay;

			float grossSalary = GrossSalary(employee[i].rateOfPay, employee[i].weeklyHours);
			
			if (grossSalary > 2500)
			{
				float tax = (grossSalary * .33);
				std::cout << "\nGross Salary: " << grossSalary << std::endl;
				std::cout << "\nTax: " << tax << std::endl << std::endl;
				float netSalary = grossSalary - tax;
				std::cout << "Net Salary: " << netSalary << std::endl << std::endl;

			}
			else {
				float tax = (grossSalary * .24);
				std::cout << "\nGross Salary: " << grossSalary << std::endl;
				std::cout << "Tax: " << tax << std::endl << std::endl;
				float netSalary = grossSalary - tax;
				std::cout << "Net Salary: " << netSalary << std::endl << std::endl;
			}
		project3File.close();
		}

		project3File.read(reinterpret_cast<char*>(&employee), sizeof(employee)); //reads all the input above
		for (int i = 0; i < N; i++)
		{
			cout << employee[i].name << endl;
			cout << employee[i].id << endl;
			cout << employee[i].weeklyHours << endl;
			cout << employee[i].rateOfPay << endl;
		}
		project3File.close();
	








	return 0;
}

float GrossSalary(float x, float y)
{
	float r = x * y;
	return r;
	//std::cout << grossSalary;
};
	
	/*float weeklyHours, rateOfPay;
		std::fstream project3_file("project3.txt");
		const int SIZE = 20;

		Employee employee[SIZE]{
			"Jerry",
			   5656,
			     50,
		 	     12
		};
		
		project3_file.open("project3.txt", std::ios::out | std::ios::binary);

		if (project3_file.fail())
		{
			std::cout << "Error" << std::endl;
		}
		else
		{
			project3_file.write(reinterpret_cast<char*>(&employee), sizeof(Employee));

			project3_file.close();
		}
		std::cout << "Weekly Hours: ";
		std::cin >> weeklyHours;

		std::cout << "Rate of Pay: ";
		std::cin >> rateOfPay;

		float grossSalary = GrossSalary(rateOfPay, weeklyHours);

		if (grossSalary > 2500)
		{
			float tax = (grossSalary * .33);
			std::cout << "\nGross Salary: " << grossSalary << std::endl;
			std::cout << "\nTax: " << tax << std::endl << std::endl;
			float netSalary = grossSalary - tax;
			std::cout << "Net Salary: " << netSalary << std::endl << std::endl;
			
		}
		else {
			float tax = (grossSalary * .24);
			std::cout << "\nGross Salary: " << grossSalary << std::endl;
			std::cout << "Tax: " << tax << std::endl << std::endl;
			float netSalary = grossSalary - tax;
			std::cout << "Net Salary: " << netSalary << std::endl << std::endl;
		}
		
		
		system("pause>0");
	}

	float GrossSalary(float x, float y)
	{
		float r = x * y;
		return r;
		//std::cout << grossSalary;
	};
	*/
	