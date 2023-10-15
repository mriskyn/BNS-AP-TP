#include <stdio.h>

struct Employee
{
  char name[50];
  int age;
  float salary;
};

int main()
{
  struct Employee emp1;
  strcpy(emp1.name, "John");
  emp1.age = 30;
  emp1.salary = 50000.0;

  printf("Name: %s\nAge: %d\nSalary: %.2f\n", emp1.name, emp1.age, emp1.salary);
  return 0;
}
