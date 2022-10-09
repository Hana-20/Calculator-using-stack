#include <bits/stdc++.h>
#include <conio.h>
#include "calc.h"
int main()
{
    int flag;
    string x;
    char key;
    double ans;
    while(true){
    if(kbhit()){
      key = getch();
    if(key=='T'|| key=='t'){
            break;
        }
    }
        cin>>x;
    ans=Evaluate(x,&flag);
    if(!flag){
      cout<<"invalide excepression"<<endl;
    }
   else cout<<ans<<endl;
    }

    return 0;
}
