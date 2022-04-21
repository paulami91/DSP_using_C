/**********************************************************************************************************
Convolution
1. Here, the sequence_1 is of length 4, the sequence_2 is of length 5.
2. Input integer values for sequence_1 and sequence_2.
3. Output is the convolution of these two sequences.
**********************************************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){

int seq_1[4], seq_2[5], y[8], z[12], rev_seq_2[5];
int i =0, j=0,k=0;

printf("Enter the number of points of the signal");
for(i=0; i<4; i++){
scanf("%d", &seq_1[i]);
}

printf("Enter the number of points of the filter");
for(j=0; j<5; j++){
scanf("%d", &seq_2[j]);
}

// Zero padding

for (i=0;i<12;i++){
  if(i<4 || i>7){
  z[i] = 0;
  }
  else{
  z[i] = seq_1[i-4];
  }
  }

//  Reversal of the sequence_2

for(j=4; j>=0; j--){
  rev_seq_2[(j-4)*-1] = seq_2[j];

  }

 // Convolution

for(i=0; i<8; i++){
    y[i] =0;
  for(j=0;j<5;j++)
  {
    y[i]= y[i]+(z[i+j]*rev_seq_2[j]);
  }
}

for(i=0;i<8;i++){
    printf("Values y[%d]=%d\n", i,y[i]);
}

}
