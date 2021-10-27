#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
#include <string.h>
#include<math.h>

#define arr_size 35
#define string_size 315
#define len 9
#define base 1e9

typedef struct {
    int a[arr_size];
    } uint1024_t;

void init(uint1024_t* x)
{
    for (int i = 0; i < arr_size; i++)
        x->a[i] = 0;
}

uint1024_t scanf_our(char *s) {
    uint1024_t rez;
    init(&rez);
    int i;
    int x = 0;
    int j = 1;
    int index = strlen(s);
    int b = 1;
    int k = arr_size - 1;
    
}

int main() {
    uint1024_t first_num;
    uint1024_t second_num;
    uint1024_t rez;
    init(&first_num);
    init(&second_num);
    init(&rez);
    char s[string_size];

    for (int i = 0; i < 35; i++){
        first_num.a[i] = 0;
        second_num.a[i] = 0;
        rez.a[i] = 0;
    }

    scanf("%s", s);
    first_num = scanf_our(s);

    scanf("%s", s);
    second_num = scanf_our(s);
    return 0;
}