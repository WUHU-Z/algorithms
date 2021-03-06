/*************************************************************************
    > File Name       : LCM_GCD.cpp
    > Author          : Ther
    > Created Time    : 2021年08月19日 星期四 12时00分42秒
 ************************************************************************/

#include<iostream>

using namespace std;

/****GCD****/
int GCD_division(int a, int b){ 
    int t;
    while( b != 0 ){
        t = b;
        b = a % b;
        a = t;
    }
    
    return a;  
}

int GCD_recursion1(int a, int b){ 
    if(b == 0){
        return a;
    }else{
        return GCD_recursion1(b, a%b);
    }    
}

int GCD_recursion2(int a, int b){
    return b==0?a:GCD_recursion2(b,a%b);
}

int GCD_substitution(int a, int b){ 
    while(a != b){
        if(a > b){
            a = a-b;
        }else{
            b = b-a;
        }
    }
    
    return a;
}

/****LCM****/
int LCM(int a, int b){ 
    return abs(a*b)/GCD_recursion2(a, b);   
}

int main () {
    printf("GCD - a = 22, b = 44 - %d\n", GCD_substitution(22, 44));
    printf("GCD - a = 7 , b = 31 - %d\n", GCD_division(7, 31));
    printf("GCD - a = 18, b = 27 - %d\n", GCD_recursion1(18, 27));
    printf("GCD - a = 18, b = 27 - %d\n", GCD_recursion2(30, 27));
    printf("LCM - a = 12, b = 21 - %d\n", LCM(12, 21));
}
