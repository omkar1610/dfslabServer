#include <stdio.h>
#include "mean.h"
#include "add.h"

int main() {
  int num1 = 25;
  int num2 = 37; 
  printf("The sum is: %d\n", add(num1,num2));
  printf("The mean is: %d\n", mean(num1,num2));
  return 1;
}
