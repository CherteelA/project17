//
// Created by admin on 23.04.2024.
//
#include "lab19.h"
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__);
//tusk1
void toColFromRow(FILE *file){
    char n_arr[100];
    fgets(n_arr, 100, file);
    char tempNumb[100];
    copy(n_arr, find(n_arr, n_arr+100, '\n')+1,tempNumb);
    replace(n_arr, "\n", "\0");
    int n = atoi(n_arr);
    int values[1000];
    int size = 0;
    while (feof(file)==0){
        const char numb = (char)fgetc(file);
        if(numb>='0' && numb <='9'){
            values[size] = atoi(&numb);
            size++;
        }
    }
    matrix matrix = createMatrixFromArray(values, n, size/n);
    transposeMatrix(&matrix);
    char result[size];
    int size_res = 0;
    for(int i = 0; i < size/n; i++){
        for(int j = 0; j < n; j++){
            result[size_res] = (char)(matrix.values[i][j] + 48);
            size_res++;
        }
        result[size_res] = '\n';
        size_res++;
    }
    FILE *Fresult = fopen("res.txt","w");
    fputs(tempNumb, Fresult);
    fputs(result, Fresult);
    fclose(Fresult);
}

void test1_tusk1(){
    char s[1000] = "4\n123456789\n963852741\n159236478\n951632874";
    FILE *f = fopen("my_file.txt", "w");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fclose(f);
    FILE *file= fopen("my_file.txt", "r");
    toColFromRow(f);
    fclose(file);
    file = fopen("res.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("4\n1919\n2655\n3391\n4826\n5533\n6262\n7748\n8477\n9184\n",res);
    remove("res.txt");
    remove("my_file.txt");
}
void test2_tusk1(){
    char s[1000] = "5\n951632874\n789420000\n556236985\n123456789\n333333333";
    FILE *f = fopen("my_file.txt", "w");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fclose(f);
    FILE *file= fopen("my_file.txt", "r");
    toColFromRow(f);
    fclose(file);
    file = fopen("res.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("5\n97513\n58523\n19633\n64243\n32353\n20663\n80973\n70883\n40593\n",res);
    remove("res.txt");
    remove("my_file.txt");
}
void test3_tusk1(){
    char s[1000] = "2\n951632874\n951632874";
    FILE *f = fopen("my_file.txt", "w");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fclose(f);
    FILE *file= fopen("my_file.txt", "r");
    toColFromRow(f);
    fclose(file);
    file = fopen("res.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("2\n99\n55\n11\n66\n33\n22\n88\n77\n44\n",res);

}
void test_lab19(){
    test1_tusk1();
    test2_tusk1();
    test3_tusk1();
}