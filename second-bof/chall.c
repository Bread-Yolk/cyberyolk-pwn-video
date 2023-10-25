#include <stdio.h>

int main(void){
    char buffer[65];
    int number = 0;
    puts("BOF me again!");
    printf("> ");
    gets(buffer);
    if(number = 1337){
        puts("Using BOF to overwrite stack value.");
    }

    return 0;
}