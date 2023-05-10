#include <stdio.h>
#include <math.h>


int main(void)
{
  double base, power, result;
  char c;

  for(;;){  
    printf("\nEnter the letter 'e' to end the program: \n");  
    printf("Enter x to reveal the secret option: \n");  
    printf("Enter a number from 0 to 5: \n");  
    scanf(" %c",&c);
    switch (c) {
    case '0': 
      printf("Introduced: 0\n");
      break;
    case '1':
      printf("Introduced: 1\n");
      break;
    case '2':
      printf("Introduced: 2 (no break) \n");
    case '3':
      printf("Introduced: 3\n");
      break;
    case '4':
      printf("Introduced: 4\n");
    	break;
    case '5':
      printf("Introduced: 5\n");
      break;
    case 'x':
      printf("Enter the number to be raised to a power\n");
      scanf("%lf",&base);
      printf("Enter power\n");
      scanf("%lf",&power);
      result = pow(base, power);
      printf("result: %lf,it was to power: %lf\n", result, power);
      break;
    case 'e':
       return 0;
    default:
      printf("Entered: a character outside the range 0-5\n");
      break;
    }
  }

}