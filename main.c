#include "libs/data_struct/stack/stack.h"


int inArray(char sym){
    char s[] = {')','=','>','+','*','-',  '('};
    for(int i = 0; i < 7; i++){
        if(s[i] == sym) return i;
    }
    return -1;
}

void writePolskaiaZapis(char *str, char *symbol){
    stackNode *next = NULL;
        for(int i = 0; i < strlen(str); i++){
        int ord = inArray(str[i]);
        if(ord != -1){
            int ordPref;
            if(next)
                ordPref = inArray(*next->data);
            if(next == NULL || ordPref < ord || ordPref==6)
                next = push_(next, &str[i], sizeof(str[i]));
            else{
                if(str[i] == ')'){
                    while (1){
                        *symbol = *next->data;
                        symbol++;
                        next = pop_(next);

                        if(*next->data == '('){
                            next = pop_(next);
                            break;
                        }
                    }
                }
                else{
                    while (1){
                        *symbol = *next->data;
                        symbol++;
                        next = pop_(next);
                        if(next == NULL){
                            next = push_(next, &str[i], sizeof(str[i]));
                            break;
                        }
                        int pref = inArray(*next->data);
                        if(pref < ord || pref == 6){
                            next = push_(next, &str[i], sizeof(str[i]));
                            break;
                        }
                    }
                }
            }
        } else{
            *symbol = str[i];
            symbol++;
        }
    }
    symbol--;
    while (next){
        *symbol = *next->data;
        symbol++;
        next = pop_(next);
    }
    *symbol = '\0';
    freeStack(next);
}



int main(){
    char buf[100];
    while (fgets(buf, 99, stdin) != NULL){
        if(buf[0] == 'q') break;
        char * str = &buf[0];
        char ans[strlen(str)+1];
        writePolskaiaZapis(str, &ans[0]);
        printf("%s", ans);
    }
    return 1;
}