#include <stdio.h>
#include <stdint.h>
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
    while ((index-- > 0) && (k >= 0)) {
        x += b * (s[index] - '0');
                b *= 10;
                printf("%d\n", x);
        if (j++ >= 9 || index <= 0) {
            rez.a[k--] = x;
            j = 1;
            b = 1;
            x = 0;
        }
    }
    return rez;

}
int add(int a, int b, uint8_t *carry) {
    int res;
    res = a + b + *carry;
    if (res > 999999999) {
        *carry = 1;
        res -= 1000000000;
        }
    else {
        *carry = 0;
    }
    return res;
}
uint1024_t add_op(uint1024_t num1, uint1024_t num2){
    int i;
    uint8_t carry = 0;
    uint1024_t result;
    init(&result);
    for (i = 34; i >= 0; i--){
        result.a[i] = add(num1.a[i], num2.a[i], &carry);
    }
    return result;
}
int sub(int a, int b, uint8_t *carry) {
    int res;
    res = a - b - *carry;
    if (res < 0) {
        *carry = 1;
        res += 1000000000;
    }
    else {
        *carry = 0;
    }
    return res;
}
uint1024_t subtr_op(uint1024_t num1, uint1024_t num2){
    int i;
    uint8_t carry = 0;
    uint1024_t result;
    init(&result);
    for (i = 34; i >= 0; i--){
        result.a[i] = sub(num1.a[i], num2.a[i], &carry);
    }
    return result;
}
uint1024_t mult_op(uint1024_t num1, uint1024_t num2){
    int i;
    int j;
    int k;
    long long r;
    int r1, r2;
    uint8_t carry = 0;
    uint1024_t result;
    init(&result);

    for (i = 34; i >= 0; i--){
        for (j = 34; j >= 0; j--) {
            k = (i + j - 34);
            if (k < 0)
                continue;
            r = (long long) num1.a[i] * (long long) num2.a[j];
           // printf("%d%d", r);
            r1 = r % 1000000000;
            r2 = r / 1e9;
            carry = 0;
            if (r1 > 0){
                result.a[k] = add(result.a[k], r1, &carry);
                // printf("%d\n", result.parts[k]);
            }
            if (k >= 1 && r2 > 0){
                result.a[k - 1] = add(result.a[k - 1], r2, &carry);
                // printf("%d%d\n", result.parts[k - 1]);
            }
        }
    }
    return result;
}
void ToString (uint1024_t rez, char *s) {
        int index = 0;
    for (int i = 0; i < arr_size; i++) {
        index += sprintf(&s[index], "%d", rez.a[i]); // rez.a[i] записывается в &s[index]
    }
    delLeadZeros(s, s);
}
void delLeadZeros(char *str, char *dest)
{
    int i;
    for (i = 0; i < strlen(str) - 1; i++) {
        if (str[i] != '0')
            break;
    }
    strcpy(dest, str + i); // копируем str + i в destr и получаем строку без лишних нулей в начале
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

    printf("%s", "Enter your firs number:");
    scanf("%s", s);
    first_num = scanf_our(s);

    printf("%s", "Enter your second number:");
    scanf("%s", s);
    second_num = scanf_our(s);

    rez = add_op(first_num, second_num);
    ToString(rez, s);
    printf("%s\n",s);

    rez = subtr_op(first_num, second_num);
    ToString(rez, s);
    printf("%s\n",s);

    rez = mult_op(first_num, second_num);
    ToString(rez, s);
    printf("%s\n",s);
    return 0;
}