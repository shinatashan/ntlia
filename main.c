#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const float pi=3.14159;

float decriment (float  b, float c, float k);
float dobrotnost (float decr);

int main()
{

    printf (" LABA 3.2.5 \n \n");
    printf (" Data is in the file 'laba.txt' \n");
    printf (" Results is in the file 'results.txt' \n");

    float i = 0, Un = 0, Unk = 0, k = 0, decr = 0, dobr = 0 ;

    FILE* f1 = fopen("lab.txt", "r");
    fscanf(f1, "%f", &Un);
    if (Un == NULL)
        printf("the file is empty\n");
    if(errno)
    {
      printf("file does not exist(");
      exit(1);
    }

    fclose(f1);


    fopen("laba.txt", "r");
    FILE* f2 = fopen("results.txt", "w");


    fprintf(f2,"decriment   dobrotnost\n");

    while (Un != EOF)
    {
        fscanf(f1, "%f %f %f", &Un, &Unk, &k);
        decr = decriment(Un, Unk, k);
        dobr = dobrotnost (decr);
        fprintf(f2,"%f   %f\n", decr, dobr);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
float decriment (float  b, float c, float k)
{
  float a = 0;

  if((k == 0) || (c == 0))
    printf("Error in decr!\n");

  a = (1/k) * log(b/c);
  return a;
}

float dobrotnost (float decr)
{
  float a=0;

  if(decr == 0)
    printf("Error in dobr!\n");

  a = pi/decr;
  return a;
}
