#include "polscaiaZapis.h"

int inArray(char sym){
    char s[] = {')','=','>','+','&','-',  '('};
    for(int i = 0; i < 7; i++){
        if(s[i] == sym) return i;
    }
    return -1;
}

void writePolskaiaZapis(char *str, char *symbol){
    stackNode *next = NULL;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            continue;
        }
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

//операции
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
                if (*begin == '&')
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


void solve(){
    SetConsoleOutputCP(CP_UTF8);
    printf("Введите логическое выражение, где дизъюнкция обозначается '+', конъюнкция '&',\nимпликация '>', эквивалентность '=', отрицание знаком '-' перед переменной,\nтакже можно использовать скобки ().\nВведите 'q' чтобы выйти.\n\n");
    char buf[100];
    while (fgets(buf, 99, stdin) != NULL){
        if(buf[0] == '\n'){
            printf("Логическое выражение введено неверно\n\n");
            continue;
        }
        if(buf[0] == 'q') break;
        char *str = &buf[0];
        char ans[strlen(str)+1];
        writePolskaiaZapis(str, &ans[0]);
        if(ans[0] == '\0') {
            printf("Логическое выражение введено неверно\n\n");
            continue;
        }
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
}




int uniqRes(char *S1, char *S2){
    char *begin1 = S1;
    char *begin2 = S2;
    while (*begin1 != '\0' || *begin2 != '\0'){
        if(*begin1 != *begin2){
            return 0;
        }
        begin1++;
        begin2++;
    }
    return *begin1 == *begin2;
}

void set(char *s1, char *s2){
    char *begin = s1;
    while (*begin!='\0'){

        char *beg = s2;
        int flag = 1;
        while (*beg!='\0'){
            if(*beg == *begin && *beg!='+' &&  *beg!='-'){
                int N = 0;
                if(beg != s2){
                    if(*(beg-1) == '-'){
                        N++;
                    }
                }
                if(begin != s1){
                    if(*(begin-1) == '-'){
                        N++;
                    }
                }
                if(N == 0){
                    flag = 0;
                }
                else if(N == 2){
                    flag = 2;
                }
            }
            beg++;
        }
        if(flag == 1){
            *beg = *begin;
        }
        if(flag == 2){
            *(beg-1) = ' ';
        }
        begin++;
    }
    begin = s2;
    while (*begin!='\0'){
        if(*begin == *(begin+1) && *begin == '+'){
            *begin=' ';
        }
        if(*begin == '+' && (*(begin+1) == ' ' ||  *(begin+2) == ' ')){
            *begin=' ';
        }
        begin++;
    }
}

void gluing(char *ans, char *s){

    char arr[100][3];
    int indx = 0;
    char *begin = ans;
    while (*begin!= '\0'){
        char *beg = arr[indx];
        while(*begin!='+' && *begin != '\0'){
            if(*begin!=' ') {
                *beg = *begin;
                beg++;
            }
            begin++;
        }
        *beg = '\0';
        indx++;
        if(*begin!='\0')
            begin++;
    }
    begin = s;
    while (*begin!= '\0'){
        char *beg = arr[indx];
        while(*begin!='+' && *begin != '\0'){
            if(*begin!=' ') {
                *beg = *begin;
                beg++;
            }
            begin++;
        }
        *beg = '\0';
        indx++;
        if(*begin!='\0')
            begin++;
    }
    begin = ans;
    for(int i = 0; i < indx; i++){
        int flag1 = 0;
        for(int j = 0; j < indx; j++){
            if(i!=j&&uniqRes(arr[i],arr[j])){
                if(flag1){
                    arr[j][0] = '\0';
                }
                else {
                    *arr[j] = '\0';
                }
            }
            if((arr[i][0] == arr[j][1] && arr[j][1] != '\0') || (arr[i][1] == arr[j][0]&& arr[j][0] != '\0')){
                flag1 = 1;
                arr[j][0] = '\0';
            }
        }
        if(flag1){
            arr[i][0] = '\0';
        }
        char *beg = arr[i];
        int flag = 0;
        while (*beg!='\0'){
            flag = 1;
            *begin = *beg;
            begin++;
            beg++;
        }
        if(flag) {
            *begin = '+';
            begin++;
        }
    }
    if(begin == ans){
        *begin = '\0';
    }
    else {
        *(begin - 1) = '\0';
    }
}

int _AinB(int A, int *arr, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == A)
            return 1;
    }
    return 0;
}

void result(char arr[][100], int size, char ans[1000], char resolvent[100], int *size_rez,int *flag, int *sizeAns, int *indx, int *arrRout){
    if(*flag == 1){
        return;
    }
    if(*sizeAns == 0){
        for(int i = 0; i < size; i++){
            if(*flag)
                break;
            char *begin = arr[i];
            arrRout[*indx] = i;
            (*indx)++;
            while (*begin!='\0'){
                *ans = *begin;
                *resolvent = *begin;
                resolvent++;
                begin++;
                ans++;
                (*sizeAns)++;
                (*size_rez)++;
            }
            *resolvent = '\0';
            *ans = '\0';
            resolvent -= *size_rez;
            result(arr, size, ans, resolvent, size_rez,flag,sizeAns, indx, arrRout);

            *sizeAns = 0;
            *size_rez = 0;
        }
    } else{
        for(int i = 0; i < size; i++){
            if(*flag)
                break;
            if(!_AinB(i, arrRout, *indx)){
                arrRout[*indx] = i;
                (*indx)++;
                *ans = '|';
                ans++;
                char *begin = arr[i];
                while (*begin != '\0'){
                    *ans = *begin;
                    ans++;
                    begin++;
                }
                *ans = '=';
                ans++;
                *ans = '\0';

                gluing(resolvent, arr[i]);
                char *b = resolvent;
                while (*b!='\0'){
                    *ans = *b;
                    ans++;
                    b++;
                }
                *ans = '\0';
                if(*resolvent == '\0'){
                    *flag = 1;
                    *ans='0';
                    *(++ans) = '\0';
                    return;
                }
                result(arr, size, ans, resolvent, size_rez,flag,sizeAns, indx, arrRout);
            }
        }
    }
}

void solve2() {
    SetConsoleOutputCP(CP_UTF8);
    printf("Введите количество посылок:");
    int N;
    scanf("%d", &N);
    char array[N + 1][100];
    printf("Введите посылки\n");
    for (int i = 0; i < N; i++) {
        scanf("%s", array[i]);
    }

    printf("Введите следствие\n");
    scanf("%s", array[N]);

    char str[100 * N * 2];
    char *strBegin = str;
    for (int i = 0; i <= N; i++) {
        char *begin = &array[i][0];
        while (*begin != '\0') {
            if(*(begin-1) != '-') {
                *strBegin = ' ';
                strBegin++;
            }
            *strBegin = *begin;
            strBegin++;
            begin++;
        }
        if (i == N)
            break;
        if (i != N - 1) {
            *strBegin = '&';
            strBegin++;
        } else {
            *strBegin = '>';
            strBegin++;
        }
    }
    strBegin = str;
    int flag = 0;
    int countRes = 0;
    while (*strBegin!='\0'){
        if(flag){
            if(*strBegin != ' ' && *strBegin != '-' && *strBegin != '+' && *strBegin != '&'){
                if(*(strBegin-1) == '-'){
                    *(strBegin-1) = ' ';
                }
                else{
                    *(strBegin-1) = '-';
                }
            }
            else{
                if(*strBegin == '+'){
                    *strBegin = '&';
                }
                else if(*strBegin == '&'){
                    *strBegin = '+';
                }
            }
        }
        if(*strBegin == '>') {
            flag = 1;
            *strBegin = '&';
        }
        if(*strBegin == '&')
            countRes++;
        strBegin++;
    }
    countRes++;
    char resolvent[countRes][100];
    strBegin = str;
    for(int i = 0; i < countRes; i++){
        char *begin = resolvent[i];
        while (*strBegin != '&' && *strBegin!='\0'){
            if (*strBegin != ' '){
                *begin = *strBegin;
                begin++;
            }
            strBegin++;
        }
        *begin = '\0';
        strBegin++;

        for(int j = 0; j < i; j++){
            if(uniqRes(resolvent[j], resolvent[i])){
                countRes--;
                i--;
            }
        }

    }
    char ans[1000];
    char resolve[100];
    int sizeRes = 0;
    int flagAns = 0;
    int size = 0;
    int indx = 0;
    int rout[100];
    result(resolvent, countRes,ans,resolve,&sizeRes,&flagAns,&size,&indx, rout);

    if(flagAns){
        printf("Теорема доказана\n");
        printf("%s", ans);
    }
    else{
        printf("Теорема опровергнута\n");
    }
}

