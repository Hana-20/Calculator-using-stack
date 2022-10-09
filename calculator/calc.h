#include<bits/stdc++.h>
using namespace std;
extern map<char ,double(*)(double, double)> operations;
extern map <char,int> oper;
double add(double a,double b);
double subtract(double a,double b);
double divition(double a,double b);
double multiply(double a,double b);
int prec(char c);
bool isOper(char c);
bool isNum(char c);
double doOpertion(double a,char b,double c);
double Evaluate(string x,int *flag);
