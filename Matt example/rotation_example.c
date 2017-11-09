//C code that simulates random rotation of a point about the origin
//written by Matt Bovyn 2016
//mbovyn@uci.edu

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "twister.c"

//initialize variables
#define pi 3.14159265359

double v[3]; //rotation vector
double rand1, rand2, randn1, randn2; //random numbers
double q[4]; //quaternion
double newq[4]; //updated quaternion
double p0[3]; //initial point
double p[3]; //rotated point

int i, j;
int steps=10; //number of times to rotate

#include "quaternion_formulae.c"
void generate_rand_normal();

int main()
{
    //necessary step for twister number generator to work
    RanInit(0);

    //intialize value of quaternion to the identity quaternion
    q[0]=1;
    q[1]=0;
    q[2]=0;
    q[3]=0;

    //set initial point
    p0[0]=1;
    p0[1]=0;
    p0[2]=0;
    printf("step x        y        z        length\n%d %f %f %f\n",0,p0[0],p0[1],p0[2]);

    //for each new rotation
    for(i=0;i<steps;i++){

        //create rotation vector
        generate_rand_normal();
        v[0]=randn1;
        v[1]=randn2;
        generate_rand_normal();
        v[2]=randn1;

        //convert to quaternion and compose with existing rotation
        compose_rotations();

        for(j=0;j<4;j++){
            q[j]=newq[j];
        }

        //if we want to output, rotate the initial point by the current quaternion
        if(i%1==0){
            rotate_point();
            printf("%d %f %f %f %f\n",i+1,p[0],p[1],p[2],sqrt(pow(p[0],2) + pow(p[1],2) + pow(p[2],2)));
        }

    }
}

void generate_rand_normal(){
    //generate random normal number by Box-Muller transform

    //start with 2 uniform(0,1) random numbers
    rand1=genrand_real3();
    rand2=genrand_real3();
    //tranform to normally distributed
    randn1=sqrt(-2*log(rand1))*cos(2*pi*rand2);
    randn2=sqrt(-2*log(rand1))*sin(2*pi*rand2);
}
