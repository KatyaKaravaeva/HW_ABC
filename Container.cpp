//
// Created by kikin on 10.10.2021.
//

#include "container.h"
//------------------------------------------------------------------------------
// Initialising the container.
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Clearing a container of items (freeing up memory).
void Clear(container &c) {
    delete[] *c.cont;
    c.len = 0;
}

//------------------------------------------------------------------------------
// Inputting container contents from a specified stream.
void In(container &c, std::ifstream &stream) {
    while (!stream.eof()) {
        if ((c.cont[c.len] = In(stream)) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Random entry of container contents.
void InRandom(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRandom()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Output the container contents to the specified stream.
void Out(container &c, std::ofstream &stream) {
    stream << "Container contains " << c.len << " elements." << std::endl;
    for (int i = 0; i < c.len; i++) {
        stream << i << ": ";
        Out(*(c.cont[i]), stream);
    }
}

//------------------------------------------------------------------------------
// Sorting (Straight Merge).
void Sort(container &c, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        Sort(c, l, m);
        Sort(c, m+1, r);
        Merge(c, l, m, r);
    }
}
//------------------------------------------------------------------------------
// An auxiliary method for sorting.
void Merge(container &c, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    animal* L = new animal[n1];
    animal* R = new animal[n2];
    for (i = 0; i < n1; i++)
        L[i] = *(c.cont[l + i]);
    for (j = 0; j < n2; j++)
        R[j] = *(c.cont[m + 1 + j]);
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (Quotient(L[i]) >= Quotient(R[j]))
        {
            c.cont[k] = &(L[i]);
            i++;
        }
        else
        {
            c.cont[k] = &(R[j]);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        c.cont[k] = &(L[i]);
        i++;
        k++;
    }
    while (j < n2)
    {
        c.cont[k] = &(R[j]);
        j++;
        k++;
    }
}