#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// gcc -fno-stack-protector -Wl,-z,norelro -no-pie -z execstack chall.c -o chall

void get_shell(){
    puts("How did you get in here?!");
    system("/bin/sh");
}

void vuln(){
    char name[100];
    puts("Hello, can you tell me your name?");
    printf("> ");
    scanf("%s", name);
    printf("Hi %s!\n", name);
}

int main(void){
    vuln();

    return 0;
}