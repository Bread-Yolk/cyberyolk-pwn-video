#include <stdio.h>
// gcc -fno-stack-protector -Wl,-z,norelro -no-pie -z execstack chall.c -o chall
int main(void){

    char buffer[48];
    int num = 0;
    puts("BOF me!");
    printf("> ");
    gets(buffer);
    if(num){
        puts("You just overflowed me.");
    }

    return 0;
}