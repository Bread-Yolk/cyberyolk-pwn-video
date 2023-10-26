#include <stdio.h>
#include <stdlib.h>

// gcc -fno-stack-protector -Wl,-z,norelro -no-pie -z execstack chall.c -o chall

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void vuln(){
    char buffer[100], flag_val[50];
    FILE *f = fopen("./flag.txt", "rb");
    if (f == NULL) {
        puts("flag.txt not found, please create it.");
        exit(0);
    }

    fgets(flag_val, 64, f);      
    fclose(f);

    puts("Read the flag for me!");
    printf("> ");
    fgets(buffer, sizeof(buffer), stdin);
    printf(buffer);
}

int main(void){
    init();
    vuln();

    return 0;
}