// gcc -fno-stack-protector -no-pie chall.c -o chall
#include <stdio.h>
#include <stdlib.h>

void vuln(){
    char buffer[100];
    puts("Tell me your name and your future shall be revealed!");
    printf("> ");
    gets(buffer);
    puts("Can't read your future >_<");
}

int main(void){
    vuln();
    return 0;
}