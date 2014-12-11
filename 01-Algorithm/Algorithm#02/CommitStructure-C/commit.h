// commit.h
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

#ifndef _ALGORITHM_02_COMMIT_H_
#define _ALGORITHM_02_COMMIT_H_

#include <time.h>

typedef struct commit_info {
    char *message;
    char *author;
    char *email;
    struct _commit_info *_internal;
} commit_info;

typedef struct commit {
    commit_info *info;
    struct commit *next;
} commit;


/**
 * Create a commit.
 */
commit *commit_create();

/**
 * Create a commit info.
 */
commit_info *commit_create_info();

/**
 * Set a hash to the commit info.
 */
void commit_set_hash(commit_info *, char *);

/**
 * Release the commit.
 */
void commit_destroy(commit *);

/**
 * Print a description for the commit list.
 */
void commit_print_list(commit *);

/**
 * Print a description for the commit.
 */
void commit_print(commit *);

/**
 * Print a debug description for the commit list.
 */
void commit_debug_print_list(commit *);

/**
 * Print a debug description for the commit.
 */
void commit_debug_print(commit *);

/**
 * Add a new commit with the info to tail of the list.
 */
commit *commit_append(commit *, commit_info *);

/**
 * Add a new commit with the info to head of the list.
 */
commit *commit_prepend(commit *, commit_info *);

/**
 *
 */
commit *commit_lookup(commit *, char *);

// ===

/**
 * Add a new commit with the info.
 */
commit *commit_do(commit *, commit_info *);

/**
 * Checkout
 */
commit *commit_checkout(commit *, char *);


#endif

