#include <stdio.h>
#include <stdlib.h>
// gcc -z execstack chall.c -o chall

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void vuln(){
    char buffer[100];
    puts("Can you spawn shell for me? Got SIGSGEV means you failed.");
    printf(">> ");
    fgets(buffer, sizeof(buffer), stdin);
    (*(void  (*)()) buffer)();
}

int main(void){
    init();
    vuln();
    return 0;
}