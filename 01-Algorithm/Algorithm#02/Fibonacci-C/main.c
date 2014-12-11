// main.c
//
// Copyright (c) 2014 Shintaro Kaneko
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
