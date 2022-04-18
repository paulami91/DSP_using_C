/**********************************************************************************************************
SineWave Generator
1. Input the required signal length and the frequency.
2. Output Sine Wave is stored in the file "sine_wv.dat".
3. The sampling rate is fixed here at 2000Hz but user can vary it according to the need.

**********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159

int main(void){

double samplingRate = 2000.0;
double samplingTime = 1/samplingRate;

int i,len,f;
double theta = 0.0;
float _time_inst = 0.0;

FILE *sine_wv;

printf("Enter the length of signal in points : ");
scanf("%d",&len);

printf("Enter the frequency in Hz : ");
scanf("%d",&f);

float time_inst[len];
double sineWave[len];

sine_wv = fopen("sine_wv.dat","w");

for(i=0;i<len;i++){
    time_inst[i] = _time_inst;
    _time_inst += samplingTime;
    }

//Generating Sine Wave
for(i=0; i<len; i++){
    theta = 2.0*PI*(double)f*time_inst[i];
    sineWave[i] = 10.0*(double)sin((double)theta);
    fprintf(sine_wv, "\n%lf", sineWave[i]);
    }

fclose(sine_wv);

return 0;

}

