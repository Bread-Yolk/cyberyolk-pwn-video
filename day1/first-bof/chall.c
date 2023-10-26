#include <stdio.h>
// gcc -fno-stack-protector -Wl,-z,norelro -no-pie -z execstack chall.c -o chall

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main(void){
    init();
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