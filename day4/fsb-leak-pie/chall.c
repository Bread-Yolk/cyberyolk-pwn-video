#include <stdio.h>
#include <stdlib.h>
// gcc -fno-stack-protector chall.c -o chall
void get_shell(){
    puts("[+] SHELL SPAWNED!");
    system("/bin/sh");
}

void vuln(){
    char buffer[50];
    puts("This time is harder to spawn shell, can you bypass my security?");
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
    vuln();
    return 0;
}