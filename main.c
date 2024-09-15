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


char disjunction(int a, int b){
    if(a == '1' || b == '1')
        return '1';
    return '0';
}
char conjunctions(int a, int b){
    if(a==b && a == '1'){
        return '1';
    }
    return '0';
}
char addition(int a){
    if(a == '1') return '0';
    return '1';
}
char implication(int a, int b){
    if(b == '0' && a == '1'){
        return '0';
    }
    return '1';
}
char equal(int a, int b){
    if(a == b)
        return '1';
    return '0';
}

void findUnique(char *begin, char *array){
    *array = '\0';
    char *beginarray = array;
    while (*begin != '\0'){
        if(inArray(*begin) == -1){
            int IsUniq = 1;
            char *search = beginarray;
            while (*search != '\0'){
                if(*search == *begin){
                    IsUniq = 0;
                }
                search++;
            }
            if(IsUniq){
                *array = *begin;
                array++;
                *array = '\0';
            }
        }
        begin++;

    }
}

void readPolskaiaZapis(char *begin, char *str, char *value){
    stackNode *next = NULL;
    while (*begin!='\0'){
        int inStr = 0;
        char *strSearch = str;
        int indx = 0;
        while (*strSearch != '\0'){
            if(*strSearch == *begin){
                next = push_(next,&value[indx], sizeof(value[indx]));
                inStr = 1;
                break;
            }
            indx++;
            strSearch++;
        }
        if(inStr == 0){
            char ans;
            if(*begin == '-'){
                char a = *next->data;
                next = pop_(next);
                ans = addition(a);
                next = push_(next, &ans, sizeof(ans));
            }
            else {
                char b = *next->data;
                next = pop_(next);
                char a = *next->data;
                next = pop_(next);
                if (*begin == '+')
                    ans = disjunction(a, b);
                if (*begin == '*')
                    ans = conjunctions(a, b);
                if (*begin == '>') {
                    ans = implication(a, b);
                }
                if (*begin == '=')
                    ans = equal(a, b);

                next = push_(next, &ans, sizeof(ans));
            }
        }

        begin++;
    }
    printf("%c", *next->data);
    freeStack(next);
}


int main(){
    char buf[100];
    while (fgets(buf, 99, stdin) != NULL){
        if(buf[0] == 'q') break;
        char *str = &buf[0];
        char ans[strlen(str)+1];
        writePolskaiaZapis(str, &ans[0]);
        printf("%s\n", ans);
        char uniq[strlen(ans)];
        char *unicArray = &uniq[0];
        char *begin = &ans[0];
        findUnique(begin, unicArray);
        int indxZero;
        int len = (int)strlen(uniq);
        char arrayValue[len];

        char *s = uniq;
        while (*s!= '\0'){
            printf("%c ", *s);
            s++;
        }
        printf("f\n");
        for(int i = 0; i < len; i++){
            arrayValue[i] = '0';
        }
        int first = 1;
        while (1) {
            indxZero = -1;
            if(first == 0) {
                for (int i = 0; i < len; i++) {
                    if (arrayValue[i] == '0') {
                        indxZero = i;
                    }
                }
                if (indxZero == -1) {
                    break;
                }
                arrayValue[indxZero] = '1';
                for (int i = 0; i < len; i++) {
                    if (i > indxZero) {
                        arrayValue[i] = '0';
                    }
                }
            }
            first = 0;
            for(int i = 0; i < len; i++){
                printf("%c ", arrayValue[i]);
            }

            readPolskaiaZapis(&ans[0], &uniq[0], &arrayValue[0]);
            printf("\n");
        }
        printf("\n");
    }
    return 1;
}