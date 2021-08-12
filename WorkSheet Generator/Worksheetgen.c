/*
Wroksheet Generator 
Goals
Multiples Worksheets 

0 - 12 Random Sets and answer Key seperate file 
60 Questions
"Multiplication Minute"

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<string.h>

#define MAX 12
#define Questions 60
#define Spaces 30

typedef struct Answers{
    int QuestionA;
    int QuestionB;
    int Answer;
}Answers;


Answers QuestionGen(int Max);


void main(char c, char* v[]){
    FILE *WorkSheet;
    FILE *AnswerSheet;
    int EnteredDigits = (int)c - 1;
    //printf("%d",EnteredDigit);
    WorkSheet = fopen("Worksheet.txt","w");
    AnswerSheet = fopen("AnswerSheet.txt","w");
    srand (time(NULL)+getpid());//Seed Rand
    Answers Assemble;
    for (int i = Questions; i>0; i--){
        Assemble = QuestionGen(MAX);
        if ( i % 2 == 0){
            fprintf(WorkSheet,"%02d * %02d =____",Assemble.QuestionA,Assemble.QuestionB);
            for (int Spaceman = Spaces; Spaceman > 0; Spaceman--)
                fprintf(WorkSheet," ");
            fprintf(AnswerSheet,"%02d * %02d = %02d",Assemble.QuestionA,Assemble.QuestionB,Assemble.Answer);
            int SpaceMod = Spaces;
            if (Assemble.Answer > 99) SpaceMod = Spaces -1; // handle 3 digits on space distrubution
            for (int Spaceman = SpaceMod; Spaceman > 0; Spaceman--) fprintf(AnswerSheet," ");
        }
        else{
            fprintf(WorkSheet,"%02d * %02d =____\n",Assemble.QuestionA,Assemble.QuestionB);
            fprintf(AnswerSheet,"%02d * %02d = %02d\n",Assemble.QuestionA,Assemble.QuestionB,Assemble.Answer);
        }
    }
    fclose(WorkSheet);
    fclose(AnswerSheet);
}   

Answers QuestionGen(int Max){
    /*
                                    *TODO*
      Add if condition for MAX, only us Defined if none given by charv Parser    
    */
    Answers Accum;
    Accum.QuestionA = rand() % MAX;
    Accum.QuestionB = rand() % MAX;
    Accum.Answer = Accum.QuestionA * Accum.QuestionB;
    return Accum;
}
