//
//  main.c
//  CommitStructure-C
//
//  Created by Shintaro Kaneko on 12/7/14.
//  Copyright (c) 2014 Shintaro Kaneko. All rights reserved.
//

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
