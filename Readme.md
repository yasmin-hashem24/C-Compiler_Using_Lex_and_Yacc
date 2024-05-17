# Contributors

- Yasmin Hashem Niazy
- Rofayda Bassem
- Mahinour Alaaeldin Elsarky
- Salma Ahmed Mahfouz

## Usage Example

```c
 bison --yacc -d Compiler.y
 lex Compiler.l
 cc lex.yy.c y.tab.c SymbolTable/symbolEntry.c SymbolTable/symbolTable.c Errors/error.c node.c -o bas.exe
 ./bas.exe input.txt
```

## Example of Error Handling in Semantic check
### Type Mismatch:
- For Variables

```c
int x = 1;
char y= 'c';
int z = x + y;
 // At line 3, Error: Type mismatch.
```
- For Function Return
```c
char HelloChar(int x, string y, char c) {

    x = x + 1;
    return x;
// At line 3, Error: Type mismatch. Return type does not match function declaration
}
```
- For Function Assignment
```c
char HelloChar(int x, string y, char c) {
    return c;
}

int x = HelloChar(1, "hello", 'c');
// At line 5, Error: Type mismatch
``` 
- For Function Argument Count
```c
char HelloChar(int x, string y, char c) {
    return c;
}

int x = HelloChar(1, 'c'); 
//At line 5, Error: Argument count does not match the function declaration
//At line 5, Error: Type mismatch
```
- For Function Argument Types:
```c
char HelloChar(int x, string y, char c) {
    return c;
}
string s = "Welcome to lex";
int x = HelloChar(s, 'c', 1);
//At line 5, Error: Function argument: type mismatch
```


### Declaration and Initialization

- Use of undeclare variable
```c
int y = 1;
int x = 1 + 3 + y;
int z = k;
//At line 3, Error: There is no such variable/function existing, Variable in expression is not variable/function
```

- Use of uninitialized variable
```c
int y = 1;
int x = 1 + 3 + y;
int k;
int z = k;
//At line 4, Error: Variable has not been initialized before
```
- Use of undefined function
```c
char c = 'a'+'b';
if(1){
    int x = func1(1,2);
}
//At line 3, Error: Function name not declared
//At line 3, Error: There is no such variable/function existing, Variable in expression is not variable/function
```

- Use of undefined enumarator in enum
```c
int x=5;

enum hello{ 
B =x
};

enum hello helloEntry = A;
// At line 9, Error: There is no such enumerator existing in the Enum
```

- Use of undefined enum
```c
int x=5;

enum hello{ 
B =x
};



enum bla helloEntry = B;
// At line 9, Error: No such enum exists. Enum has not been declared before
```

- Use of undeclared varibale in assigning enumarator
```c
enum hello{ 
B =x
};
//At line 5, Error: Variable not declared before
```
- Use of non constant in assigning enumarator
```c
enum hello{ 
B = 5.5
};

//At line 5, Error: Variable is not an integer constant
```
- Passing uninitialized variable to a func
```c
char HelloChar(int x, string y, char c) {
    return c;
}
string s;
int x = HelloChar(1, s, '1');

//At line 5, Error: Variable passed to the function has not been initialized before
```

### Redeclaring varibales, functions and enum in the same scope
- Enum
```c
int x=5;

enum hello{ 
B =x
};



enum hello helloEntry = B;
enum hello helloEntry = B;


//At line 10, Error: Variable has been declared before in same scope
```
- Variable
```c
string roufy = "AA333333";
if(roufy) {
    int x = 1;
    for (int i = 0; i < 3; i=i+1){
        int x = 4;
        int i;
    }
}

//At line 6, Error: Variable already declared in this scope
```
- Function
```c
void fib(int a){
    print("I'm fibooooo");
}

void fib(float i){
    print("I'm another fibooo");
}

//At line 7, Error: Function name already declared
```


## Example of Syntax Error
### Wrong Assignments and Declarations

```c
int x
in x;
int x=;
int 1hj;
string x = "ajs;
enum days {m, t w}
enum days {}
days today = m; //enum assignment should have enum at the start
```

### Wrong Function Calls and Definitions

```c
x = sum(x,);
x = sum(sum(x,7);
sum(y,1)
```
```c
void noReturn() {
    print("no return");
    retun z
}
```
```c
void wrongArguments(x){
    print("missing type in arg");
}
```
```c
int noReturn() {
    print("missing return");
}
```

### Wrong Loops

```c
for (int x = 0 x < 10; x = x +1){
    c=1;
}
```
```c
for int x = 0 x < 10; x = x +1){
    c=1;
}
```
```c
while(z) 
    print("missing brackets");
}
```
```c
while(int z) {
    print("wrong expression");
}
```
```c
do {
    print("missing semicolumns next the while");
} while(z<10)
```

### Wrong Conditions

```c
if(x<0){
    x=1;
}
else {

//this is the right else if
if(x<0){
    x=1;
} else {if (x==1) {
    x = 9;
}}
```
```c
if(x<0){
    x=1;
} else if (x==1) {
    print("wrong else if")
}
```

### Wrong Switch Cases

```c
switch(x=1){
    case 1: 
    print("this is case 1 wrong expression in the switch");
    break;
    default:
    print("this is default");
    break;
}
```
```c
switch(x){
    case 1: 
    print("this is case 1 missng break");
    default:
    print("this is default");
    break;
}
```
```c
switch(x){
    case 1: 
    print("this is case 1 missing default");
    break;
}
```

## Warnings example for variables, enum and function declared but never used
```c
int x =1;

float y;

int f(){
  int z = 1;
  return 1;
}

//Warning: x at line 1 is declared but never used
//Warning: y at line 3 is declared but never used
//Warning: f at line 8 is declared but never used
//Warning: z at line 6 is declared but never used
```

## Symbol Table Example
````markdown

````

