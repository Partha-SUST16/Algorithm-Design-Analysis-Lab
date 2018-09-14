#include <bits/stdc++.h>
#define sz 20
using namespace std;

struct Data
{
    int data;
    int key;
};

struct Data* dataList[sz][sz];
struct Data* singleItem;
struct Data* item;

int getHashCode(int key)
{
    return key%sz;
}

struct Data *search_(int key)
{
    int hashIndex = getHashCode(key);

    int i = 0;
    while(dataList[hashIndex][i]!=NULL)
    {
        if(dataList[hashIndex][i]->key == key)
            return dataList[hashIndex][i];
        ++i;
        i%=sz;
    }
    return NULL;
}

void insert_(int key,int data)
{
    struct Data *item = (struct Data*)malloc(sizeof(struct Data));
    item -> data = data;
    item->key = key;

    int hashIndex = getHashCode(key);
    int i = 0;
    while(dataList[hashIndex][i]!=NULL and dataList[hashIndex][i]->key!=-1)
    {
        ++i;
        i%=sz;
    }
    dataList[hashIndex][i] = item;
}

struct Data* del(struct Data* item)
{

    int key = item->key;
    int hashIndex = getHashCode(key);
    int i = 0;
    while(dataList[hashIndex][i]!=NULL)
    {
        if(dataList[hashIndex][i]->key==key)
        {
            struct Data* temp = dataList[hashIndex][i];
            dataList[hashIndex][i] = singleItem;
            return temp;
        }
        ++i;
        i%=sz;
    }
    return NULL;
}

void display()
{
    int i = 0;
    for(i = 0; i<sz; i++)
    {
        for(int j=0; j<sz; j++)
            if(dataList[i][j] != NULL)
            {
                printf(" (%d,%d) ",dataList[i][j]->key,dataList[i][j]->data);
            }
            else
                printf(" ~~ ");
        printf("\n");
    }
}
int main()
{
    singleItem = (struct Data*)malloc(sizeof(struct Data));
    singleItem->data= -1;
    singleItem->key = -1;

    insert_(1,20);
    insert_(2,70);
    insert_(42,80);
    insert_(4,25);
    insert_(12,44);
    insert_(14,32);
    insert_(17,11);
    insert_(13,78);
    insert_(37,97);

    display();

    item = search_(37);
    if(item!=NULL)
        printf("Element Found: %d\n",item->data);
    else
        printf("Not found\n");

    del(item);
//    display();
    item = search_(37);
    if(item!=NULL)
        printf("Element Found: %d\n",item->data);
    else
        printf("Not found\n");
    return 0;
}

