// node.c
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

#include "node.h"

#include <stdlib.h>

node_t *node_create() {
    node_t *n = malloc(sizeof(node_t));
    return n;
}

void node_destroy(node_t *nd) {
    if (nd != NULL) {
        free(nd);
        nd = NULL;
    }
}

// リストの末尾に追加する
void node_append(node_t *nd, int dt) {
    node_t *n = node_create();
    n->data = dt;
    while (nd->next != NULL) {
        nd = nd->next;
    }
    nd->next = n;
}

// リストの先頭に追加する
void node_prepend(node_t *nd, int dt) {
    node_t *n = node_create();
    n->data = dt;
    n->next = nd->next;
    nd->next = n;
}

// リストのデータを検索してそれを返却する
node_t *node_lookup(node_t *nd, int dt) {
    while (nd != NULL && nd->data != dt) {
        nd = nd->next;
    }
    return nd;
}

// リストのデータを削除する
void node_delete(node_t *nd, int idx) {

}

// リストのデータを挿入する
void node_insert(node_t *nd, int idx, int dt) {
    int i;
    node_t *n;
    n->data = dt;
    for (i = 0; i < idx && nd != NULL; i++) {
        nd = nd->next;
    }
    if (nd != NULL) {
        n->next = nd->next;
        nd->next = n;
    }
}
