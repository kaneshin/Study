// commit.c
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

#include "commit.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define COMMIT_INFO_HASH_LENGTH 64

// Private structure
typedef struct _commit_info {
    char *hash;
    time_t date;
} _commit_info;

const char *fmt[2] = {
    "commit %s\nAuthor: %s <%s>\nDate:   %s\n%s\n\n",
    "commit %s\nAuthor: %s <%s>\nDate:   %sPtr:    %p ---> %p\n\n%s\n\n"
};


///
/// private
///

commit *commit_alloc();
commit_info *commit_info_alloc();
void commit_free(commit *);
void commit_info_free(commit_info *);
bool commit_is_valid(commit *);


/**
 * Assign a commit with partially initialized.
 */
commit *commit_alloc() {
    commit *cmit = malloc(sizeof(commit));
    if (cmit == NULL) {
        // Can't be assigned to the heap memory.
        return NULL;
    }
    return cmit;
}

commit_info *commit_info_alloc() {
    commit_info *info = malloc(sizeof(commit_info));
    if (info == NULL) {
        // Can't be assigned to the heap memory.
        return NULL;
    }
    _commit_info *internal = malloc(sizeof(_commit_info));
    if (internal == NULL) {
        // Can't be assigned to the heap memory.
        // Release the assigned commit.
        free(info);
        return NULL;
    }
    // Use `calloc` to initialize by zero.
    internal->hash = calloc(COMMIT_INFO_HASH_LENGTH, sizeof(char));
    if (internal->hash == NULL) {
        // Can't be assigned to the heap memory.
        // Release the assigned commit info.
        free(internal);
        free(info);
        return NULL;
    }
    info->_internal = internal;
    return info;
}

/**
 * Free the commit
 */
void commit_free(commit *commit) {
    if (commit != NULL) {
        free(commit);
        commit = NULL;
    }
}

void commit_info_free(commit_info *info) {
    if (info != NULL) {
        _commit_info *internal = info->_internal;
        if (internal != NULL) {
            char *hash = internal->hash;
            if (hash != NULL) {
                free(hash);
                hash = NULL;
            }
            free(internal);
            internal = NULL;
        }
        free(info);
        info = NULL;
    }
}

/**
 * Check the validity of the commit.
 */
bool commit_is_valid(commit *commit) {
    commit_info *info = commit->info;
    return (bool)(info != NULL
                  && info->message != NULL
                  && info->author != NULL
                  && info->email != NULL
                  );
}

///
/// public
///

/**
 * Create an initialized commit.
 */
commit *commit_create() {
    commit *cmit = commit_alloc();
    cmit->info = commit_create_info();
    cmit->next = NULL;
    return cmit;
}

/**
 * Create an initialized commit info.
 */
commit_info *commit_create_info() {
    commit_info *info = commit_info_alloc();
    info->message = NULL;
    info->author = NULL;
    info->email = NULL;
    info->_internal->date = 0;
    return info;
}

/**
 * Set a hash to the commit info.
 */
void commit_set_hash(commit_info *info, char *hash) {
    info->_internal->hash = hash;
}

/**
 * Release the commit.
 */
void commit_destroy(commit *commit) {
    commit_info_free(commit->info);
    commit_free(commit);
}

/**
 * Print a description for the commit list.
 */
void commit_print_list(commit *head) {
    while (head != NULL) {
        commit_print(head);
        head = head->next;
    }
}

/**
 * Print a description for the commit.
 */
void commit_print(commit *commit) {
    commit_info *info = commit->info;
    if (commit_is_valid(commit)) {
        printf(fmt[0],
               info->_internal->hash,
               info->author,
               info->email,
               ctime(&(info->_internal->date)),
               info->message
               );
    }
}

/**
 * Print a debug description for the commit list.
 */
void commit_debug_print_list(commit *head) {
    while (head != NULL) {
        commit_debug_print(head);
        head = head->next;
    }
}

/**
 * Print a debug description for the commit.
 */
void commit_debug_print(commit *commit) {
    commit_info *info = commit->info;
    if (commit_is_valid(commit)) {
        printf(fmt[1],
               info->_internal->hash,
               info->author,
               info->email,
               ctime(&(info->_internal->date)),
               commit,
               commit->next,
               info->message
               );
    } else {
        printf("Head commit (%p ---> %p)\n\n", commit, commit->next);
    }
}

/**
 * Add a new commit with the info to tail of the list.
 */
commit *commit_append(commit *head, commit_info *info) {
    commit *cmit = commit_alloc();
    if (cmit == NULL) {
        return NULL;
    }
    time_t t = time(NULL);
    info->_internal->date = t;
    cmit->info = info;
    while (NULL != head->next) {
        head = head->next;
    }
    head->next = cmit;
    return cmit;
}

/**
 * Add a new commit with the info to head of the list.
 */
commit *commit_prepend(commit *head, commit_info *info) {
    commit *cmit = commit_alloc();
    if (cmit == NULL) {
        return NULL;
    }
    time_t t = time(NULL);
    info->_internal->date = t;
    cmit->info = info;
    cmit->next = head->next;
    head->next = cmit;
    return cmit;
}

commit *commit_lookup(commit *head, char *hash) {
    while (head != NULL) {
        if (strcmp(head->next->info->_internal->hash, hash) == 0) {
            return head->next;
        }
        head = head->next;
    }
    return NULL;
}

// ===

/**
 * Add a new commit with the info.
 */
commit *commit_do(commit *head, commit_info *info) {
    return commit_prepend(head, info);
}

/**
 * Checkout
 */
commit *commit_checkout(commit *head, char *hash) {
    head->next = commit_lookup(head, hash);
    return head->next;
}


