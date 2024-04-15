//
// Created by admin on 10.04.2024.
//

#include "test_processing_string.h"
#include "../string_.h"
#include "../processing_string.h"


#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define ASSERT_STRING_INT(expected, got) assertStringInt(expected, got, __FILE__, __FUNCTION__, __LINE__)
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (!strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void assertStringInt(int expected, int got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (expected != got) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%d\"\n", expected);
        fprintf(stderr, "Got: \"%d\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

//tusk 1.........................................................................................
void test_removeNonLetters_first(){
    char words[] = "hello, how are you";
    removeNonLetters(words);
    ASSERT_STRING("hello,howareyou", words);
}
void test_removeNonLetters_second(){
    char words[] = "hi 12 3     25548\n 15 jkk";
    removeNonLetters(words);
    ASSERT_STRING("hi1232554815jkk", words);
}
void test_removeNonLetters_third(){
    char words[] = "hi1232554815jkk";
    removeNonLetters(words);
    ASSERT_STRING("hi1232554815jkk", words);
}
void test_removeNonLetters_fourth(){
    char words[] = "  ";
    removeNonLetters(words);
    ASSERT_STRING("", words);
}
//tusk 2.1......................................................................................
void test_removeAdjacentEqualLetters_first(){
    char words[] = "aaaaa";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("a", words);
}
void test_removeAdjacentEqualLetters_second(){
    char words[] = "aaa bb bb";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("a b b", words);
}
void test_removeAdjacentEqualLetters_third(){
    char words[] = "  ";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING(" ", words);
}
void test_removeAdjacentEqualLetters_fourth(){
    char words[] = "";
    removeAdjacentEqualLetters(words);
    ASSERT_STRING("", words);
}
//2.2..............................................................................
void test_removeExtraSpaces_first(){
    char words[] = "aaaaa";
    removeExtraSpaces(words);
    ASSERT_STRING("aaaaa", words);
}
void test_removeExtraSpaces_second(){
    char words[] = "aaa  bb  b";
    removeExtraSpaces(words);
    ASSERT_STRING("aaa bb b", words);
}
void test_removeExtraSpaces_third(){
    char words[] = "  ";
    removeExtraSpaces(words);
    ASSERT_STRING(" ", words);
}
void test_removeExtraSpaces_fourth(){
    char words[] = "";
    removeExtraSpaces(words);
    ASSERT_STRING("", words);
}
//3.......................................................................................................................
void test_digitToStart_first(){
    char s[] = "hello81 F822";
    changeWords_numb(s);
    ASSERT_STRING("18hello 228F", s);
}
void test_digitToStart_second(){
    char s[] = "hello81 zxc123456789 856947";
    changeWords_numb(s);
    ASSERT_STRING("18hello 987654321zxc 749658", s);
}
void test_digitToStart_third(){
    char s[] = "";
    changeWords_numb(s);
    ASSERT_STRING("", s);
}
void test_getWordReverse(){
    WordDescriptor word;
    char s[] = "123 222 8585";
    getWordReverse(s,s + strlen_(s)-1, &word);
    ASSERT_STRING("8585", word.begin);
}
//решение задачи №1
void test_LettersToStart_first(){
    char s[] = "hello81 tF822";
    changeWords_Letters(s);
    ASSERT_STRING("olleh81 Ft822", s);
}
void test_LettersToStart_second(){
    char s[] = "18hello 987654321zxc 749658";
    changeWords_Letters(s);
    ASSERT_STRING("olleh18 cxz987654321 749658", s);
}

//4.....................................................................................................................
void test_doSpace_first(){
    char s[100] = "he3l1lo5";
    doSpace(s);
    ASSERT_STRING("he   l lo     ", s);
}
void test_doSpace_second(){
    char s[100] = "123";
    doSpace(s);
    ASSERT_STRING("      ", s);
}
void test_doSpace_third(){
    char s[100] = "";
    doSpace(s);
    ASSERT_STRING("", s);
}

//5.....................................................................................................................
void test_replace_first(){
    char s[] = "hhhhh hhhhhf hhh";
    char s1[] = "hhhhh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhhhhf hhh", s);
}
void test_replace_second(){
    char s[] = "hhhhh hhhhh hhhhh hhhhh";
    char s1[] = "hhhhh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh hhh hhh", s);
}
void test_replace_third(){
    char s[] = "adfg adfg adfg adfg ,adfg";
    char s1[] = "adfg";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh hhh hhh ,adfg", s);
}
void test_replace_fourth(){
    char s[] = ",adfg ,adfg ,adfg ,adfg ,adfg";
    char s1[] = "adfg";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING(",adfg ,adfg ,adfg ,adfg ,adfg", s);
}
void test_replace_fifth(){
    char s[] = "hh hh hha";
    char s1[] = "hh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh hha", s);
}
void test_replace_sixth(){
    char s[] = "hh hh h";
    char s1[] = "hh";
    char s2[] = "hhh";
    replace(s, s1, s2);
    ASSERT_STRING("hhh hhh h", s);
}
//6.......................................................................................................................
void test_areWordsEqual_first(){
    char s1[] = "abc";
    char s2[] = "abcg";
    WordDescriptor w1, w2;
    getWord(s1,&w1);
    getWord(s2,&w2);
    ASSERT_STRING_INT(0, areWordsEqual_comparison(w1, w2));
}
void test_areWordsEqual_second(){
    char s1[] = "abc";
    char s2[] = "abc";
    WordDescriptor w1, w2;
    getWord(s1,&w1);
    getWord(s2,&w2);
    ASSERT_STRING_INT(2, areWordsEqual_comparison(w1, w2));
}
void test_areWordsEqual_third(){
    char s1[] = "bcd";
    char s2[] = "abcd";
    WordDescriptor w1, w2;
    getWord(s1,&w1);
    getWord(s2,&w2);
    ASSERT_STRING_INT(1, areWordsEqual_comparison(w1, w2));
}

void test_OrderedWords_first(){
    int ans;
    char s[100] = "abcdd mdfgh zxc";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(1, ans);
}
void test_OrderedWords_second(){
    int ans;
    char s[100] = "abcdd mdfgh axc";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(0, ans);
}
void test_OrderedWords_third(){
    int ans;
    char s[100] = "abcdd abcdd abvc aa";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(0, ans);
}
void test_OrderedWords_fourth(){
    int ans;
    char s[100] = "abcdd abcdd abvc abvz aa";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(0, ans);
}
void test_OrderedWords_sixth(){
    int ans;
    char s[100] = "abcd abcdd abvc abvz";
    if(OrderedWords(s))
        ans = 1;
    else
        ans = 0;
    ASSERT_STRING_INT(1, ans);
}
//8...........................................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//работает
/*
void test_print_string_revers_first(){
    char s[MAX_STRING_SIZE] = "aaaa ssss dddd ff ggg hhhh j";
    print_string_revers(s);
}
void test_print_string_revers_second(){
    char s[MAX_STRING_SIZE] = "";
    print_string_revers(s);
}
*/
//8...........................................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
void test_count_count_palindrome_first(){
    char s[MAX_STRING_SIZE] = "Nun, Level, Deed, Sagas, Peep";
    ASSERT_STRING_INT(5, count_palindrome(s));
}
void test_count_count_palindrome_second(){
    char s[MAX_STRING_SIZE] = "Nun, Level, Deed, Saga, Peep";
    ASSERT_STRING_INT(4, count_palindrome(s));
}
//9...........................................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
void test_switch_words_first(){
    char s1[MAX_STRING_SIZE] = "fff ggg hhh jjj";
    char s2[MAX_STRING_SIZE] = "kkk lll qqq www";
    char ans[MAX_STRING_SIZE];
    switch_words(s1,s2,ans);
    ASSERT_STRING("fff kkk ggg lll hhh qqq jjj www", ans);
}
void test_switch_words_second(){
    char s1[MAX_STRING_SIZE] = "fff ggg hhh jjj";
    char s2[MAX_STRING_SIZE] = "kkk lll qqq www mmmmm fffffffafa";
    char ans[MAX_STRING_SIZE];
    switch_words(s1,s2,ans);
    ASSERT_STRING("fff kkk ggg lll hhh qqq jjj www mmmmm fffffffafa", ans);
}
void test_switch_words_third(){
    char s1[MAX_STRING_SIZE] = "fff ggg hhh jjj mmmmm fffffffafa";
    char s2[MAX_STRING_SIZE] = "kkk lll qqq www";
    char ans[MAX_STRING_SIZE];
    switch_words(s1,s2,ans);
    ASSERT_STRING("fff kkk ggg lll hhh qqq jjj www mmmmm fffffffafa", ans);
}
//10....................................................................................................................
void test_reverse_string_first(){
    char s[MAX_STRING_SIZE] = "fff ggg hhh jjj";
    reverse_string(s);
    ASSERT_STRING("jjj hhh ggg fff", s);
}
void test_reverse_string_second(){
    char s[MAX_STRING_SIZE] = "a d f  g";
    reverse_string(s);
    ASSERT_STRING("g f d a", s);
}
//11......................................................................................................................
/*
void test_printWordBeforeFirstWordWithA_first(){
    char s[MAX_STRING_SIZE] = "  tttt g skldk aggg";
    printWordBeforeFirstWordWithA(s);
    //ответ: skldk, сошлось
}
void test_printWordBeforeFirstWordWithA_second(){
    char s[MAX_STRING_SIZE] = "  tttt g hkldk gggg";
    printWordBeforeFirstWordWithA(s);
    //ответ:no one word with A, сошлось
}
void test_printWordBeforeFirstWordWithA_third(){
    char s[MAX_STRING_SIZE] = "   ";
    printWordBeforeFirstWordWithA(s);
    //ответ: no one word in string, сошлось
}
void test_printWordBeforeFirstWordWithA_fourth(){
    char s[MAX_STRING_SIZE] = "  attt g akldk gggg";
    printWordBeforeFirstWordWithA(s);
    //ответ: word with letter A first, сошлось
}
*/
//12.......................................................................................................................
void test_wordDescriptorToString_first(){
    char s[MAX_STRING_SIZE] = "hgh gg ggg";
    WordDescriptor word;
    char ans[MAX_STRING_SIZE];
    getWord(s,&word);
    wordDescriptorToString(word, ans);
    ASSERT_STRING("hgh", ans);
}
void test_wordDescriptorToString_second(){
    char s[MAX_STRING_SIZE] = "  hgh gg ggg";
    WordDescriptor word;
    char ans[MAX_STRING_SIZE];
    getWord(s,&word);
    wordDescriptorToString(word, ans);
    ASSERT_STRING("hgh", ans);
}
void test_word_in_string_frist(){
    char s[MAX_STRING_SIZE] = "hgh gg ggg";
    WordDescriptor word;
    char string[MAX_STRING_SIZE] = "vnev eee edjvj hgh veve";
    int ans;
    getWord(s,&word);
    if(word_in_string(word,string)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_word_in_string_second(){
    char s[MAX_STRING_SIZE] = "hgh gg ggg";
    WordDescriptor word;
    char string[MAX_STRING_SIZE] = "vnev eee edjvj egeg hgh";
    int ans;
    getWord(s,&word);
    if(word_in_string(word,string)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(1, ans);
}
void test_word_in_string_third(){
    char s[MAX_STRING_SIZE] = "hgh gg ggg";
    WordDescriptor word;
    char string[MAX_STRING_SIZE] = "vnev eee edjvj egeg ss";
    int ans;
    getWord(s,&word);
    if(word_in_string(word,string)){
        ans = 1;
    } else{
        ans = 0;
    }
    ASSERT_STRING_INT(0, ans);
}
void test_wordFromEndFirstLineWhichStayInSecondLine_first(){
    char s1[MAX_STRING_SIZE] = "hgh gg ggg";
    char s2[MAX_STRING_SIZE] = "vnev eee gg egeg ss";
    WordDescriptor ansW = wordFromEndFirstLineWhichStayInSecondLine(s1,s2);
    char ans [MAX_STRING_SIZE];
    wordDescriptorToString(ansW,ans);
    ASSERT_STRING("gg", ans);
}
void test_wordFromEndFirstLineWhichStayInSecondLine_second(){
    char s1[MAX_STRING_SIZE] = "hgh gg ggg";
    char s2[MAX_STRING_SIZE] = "vnev eee sgg egeg ss";
    WordDescriptor ansW = wordFromEndFirstLineWhichStayInSecondLine(s1,s2);
    char ans [MAX_STRING_SIZE];
    wordDescriptorToString(ansW,ans);
    ASSERT_STRING("hgh", ans);
}

void test_lab18(){
    test_removeNonLetters_first();
    test_removeNonLetters_second();
    test_removeNonLetters_third();
    test_removeNonLetters_fourth();
    test_removeAdjacentEqualLetters_first();
    test_removeAdjacentEqualLetters_second();
    test_removeAdjacentEqualLetters_third();
    test_removeAdjacentEqualLetters_fourth();
    test_removeExtraSpaces_first();
    test_removeExtraSpaces_second();
    test_removeExtraSpaces_third();
    test_removeExtraSpaces_fourth();
    test_digitToStart_first();
    test_digitToStart_second();
    test_digitToStart_third();
    test_LettersToStart_first();
    test_LettersToStart_second();
    test_getWordReverse();
    test_doSpace_first();
    test_doSpace_second();
    test_doSpace_third();
    test_replace_first();
    test_replace_second();
    test_replace_third();
    test_replace_fourth();
    test_replace_fifth();
    test_replace_sixth();
    test_areWordsEqual_first();
    test_areWordsEqual_second();
    test_areWordsEqual_third();
    test_OrderedWords_first();
    test_OrderedWords_second();
    test_OrderedWords_third();
    test_OrderedWords_fourth();
    test_OrderedWords_sixth();
    /*
    test_print_string_revers_first();
    test_print_string_revers_second();
    */
    test_count_count_palindrome_first();
    test_count_count_palindrome_second();
    test_switch_words_first();
    test_switch_words_second();
    test_switch_words_third();
    test_reverse_string_first();
    test_reverse_string_second();
    /*
    test_printWordBeforeFirstWordWithA_first();
    test_printWordBeforeFirstWordWithA_second();
    test_printWordBeforeFirstWordWithA_third();
    test_printWordBeforeFirstWordWithA_fourth();
     */
    test_wordDescriptorToString_first();
    test_wordDescriptorToString_second();
    test_word_in_string_frist();
    test_word_in_string_second();
    test_word_in_string_third();
    test_wordFromEndFirstLineWhichStayInSecondLine_first();
    test_wordFromEndFirstLineWhichStayInSecondLine_second();
}