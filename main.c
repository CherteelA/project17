#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include "libs/data_struct/string/processing_string.h"
void testLab20();
char *find_suffix(char *s);
//tusk 10...............................................................................................................
volatile sig_atomic_t print_next = 0;
void handle_signal(int sig){
    if(sig==SIGINT){
        print_next = 1;
    }
}
int main(int argc, char *argv[]) {
    char lines[] = "gggggggg aaaaaaaaa\npppppp\nkkkkkkkk llllllll pppppppp\nprogram\nend\nnow\nfffff\nnnnnnnn\nmmmmmmmm\nwait\n1\nsec";
    char *suffix = find_suffix(argv[1]);
    if(find_suffix(argv[1]) == NULL || !strcmp_(suffix, ".txt")){
        fprintf(stderr, "add to file suffix: .txt");
        exit(1);
    }
    char *begin = argv[2];
    while (*begin!='\0'){
        if(*begin < '0' || *begin > '9'){
            fprintf(stderr, "second parameter must be an integer");
            exit(1);
        }
        begin++;
    }
    FILE *f = fopen(argv[1], "w+");
    if(f==NULL) {
        fprintf(stderr, "Fail");
        exit(1);
    }
    fputs(lines, f);
    fseek(f, 0L, 0);
    int count_line = 0;
    int N = atoi(argv[2]);
    while(fgets(lines, 1000, f) > 0){
        signal(SIGINT, handle_signal);
        while (!print_next){}
        if(print_next){
            printf("%s", lines);
            count_line++;
        }
        if(count_line == N) {
            print_next = 0;
            count_line = 0;
        }
    }
    printf("\n");
    testLab20();
    return 0;
}

