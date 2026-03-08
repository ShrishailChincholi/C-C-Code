#include <stdio.h>

struct employee
{
    int id;
    char name[30];
    float basic, hra, da, total;
};


void calculate(struct employee *e)
{
    e->hra = 0.20 * e->basic;
    e->da = 0.10 * e->basic;
    e->total = e->basic + e->hra + e->da;
}