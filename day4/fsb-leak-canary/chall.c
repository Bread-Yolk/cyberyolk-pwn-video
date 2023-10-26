#include <stdio.h>
#include <stdlib.h>
// gcc -no-pie chall.c -o chall

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void get_shell(){
    puts("[+] SHELL SPAWNED!");
    system("/bin/sh");
}

void vuln(){
    char buffer[50];
    puts("Nice move you just bypass PIE protection before, this time I turned it off.");
    puts("Can you bypass my new security?");
    printf(">> ");
    fgets(buffer, sizeof(buffer), stdin);
    puts("Welp, try again!");
    printf("Your payload before: ");
    printf(buffer);
    puts("");
    puts("-----");
    puts("Last chance!");
    printf(">> ");
    fgets(buffer, 120, stdin);
    puts("HAHAA.. I think this is the strongest protection!");
}

int main(void){
    init();
    vuln();
    return 0;
}