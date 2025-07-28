#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeLichThi {
    char tenMon[50];
    char ngayThi[20];
    struct NodeLichThi* prev;
    struct NodeLichThi* next;
} NodeLichThi;

