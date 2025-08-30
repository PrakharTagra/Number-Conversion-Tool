#include<stdio.h>
#include<string.h>
#include<math.h>
int numstack[100];
int MAXSIZE = 100;
int top = -1;

int isfull(){
    if(top==MAXSIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(!isfull()){
        top=top+1;
        numstack[top]=data;
    }
    else{
        printf("\nSTACK IS FULL....NO OTHER ELEMENTS CAN BE ADDED!!!");
    }
}

int pop(){
    if(!isempty()){
        int data;
        data = numstack[top];
        top = top-1;
        return data;
    }
    else{
        printf("\nSTACK IS EMPTY..");
        return 0;
    }
}

void numberConversion1(int number, int base){
    while(number!=0){
        push(number%base);
        number=number/base;
    }
}

void numberConversion2(char number[100], int base){
    int value,i=0,j;
    for(j=strlen(number)-1;j>=0;j--){
        if(number[j]>='0' && number[j]<='9'){
            value = number[j]-'0';
        }
        else if(number[j]>='A' && number[j]<='F'){
            value = number[j]-'A'+10;
        }
        else if(number[j]>='a' && number[j]<='f'){
            value = number[j]-'a'+10;
        }
        else{
            printf("\nInvalid Input!!");
            return;
            }
        push(value*pow(base,i));
        i++;
    }
}

int main(){
        int base,choice,number,digit=0,i;
        char strnum[100];
        while(1){
        top=-1;
        printf("\n**********MENU CARD**********\n");
        for(i=0;i<=50;i++){
            printf("*");
        }
        printf("\nChoose The Required Option From Following: ");
        printf("\n1. Decimal To Binary: ");
        printf("\n2. Decimal To Octal: ");
        printf("\n3. Decimal To HexaDecimal: ");
        printf("\n4. Binary To Decimal: ");
        printf("\n5. Octal To Decimal: ");
        printf("\n6. HexaDecimal To Decimal: ");
        printf("\n0. Exit the Code");
        printf("\n");
        for(i=0;i<=50;i++){
            printf("*");
        }
        printf("\n");
        printf("\n");
        for(i=0;i<=50;i++){
            printf("*");
        }
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        printf("\n");
        for(i=0;i<=50;i++){
            printf("*");
        }
        if(choice == 0){
            printf("\nExiting the Program... GoodBye!!");
            break;
        }
        switch(choice){
            case 1:
            printf("\nEnter Decimal Number: ");
            scanf("%d",&number);
            numberConversion1(number,base=2);
            printf("\nConverted Answer in Binary: ");
            digit=0;
            while(!isempty()){
                digit = pop();
                if(digit>=10){
                    digit = 'A'+(digit-10);
                    printf("%c",digit);
                }
                else{
                    printf("%d",digit);
                }
            }
            break;
            case 2:
            printf("\nEnter Decimal Number: ");
            scanf("%d",&number);
            numberConversion1(number,base=8);
            printf("\nConverted Answer in Octal: ");
            digit=0;
            while(!isempty()){
                digit = pop();
                if(digit>=10){
                    digit = 'A'+(digit-10);
                    printf("%c",digit);
                }
                else{
                    printf("%d",digit);
                }
            }
            break;
            case 3:
            printf("\nEnter Decimal Number: ");
            scanf("%d",&number);
            numberConversion1(number,base=16);
            printf("\nConverted Answer in HexaDecimal: ");
            digit=0;
            while(!isempty()){
                digit = pop();
                if(digit>=10){
                    digit = 'A'+(digit-10);
                    printf("%c",digit);
                }
                else{
                    printf("%d",digit);
                }
            }
            break;
            case 4:
            printf("\nEnter Binary Number: ");
            scanf("%s",strnum);
            numberConversion2(strnum,base=2);
            printf("\nConverted Answer in Decimal: ");
            digit=0;
            while(!isempty()){
                digit = digit + pop();
            }
                printf("%d",digit);
            break;
            case 5:
            printf("\nEnter Octal Number: ");
            scanf("%s",strnum);
            numberConversion2(strnum,base=8);
            printf("\nConverted Answer in Decimal: ");
            digit=0;
            while(!isempty()){
                digit = digit + pop();
            }
                printf("%d",digit);
            break;
            case 6:
            printf("\nEnter Hexadecimal Number: ");
            scanf("%s",strnum);
            numberConversion2(strnum,base=16);
            printf("\nConverted Answer in Decimal: ");
            digit=0;
            while(!isempty()){
                digit = digit + pop();
            }
                printf("%d",digit);
            break;
            default:
            printf("\n**NO SUCH CHOICE FOUND**");
        }
    }
}