#include <stdio.h>
#include <stdlib.h>
// gcc -z execstack chall.c -o chall
void vuln(){
    char buffer[100];
    puts("Can you spawn shell for me? Got SIGSGEV means you failed.");
    printf(">> ");
    fgets(buffer, sizeof(buffer), stdin);
    (*(void  (*)()) buffer)();
}

int main(void){
    vuln();
    return 0;
}