#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void a() {
    asm(
        "popq %rdx;"
        "ret;"
    );
}

void admin_login(int param1, int param2, int param3){
    if (param1 == 0xdeaddead && param2 == 0xfeedbeef && param3 == 0xc0debabe){
        puts("[+] Welcome back admin!");
        system("/bin/sh");
    }
    else{
        char name[50];
        puts("Hello there what is your name?");
        scanf("%49s", name);
        printf("Hello %s\n", name);
        puts("Nice to meet you!");
        printf("Exiting program");
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        exit(0);
    }
}

void vuln(){
    char buffer[80];
    puts("Try to login as admin.");
    puts("Simply guess the admin username, hence you shall logged in!");
    printf("> ");
    fgets(buffer, 160, stdin);
    puts("You failed to login as admin :(");
}

int main(void){
    vuln();
    return 0;
}