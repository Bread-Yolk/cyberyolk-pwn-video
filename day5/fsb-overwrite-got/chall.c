#include <stdio.h>
#include <stdlib.h>
// gcc -fno-stack-protector -no-pie -z execstack -Wl,-z,norelro chall.c -o chall

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void helper(){
    system("/bin/sh");
}

void vuln(){
    while(1){
        char input[160];
        puts("Can you break out of the loop?");
        puts("Try to identify the vuln and tweak with it.");
        printf(">> ");
        fgets(input, sizeof(input), stdin);
        printf(input);
    }
}

int main(void){
    init();
    vuln();
    return 0;
}
