#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

//Main Menu

void TextMenuMain();

//Exercise 1
//


struct node
{
    int value;
    struct node* next;
};

int Exercise1();
int SumNodesUtil(struct node* head);
void SumNodes(struct node* head, int* sum);
void Add(struct node** head_ref, int new_value);

//Exercise 2
//

int Exercise2();
void TextMenuExercise2();
//Exercise A
void TextSolutionExercise2A();
int Exercise2Amain();
void Exercise2AFunc(int a);
//Exercise B
void TextSolutionExercise2B();
int Exercise2Bmain();
void Exercise2BFunc(int* a);
//Exercise C
void TextSolutionExercise2C();
int Exercise2Cmain();
void Exercise2CFunc(int& a);
//Exercise D
void TextSolutionExercise2D();
int Exercise2Dmain();
void Exercise2DFunc(int& a);
//Exercise E
void TextSolutionExercise2E();
int Exercise2Emain();
void Exercise2EFunc(int* a);
//Exercise F
void TextSolutionExercise2F();
int Exercise2Fmain();
void Exercise2FFunc(int* a);
//Exercise G
void TextSolutionExercise2G();
int Exercise2Gmain();
void Exercise2GFunc(int& a);
//Exercise H
void TextSolutionExercise2H();
int Exercise2Hmain();
void Exercise2HFunc(int& a);

//Exercise 3
//

int Exercise3();


//Exercise 4
//

int Exercise4();

//Exercise 5
//

class Utils
{
public:
    bool check(std::string arg);
};
int Exercise5();

//Exercise 6
//

int Exercise6();
int Exercise6Main();
int FindMissing(int values[], int amountTimes);
void FillList(int values[], int amountTimes);
void DeleteRandomNumber(int values[], int amountTimes);
void FillRandomNumber(int values[], int values2[], int amountTimes);
void DisorderList(int values[], int amountTimes);

//Exercise 7
//

void Exercise7();