## GCD and LCM Euclid's Algorithm

### Template

This is the template for LCM and GCD

```c++
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
```

## Long Arithmetic (Multi, Sum, Div, Sub)

### Template

[C version click here](https://github.com/28251536/algorithms/tree/master/NumberTheory/source/LongArithmetic.c)

[C++ version click here](https://github.com/28251536/algorithms/tree/master/NumberTheory/source/LongArithmetic.cpp)

