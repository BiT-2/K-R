#include <stdio.h>

#define STEP 10
#define MAX 300

float temp_F_to_C(float );
float temp_C_to_F(float );

void main()
{
    for( int i = 0; i <= MAX ; i = i + STEP)
    {
        printf("%d Fahrenheit is %3.2f Celsius \n", i, temp_F_to_C(i));
        printf("%d Celsius is %3.2f Farenheit \n", i, temp_C_to_F(i));
    }

}

float temp_F_to_C (float farh)
{
    float celsius;
    celsius = (farh - 32)*(5.0/9.0);
    return celsius;
}

float temp_C_to_F(float celsius)
{
    float fahr;
    fahr = (9.0/5.0)*celsius + 32;
    return fahr;
}