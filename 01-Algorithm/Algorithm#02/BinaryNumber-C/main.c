//
//  main.c
//  BinaryNumber-C
//
//  Created by Shintaro Kaneko on 12/11/14.
//  Copyright (c) 2014 Shintaro Kaneko. All rights reserved.
//

#include <stdio.h>

void binary_number(char *binary, int *length, int decimal_number) {
    binary[(*length)] = 48 + decimal_number % 2;
    (*length)++;
    decimal_number = decimal_number / 2;
    if (decimal_number != 0) {
        binary_number(binary, length, decimal_number);
    }
}

int main(int argc, const char * argv[]) {
    int length = 0;
    char binary[100];
    binary_number(binary, &length, 109);
    while (length-- != 0) {
        printf("%c", binary[length]);
    }
    printf("\n");
    return 0;
}
