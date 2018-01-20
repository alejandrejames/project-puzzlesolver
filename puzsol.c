#include<stdio.h>
#include<stdlib.h>
int intstate[4][4];
int glstate[4][4];
void inputassigner(FILE *inpint,int array[4][4]);

main(){
       /*Inputs Start*/
       printf("This Program solves a 4x4 puzzle\n\n");
       
       FILE *inpint;
       FILE *inpgl;
       
       //Initial State
       inpint=fopen("initialstate.txt","r");
	   if(inpint==NULL){
   	                  printf("Error opening file\n");
                      return 1;
       }
       inputassigner(inpint,(int *)intstate);
       
       //Goal State
       inpgl=fopen("goalstate.txt","r");
	   if(inpgl==NULL){
   	                  printf("Error opening file\n");
                      return 1;
       }
       inputassigner(inpgl,(int *)intstate);
       /*Inputs End*/
       
       
       /*Main Program Start*/
       
       /*Main Program End*/

//Close Files      
fclose(inpint);
fclose(inpgl);
system("pause");//Used for windows systems only(delete if you are using a different OS)
}

//Function to assign the initial state and the goal state
void inputassigner(FILE *inpint,int array[4][4]){
     int a1=0,a2=0,temp;
     while(fscanf(inpint,"%i",&temp)==1){
             if(a2==4){
               a1++;
               a2=0;
               printf("\n");
               array[a1][a2] = temp;
               printf("%3i",array[a1][a2]);
               a2++;        
             }
             else{
                 array[a1][a2] = temp;
                 printf("%3i",array[a1][a2]);
                 a2++; 
             }                              
       }
       printf("\n\n");
}
