#include <stdio.h>
#include <stdlib.h>
// gcc -fno-stack-protector -z execstack chall.c -o chall

void vuln(){
    char buffer[100];
    printf("Oopss, stack address leaked! %p\n", &buffer);
    puts("Try to spawn a shell again!");
    printf(">> ");
    scanf("%s", buffer);
    puts("Sadly you failed.");
}

int main(void){
    vuln();

    return 0;
}
