#include <stdio.h>
#include <string.h>
#include "04-02-SC.h"

int main(int argc, char *argv[])
{
  char oneline[80];
  float value1, value2;
  char operator[5] = "";
  int numelements;
  float resultvalue;

  while (fgets(oneline, sizeof(oneline), stdin) != NULL)
  {
    value1 = 0;
    value2 = 0;
    numelements = sscanf(oneline, "%f %4s %f", &value1, operator, &value2);
    if (numelements == 3)
    {
      int error_flag = 0;
      if (strcmp(operator, "+") == 0)
      {
        resultvalue = operation_plus(value1, value2);
      }
      else if (strcmp(operator, "-") == 0)
      {
        resultvalue = operation_minus(value1, value2);
      }
      else if (strcmp(operator, "*") == 0)
      {
        resultvalue = operation_mult(value1, value2);
      }
      else if (strcmp(operator, "/") == 0)
      {
        resultvalue = operation_div(value1, value2);
      }
      else if (strcmp(operator, "abs") == 0)
      {
        resultvalue = operation_absdiff(value1, value2);
      }
      else if (strcmp(operator, "exp") == 0)
      {
        resultvalue = operation_exp(value1, value2);
      }
      else if (strcmp(operator, "log") == 0)
      {
        if (value1 > 0 && value1 != 1 && value2 > 0)
        {
          resultvalue = operation_log(value1, value2);
        }
        else
        {
          printf("Error: Invalid numbers for log calculation (A=%g, B=%g).\n", value1, value2);
          error_flag = 1;
        }
      }
      else
      {
        error_flag = 1;
      }

      if (error_flag == 0)
      {
        printf("%g %s %g = %g\n", value1, operator, value2, resultvalue);
      }
    }
    else
    {
      printf("Missing some elements ... %g, \"%s\", %g\n", value1, operator, value2);
    }
  }

  return 0;
}