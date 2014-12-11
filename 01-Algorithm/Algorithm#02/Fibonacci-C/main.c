//
//  main.c
//  Fibonacci-C
//
//  Created by Shintaro Kaneko on 12/11/14.
//  Copyright (c) 2014 Shintaro Kaneko. All rights reserved.
//

#include <stdio.h>

int fibonacci(int n, int f1, int f0) {
    int fn = f1 + f0;
    if (n >= 2) {
        fn = fibonacci(--n, fn, f1);
    } else {
        if (n == 1) {
            return f1;
        } else {
            return f0;
        }
    }
    return fn;
}

int main(int argc, const char * argv[]) {
    int fn, f1, f0;
    int n = 15;

    {
        f1 = 1;
        f0 = 0;
        fn = fibonacci(n, f1, f0);
    }
    printf("F_%d = %d\n", n, fn);

    {
        if (n >= 2) {
            for (int i = 2; i <= n; i++) {
                fn = f1 + f0;
                f0 = f1;
                f1 = fn;
            }
        } else if (n == 1) {
            fn = f1;
        } else {
            fn = f0;
        }
    }
    printf("F_%d = %d\n", n, fn);
    return 0;
}
