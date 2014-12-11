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
#include <string.h>

#include "commit.h"

commit_info *create_info(char *message, char *hash) {
    commit_info *info = commit_create_info();
    info->message = message;
    info->author = "Shintaro Kaneko";
    info->email = "kaneshin0120@gmail.com";
    commit_set_hash(info, hash);
    return info;
}

int main(int argc, const char * argv[]) {
    commit *head = commit_create();
    commit *master = commit_create();
    commit *develop = commit_create();

    master = commit_do(head, create_info("Master 1st commit", "m1"));
    master = commit_do(head, create_info("Master 2nd commit", "m2"));
    master = commit_do(head, create_info("Master 3rd commit", "m3"));
    master = commit_do(head, create_info("Master 4th commit", "m4"));
    master = commit_do(head, create_info("Master 5th commit", "m5"));

    commit_checkout(head, "m3");

    develop = commit_do(head, create_info("Develop 1st commit", "d1"));
    develop = commit_do(head, create_info("Develop 2nd commit", "d2"));
    develop = commit_do(head, create_info("Develop 3rd commit", "d3"));

    printf("\n\n=== Master Branch ===\n\n");
    commit_debug_print_list(master);
    
    printf("\n\n=== Develop Branch ===\n\n");
    commit_debug_print_list(develop);

    return 0;
}
