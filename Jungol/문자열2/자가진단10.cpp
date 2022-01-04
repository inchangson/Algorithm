#include <stdio.h>

int main(){
    char ch;
    long long num = 0;
    long long digit = 0;
    while(true){
        ch = getchar();
        if(ch == '.'){
            digit = 1;
        }
        else if('0' <= ch && ch <= '9'){
            if(digit){
                digit *= 10;
                if(digit > 1000){
                    break;
                }
            }
            num = num * 10 + (ch - '0');
        }
        else{
            break;
        }
    }

    printf("%d\n", num / digit);
    printf("%0.2lf\n", (double)num / digit);

    return 0;
}