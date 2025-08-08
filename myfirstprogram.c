#include <stdio.h> // #include is a preprocessor directive that tells the compiler to include the contents of a file before compiling the acual code 
// <stdio.h> is the standard input output header that contains common input/output declarations like printf() 
#include <stdbool.h> // a c header that allows you to declare and process bolean values in a clean & easy way 

#include <string.h> // allows you to use string functions

// this is a comment 
/* This code below prints "Hello, World!" to the screen */
// There are different types of variables in C, such as integers, floats, and strings.
int main() {
    printf("Hello, World!!\n");
    printf("This is my first C program!"); 

    int myNum = 15; 
    float myFloatNum = 5.99;
    char myLetter = 'D'; 

    printf("%d\n", myNum);
    printf("%f\n", myFloatNum);
    printf("%c\n", myLetter);
    printf("My favorite number is: %d\n", myNum); // w/ variable 
    printf("My favorite number is %d and my favorite letter is %c\n", myNum, myLetter); // w/ variable
    printf("My favorite number is: %d\n", 3); // without varibale 
    printf("My favorite letter is: %c\n", 'E'); // without varibale 

    myNum = 20; 
    printf("My favorite number is now: %d\n", myNum); // after changing the variable

    int myOtherNum = 30; 
    myNum = myOtherNum; // assigning the value of myOtherNum to myNum
    printf("My favorite number is now: %d\n", myNum); // after changing the variable again

    int x = 5; 
    int y = 9; 
    int sum = x + y; 
    printf("The sum of %d and %d is: %d\n", x, y, sum); // printing the sum of two variables

    int xxx, yyy, zzz; 
    xxx = yyy = zzz = 309; 
    printf("The value of x, y, and z is: %d, %d, %d\n", xxx, yyy, zzz); // printing the value of multiple variables

    // college student data example
    int studentID = 3967384; 
    char studentGrade = 'A';
    int studentAge = 18; 
    int studentYear = 1; 
    float studentGPA = 3.5; 

    printf("Student ID: %d\n", studentID);
    printf("Student Grade: %c\n", studentGrade);
    printf("Student Age: %d\n", studentAge);
    printf("Student Year: %d\n", studentYear);
    printf("Student GPA: %f\n", studentGPA);

    // int 2 or 4 bytes 
    // float 4 bytes
    // char 1 byte
    // double 8 bytes

    // character # variables w/ ascii values 
    char aaa = 65, bbb = 66, ccc = 67;
    printf("%c\n", aaa);
    printf("%c\n", bbb); 
    printf("%c\n", ccc);

    // double variables 
    double myDoubleNum = 19.999994123; 
    double myDoubleNum2 = 37E4; // 37 x 10^4 
    printf("My double number is: %.10lf\n", myDoubleNum); // printing a double variable use .___ to specify precision
    printf("My second double number is: %lf\n", myDoubleNum2); // printing another double variable

    // 1000 bytes = 1 kilobyte 
    int myInt;
    float myFloat;
    double myDouble;
    char myChar;

    printf("%zu\n", sizeof(myInt));
    printf("%zu\n", sizeof(myFloat));
    printf("%zu\n", sizeof(myDouble));
    printf("%zu\n", sizeof(myChar));

    // varibles with different data types 
    int items = 39; 
    float costPerItem = 2.99; 
    float totalCost = items * costPerItem; 
    char currency = '$';

    printf("Number of items: %d\n", items);
    printf("Cost per item: %c%.2f\n", currency, costPerItem);
    printf("Total cost of %d items is: %c%.2f\n", items, currency, totalCost);

    // type conversion ( there are two types of type conversion IMPLICIT AND EXPLICIT CONVERSIONS)
    int n = 5; 
    int m = 2; 
    int div = n / m; 

    printf("%d\n", div); // outputs 2 

    // IMPLICIT CONVERSION 
    float myFloat2 = 9; 
    int myInt2 = 91.99; 

    printf("%f\n", myFloat2); 
    printf("%d\n", myInt2); 

    // EXPLICIT CONVERSION (Manual)
    int num99 = 78; 
    int num28 = 818; 
    float div182 = (float) num28 / num99; 

    printf("%.7f\n", div182);

    // Video Game Score Example w/ Explicit Conversion 
    int topScore = 1123983; 
    int userScore = 67283; 
    float userScoreEvaluation = (float) userScore / topScore * 100; 

    printf("Score Percentage: %.7f%%\n", userScoreEvaluation); //  %% for percentage sign 

    // const is a keyword that declares a variable as constant, meaning its value cannot be changed after initialization
    const int loNum = 75; 
    
    // + operator adds two values together 
    int dhNum = 1000 + 23; 
    printf("The value of dhNum is: %d\n", dhNum); // prints the value of dhNum

    // there are many other operators in c like, & (modulus or remainder), ++ (increment by 1), -- (decrement by 1 )
    int hdj = 193; 
    hdj += 10; // this is equivalent to hdj = hdj + 10;

    // comparision values 1 ( true ), 0 ( false )
    // logical operators && (and), || (or), ! (not)

    bool isProgrammingFun = true; 
    printf("Is programming fun: %d\n", isProgrammingFun);
    printf("%d", 89 > 2);


    // real life example 
    int myAge = 18; 
    int legalAge = 21; 
    int time = 8; 

    if (myAge >= legalAge) {
        printf("\nOld enough to go to the bar "); 
    }else if (time >= 9 && myAge < legalAge)  {
        printf("\nNot old enough to go to the bar");
    } else (time <= 9 && myAge < legalAge); {
        printf("\nYou can come into the bar but have to be out by 9pm"); 
    }

    // if (condition) { // code here } (if condition if true)

    // short hand if and else statement is the TERNARY OPERATOR 
    char holdingCard = 'Ace';
    (holdingCard = 'Ace') ? printf("\nWe tie, I also have an Ace!") : printf("\nYou lose I have an Ace!");

    // instead of writing many if..else statements, you can use the switch statment 
    int season = 1; 

    switch (season) { 
        case 1: 
            printf("\nIt is Winter!");
            break; 
        case 2: 
            printf("\nIt is Spring!"); 
            break;
        case 3: 
            printf("\nIt is Summer!");
            break;
        case 4: 
            printf("\nIt is Fall!");
            break; 
    }

    // while loop 

    int yourAge = 12;

    while (yourAge <= 18) {
        printf("\n You are %d", yourAge);
        yourAge++;
    }

    // do/while loop (always happens once unlike reg while loop)
    int gad = 20; 

    do { 
        printf("\n%d", gad);
        gad--;
    }
    while (gad > 16);

    // for loop 
    int ba; 

    for (ba = 0; ba < 6; ba++) { 
        printf("\n%d", ba);
    }

    // nested loop 
    int kl, jl; 

    for (kl = 1; kl <= 2; ++kl) { 
        printf("\n Outer: %d", kl);
        for (jl = 1; jl <= 4; ++jl) { 
            printf("\nInner: %d", jl);
        }
    }
    
    // Arrays (same dt)
    int myNumbers[] = {33, 88, 99,};
    printf("\n%d", myNumbers[0]);
    printf("\n%zu", sizeof(myNumbers)); 


    // multidimentional array (matrix)
    int matrix[2][3] = { {3, 8, 8}, {9, 3, 9} }; 
    printf("\n%d", matrix[1][0]);


    // strings 
    char message[] = "Good to see you, "; 
    char mname[] = "Bob"; 

    printf("\n%s %s!", message, mname); 

    // quotes within strings --- double qoutes = \" ---- single qoute = \' --- backslash = double backslash
    char txt[] = "We are \"Aliens,\" from planet X.";
    printf("\n%s", txt);

    // \n = new line 
    // \t = Tab 
    // \0 = Null 

    // string length function 
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("\n%zu", strlen(alphabet));


    // concatination of strings 

    char str100[20] = "Hello ";
    char str200[] = "World!";

    strcat(str100, str200); 
    printf("\n%s", str100);
    printf("\n%zu", sizeof(str100));

    // copy strings 
    char str300[20] = "Hello World!";
    char str400[20]; 

    strcpy(str400, str300);
    printf("\n%s", str400);


    // Compare strings
    
    char str500[] = "Grand";
    char str600[] = "Colosseum";
    char str700[] = "Colosseum";

    printf("\n%d", strcmp(str500, str600));
    printf("\n%d", strcmp(str700, str600));

    // User input 
    int userNum; 

    printf("\nType a num: \n");

    scanf("%d", &userNum);

    printf("\nYour number is: %d", userNum);
    
    // double user input 
    int userNum200; 
    char userChar200; 

    printf("\nType a number AND a character and press eneter: \n");

    scanf("%d %c", &userNum200, &userChar200);

    printf("\n Your number is: %d", userNum200); 
    printf("\n Your character is: %c", userChar200);

    // STRING INPUT FROM USER 
    char firstName[20]; 

    printf("\nEnter your first name here: \n");

    scanf("%s", firstName);

    printf("\n Hello %s", firstName);

    // scanf interprets spaces and other special characters as a termination which is why we use fgets command to get strings that are in sentences 

    char fullName[30];

    printf("\nType your full name here: \n");
    getchar();
    fgets(fullName, sizeof(fullName), stdin);

    printf("Hello %s", fullName);

    // Mem address 
    int myBirthday = 31407; 
    printf("\n%p", &myBirthday);

    // Creating Pointers (pointers are variables that stores the memory address of a variable and its value )
    int* ptr = &myBirthday; // a pointer variable with the name ptr that stores the addres of myBirthday

    // Output the value of myAge (43)
    printf("\n%d\n", myBirthday);

    // Output the memory address of myAge (0x7ffe5367e044)
    printf("%p\n", &myBirthday);

    // Output the memory address of myAge with the pointer (0x7ffe5367e044)
    printf("%p\n", ptr);

    // Dereference: Output the value of myAge with the pointer (43)
    printf("%d\n", *ptr);   

    // POINTERS AND ARRAYS 

    int myArray[4] = {30, 90, 80, 100};
    int i; 

    for (i =0; i < 4; i++) {
        printf("\n%d", myArray[i]);
        printf("\n%p", &myArray[i]);
    }


    return 0; 
    }

