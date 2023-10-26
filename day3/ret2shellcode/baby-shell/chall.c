#include <stdio.h>
#include <stdlib.h>
// gcc -fno-stack-protector -z execstack chall.c -o chall

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void vuln(){
    char buffer[100];
    printf("Oopss, stack address leaked! %p\n", &buffer);
    puts("Try to spawn a shell again!");
    printf(">> ");
    scanf("%s", buffer);
    puts("Sadly you failed.");
}

int main(void){
    init();
    vuln();

    return 0;
}
