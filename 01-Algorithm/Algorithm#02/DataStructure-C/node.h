// node.h
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

#ifndef _ALGORITHM_02_NODE_H_
#define _ALGORITHM_02_NODE_H_

typedef struct node_tag {
    int data;
    struct node_tag *next;
} node_t;

void node_append_to_tail(node_t *head, int data);
void node_append_to_head(node_t *head, int data);


/* ------------------------------ */
node_t *node_create();
void node_destroy(node_t *);
/* ------------------------------ */

// リストの末尾に追加する
void node_append(node_t *, int);

// リストの先頭に追加する
void node_prepend(node_t *, int);

// リストのデータを検索してそれを返却する
node_t *node_lookup(node_t *, int);

// リストのデータを削除する
void node_delete(node_t *, int);

// リストのデータを挿入する
void node_insert(node_t *, int, int);

#endif
