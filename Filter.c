/**********************************************************************************************************
Low-pass Filter
1. Input the required cut-off frequency between 0 to 1000Hz.
2. Output Filter kernel is stored in the file "filter.dat".
3. The sampling rate is fixed here at 2000Hz but user can vary it according to the need.

**********************************************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14159

int main(){

int M = 101;
int f_cutoff;
int Fs = 2000;
int i;
float sum = 0;
double filter_arr[M];
float f_radians;

FILE *filter;

printf("Enter the cut off frequency between 0 to 1000Hz : ");
scanf("%d", &f_cutoff);

f_radians = (float)f_cutoff/(float)Fs;

filter = fopen("filter.dat","w");
for(i=0;i<M;i++){

  if(i==M/2){
    filter_arr[i] = (double)(2.0*PI*f_radians);
  }
  else{
  filter_arr[i] = (sin((double)(2.0*PI*f_radians*(i-M/2)))/(i-M/2));
  }

  filter_arr[i] = filter_arr[i] * (0.54 - 0.46*cos((double)(2.0*PI*(i/M)*(PI/180))));
}

//Normalizing

for(i = 0;i<M;i++){
  sum = sum+filter_arr[i];
}

for(i=0;i<M;i++){
  filter_arr[i]=filter_arr[i]/sum;

}

for (i=0;i<M;i++){
  printf("array[%d]:%1f\n",i,filter_arr[i]);
  fprintf(filter,"\n%1f",filter_arr[i]);
}
fclose(filter);

return 0;
}
