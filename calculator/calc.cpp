#include "calc.h"
using namespace std;
map<char,int> oper={{'*',3},{'-',2},{'/',3},{'(',0},{')',0},{'+',1}};
map<char ,double(*)(double, double)> operations{{'*',multiply},{'-',subtract},{'/',divition},{'+',add}};
double add(double a,double b){
    return a+b;
}
double subtract(double a,double b){
    return a-b;
}
double divition(double a,double b){
    return a/b;
}
double multiply(double a,double b){
    return a*b;
}
bool isOper(char c){
        if(oper.find(c)!=oper.end()){
            return true;
        }
    return false;

}
bool isNum(char c){
    return (c>='0'&&c<='9');
}
double doOpertion(double a,char b,double c){
   return operations[b](a,c);
}
int prec(char c){
    return oper[c];
}
double Evaluate(string x,int *flag){
 int i=0,neg=1;
 double prev,num=0;
 *flag=1;
 string str="0";
 stack <double>s_num;
 stack <char>s_oper;
 while(i<x.size()){
    str="0";
    num=0;
    while(!isOper(x[i])){
    str+=x[i];
    i++;
    }
    num+=stod(str);
    if(isOper(x[i])){
            if(isOper(x[i-1])){
       if(prec(x[i])&&i==0&&x[i]!='-'){
                *flag=0;
                 break;
    }
            }
    switch (x[i]){
    case '(':
           if(i>0&&isNum(x[i-1])){
            *flag=0;
            break;
           }
        s_oper.push(x[i]);
        break;
    case ')':
        *flag=0;
        while(!s_oper.empty()&&s_oper.top()!='('&&!s_num.empty()){
                *flag=1;
            num=doOpertion(s_num.top(),s_oper.top(),num*neg);
            neg=1;
             s_num.pop();
             s_oper.pop();
        }
        if(s_oper.empty()||s_oper.top()!='('){
          *flag=0;
          break;
           }
           s_oper.pop();
           break;
     case '-':
        if(neg==-1){
            *flag=0;
            break;
        }
        if(i==0||isOper(x[i-1])){
            neg=-1;
            i++;
            continue;
        }

    default:
        if(!s_oper.empty()){
        if(prec(s_oper.top())>prec(x[i])){
          if(s_num.empty()){
            *flag=0;
            break;
          }
           num=doOpertion(s_num.top(),s_oper.top(),num*neg);
           neg=1;
           s_oper.pop();
           s_num.pop();
        }
        }
        s_oper.push(x[i]);
        s_num.push(num*neg);
        neg=1;
        num=0;
    }
 }
 i++;
}
num*=neg;
while(!s_oper.empty()&&!s_num.empty()){
            num=doOpertion(s_num.top(),s_oper.top(),num);
            s_num.pop();
            s_oper.pop();
        }

if((!s_oper.empty())||(!s_num.empty())){
   *flag=0;
}

return num;
}
