#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000
#define MAX_LINE_LENGTH2 1000
char Task2Codes [75][4];
int Task2Numbers [75];
char OriginalBase62[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char CustomBase62[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
_Bool Changes[63];

void BuildCustomBase62 (int number, char code[]){
int counter =2;
while (number>0){
int remainder = number%62;
if (Changes[remainder]&& CustomBase62[remainder] != code[counter]){ printf("Faulty assumption  "); }
CustomBase62[remainder] = code[counter];
Changes[remainder] =1;
number =number/62;
counter--;
}
}
// function that used the deduced base62 substitution Cipher to create a code for any number in the int range
void CreateCodeFromNumber (int number){
  printf("Number: %d  Code: ",number);  
  if (number==0){printf("%c \n",CustomBase62[0]); return;}
  if (number<0){printf("-"); number =0-number;}
char outputBuffer[100];
int counter= 99;
while (number>0){
int remainder = number % 62;
outputBuffer[counter] = CustomBase62[remainder];
number =number/62;
counter--;
}
for(int i=counter+1;i<100;i++){
printf("%c", outputBuffer[i]);
}
printf(" \n");
}
// function that calls the function deducing the base62 cipher for each number code pair 
void CallBuildCustomBase62(){
    for(int i=0;i<75;i++){
    char code[4];
    for (int j=0;j<3;j++){
        code[j] = Task2Codes[i][j];
    }
 BuildCustomBase62 (Task2Numbers[i], code);

    }

}
// function that checks if there is any charcter that could not be deduced from the given number code pairs
void CheckIfMissingaChange(){
for (int i=0;i<62;i++){
    if (Changes[i]!=1){ printf("%d Missing a change at %c: Not enough data to completely guess Cipher \n",i,CustomBase62[i]);}

}
CustomBase62[21]='5';
}

// function for task 1  to calculate the largest square in a rectangle
void Task1LargestSquaresInRectangle(int N, int M)
{  if(N==0 || M==0){printf("One or more side is zero so no positive area possible \n");return;} 
   if(N<0 || M<0){printf("One or more side is negative so no positive area possible \n");return;}  
   if (N==M){ printf("%d%c%d\n",N,'X',N); return;}
   else if (N<M){ printf("%d%c%d, ",N,'X',N); M=M-N;}
   else{ printf("%d%c%d, ",M,'X',M); N=N-M; }
   Task1LargestSquaresInRectangle(N,M);
}
// loading the numbers from a text file and storing it in an array
int Task2GetNumbersFromFile()
{    
  FILE    *textfile;
  char    line[MAX_LINE_LENGTH];
  textfile = fopen("ResourceNumbers.txt", "r");
    if(textfile == NULL)
        return 1;
     
    int NumberOfLines=0;
    while(fgets(line, MAX_LINE_LENGTH, textfile)){
        Task2Numbers[NumberOfLines] = atoi(line);
      
        NumberOfLines++;
    }
     printf("\n");
    fclose(textfile);

}
 // loading the codes from a test file and storing it
int Task2GetCodesFromFile()
{    
  FILE    *textfile;
  char   line[MAX_LINE_LENGTH2];
  textfile = fopen("ResourceCodes.txt", "r");
    if(textfile == NULL)
        return 1;
     
    int NumberOfLines=0;
    while(fgets(line, MAX_LINE_LENGTH2, textfile)){
        
        for (int i=0;i<4;i++){
        Task2Codes[NumberOfLines][i]= line[i];
        }
      
        NumberOfLines++;
    }
     printf("\n");
    fclose(textfile);

}
// function to print the stored numbers and codes to validate them
void PrintNumbersandCodes(){
for (int i=0;i<75;i++){
   printf("%d",Task2Numbers[i]);
   printf("  %c%c%c\n",Task2Codes[i][0],Task2Codes[i][1],Task2Codes[i][2]); 
}

}

int main(int argc, char **argv)
{
printf("\n ************************************************************************************ \n");
printf("Testing the function for Task1 : Largest Squares in a rectangle with different inputs\n");    
printf("For a rectangle that is 6X5 the answer is :\n");    
Task1LargestSquaresInRectangle(6,5);  
printf("For a Square that is 1X1 the answer is :\n");    
Task1LargestSquaresInRectangle(1,1); 
printf("For a Square that is 9X9 the answer is:\n");    
Task1LargestSquaresInRectangle(9,9);     
printf("For a rectangle that is 12X7 the answer is:\n");    
Task1LargestSquaresInRectangle(12,7); 
printf("For a rectangle that is 302X415 the answer is:\n");    
Task1LargestSquaresInRectangle(302,415);  
printf("\n ************************************************************************************ \n");
printf("Loading the numbers and Codes from the files\n");          
Task2GetNumbersFromFile();
Task2GetCodesFromFile();        
//PrintNumbersandCodes();
printf("Deducing the Base62 Substitution Cipher\n");
CallBuildCustomBase62();
CheckIfMissingaChange();
printf("L at position 21 is substituted with 5 to make the Cipher valid and avoid collisions\n");       
printf("Original Cipher: %s\n", OriginalBase62);
printf("New Cipher after substituting L: %s\n", CustomBase62);
printf("Testing the code generation function with different inputs\n");    
   CreateCodeFromNumber(15840);
   CreateCodeFromNumber(50129);
   CreateCodeFromNumber(17941);
   CreateCodeFromNumber(49639);
   CreateCodeFromNumber(30001);
   CreateCodeFromNumber(55555);
   CreateCodeFromNumber(77788);
   CreateCodeFromNumber(20);
   CreateCodeFromNumber(0);
   CreateCodeFromNumber(-15840);
   
   while(1){
    printf("\n ************************************************************************************ \n");
    printf("please enter 1 : to Test the Largest Squares in a rectange function \n or enter 2 : To test the Code Generation function \n or enter anything else to exit \n ");
   char strvar[10];
   fgets (strvar, 10, stdin);
   int Selectfunction = atoi(strvar);
   if (Selectfunction==1){
    printf("please enter a numeric value for the first side of the rectangle N:");
    char Nchars[10];
   fgets (Nchars, 10, stdin);
    int N = atoi(Nchars);
    printf("please enter a numeric value for the second side of the rectangle M:");
    char Mchars[10];
   fgets (Mchars, 10, stdin);
    int M = atoi(Mchars);
    Task1LargestSquaresInRectangle(N,M);
   }
   else if(Selectfunction==2){
   printf("please enter a numeric value for the number you want to generate a code for:");
   char Numberchars[10];
   fgets (Numberchars, 10, stdin);
    int Number = atoi(Numberchars);
     CreateCodeFromNumber(Number);
   }
   else{ return 0;}
   }
    return 0;       
}


