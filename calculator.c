#include "compare_size.h"
#include <stdio.h>

// 각각의 자릿수를 나타내는 노드
typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} node;

// 맨 왼쪽, 오른쪽 자릿수와 정수부 또는 실수부의 길이를 나타내는 큐
typedef struct {
    node *leftMost;
    node *rightMost;
    int size;
} queue;

// 정수부와 실수부를 포함하는 무한소수 구조체
typedef struct {
    queue *integer;
    queue *decimal;
} infDec;

// infDec add(infDec *a, infDec *b)
// {
//     queue *a_int = a->integer, *b_int = b->integer,
//           *a_dec = a->decimal, *b_dec = b->decimal,
//           *res_int, *res_dec;

//     node *a_int_tmp = a_int->rightMost, *b_int_tmp = b_int->rightMost,
//          *res_int_tmp = res_int->rightMost;

//     for (int cnt = 0; cnt < min(a_int->size, b_int->size); cnt++) {
//         res_int_tmp->value += a_int_tmp->value + b_int_tmp->value;
//         if (res_int_tmp->value >= 10) {
//             res_int_tmp->value -= 10;
//             res_int_tmp->left->value += 1;
//         }
//     }
//     infDec res_infDec = {res_int, res_dec};
//     return res_infDec;
// }

void printNode(node *n)
{
    printf("This node's value is %d.\n", n->value);
    printf("Left: %d, Right: %d.\n", n->left->value, n->right->value);
}

void printQueue(queue *q)
{
    printf("This queue is from %d to %d.\n", q->leftMost, q->rightMost);
    printf("It has %d nodes.\n", q->size);
}

queue addInt(queue *a, queue *b)
{
    queue res;

    node *a_tmp = a->rightMost, *b_tmp = b->rightMost,
         *res_tmp = (&res)->rightMost;

    printNode(a_tmp);
    printNode(b_tmp);
    printNode(res_tmp);

    for (int cnt = 0; cnt < min(a->size, b->size); cnt++) {
        res_tmp->value += a_tmp->value + b_tmp->value;
        printf("%d", res_tmp->value);
        if (res_tmp->value >= 10) {
            res_tmp->value -= 10;
            res_tmp->left->value += 1;
        }
    }
    return res;
}

void printInfiniteDecimal(infDec *infDec)
{
    node *intTmp = infDec->integer->leftMost;
    for (int i = 0; i < infDec->integer->size; i++) {
        printf("%d", intTmp->value);
        intTmp = intTmp->right;
    }
    
    printf(".");

    node *decTmp = infDec->decimal->leftMost;
    for (int i = 0; i < infDec->decimal->size; i++) {
        printf("%d", decTmp->value);
        decTmp = decTmp -> right;
    }
    
}

int main(void)
{
    node dummyNode = {NULL, NULL, -1};

    node a1 = {.left = &dummyNode, .right = &dummyNode, .value = 1};
    node a2 = {.left = &a1, .right = &dummyNode, .value = 2};
    a1.right = &a2;
    queue qa = {.leftMost = &a1, .rightMost = &a2, .size = 2};
    // infDec a = {.integer = &qa, .decimal = NULL};

    node b1 = {.left = &dummyNode, .right = &dummyNode, .value = 1};
    node b2 = {.left = &b1, .right = &dummyNode, .value = 2};
    b1.right = &b2;
    node b3 = {.left = &b2, .right = &dummyNode, .value = 3};
    b3.right = &b2;
    queue qb = {.leftMost = &b1, .rightMost = &b3};
    // infDec b = {.integer = &qb, .decimal = NULL};

    queue result = addInt(&qa, &qb);
    infDec c = {.integer = &result, .decimal = NULL};
    printInfiniteDecimal(&c);
}