#include <bits/stdc++.h>
#define sz 20
using namespace std;

struct three{
    string s;
    int a,b;
    three(){}

    three(string ss,int aa,int bb){
        s = ss;
        a = aa;
        b = bb;
    }
};
struct Data
{
    three data;
    int key;
};

struct Data* dataList[sz];
struct Data* singleItem;
struct Data* item;

int getHashCode(int key)
{
    return key%sz;
}

struct Data *search_(int key)
{
    int hashIndex = getHashCode(key);


    while(dataList[hashIndex]!=NULL)
    {
        if(dataList[hashIndex]->key == key)
            return dataList[hashIndex];
        ++hashIndex;
        hashIndex%=sz;
    }
    return NULL;
}

void insert_(int key,three data)
{
    struct Data *item = (struct Data*)malloc(sizeof(struct Data));
    item -> data = data;
    item->key = key;

    int hashIndex = getHashCode(key);

    while(dataList[hashIndex]!=NULL and dataList[hashIndex]->key!=-1)
    {
        ++hashIndex;
        hashIndex%=sz;
    }
    dataList[hashIndex] = item;
}

struct Data* del(struct Data* item)
{

    int key = item->key;
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex]!=NULL)
    {
        if(dataList[hashIndex]->key==key)
        {
            struct Data* temp = dataList[hashIndex];
            dataList[hashIndex] = singleItem;
            return temp;
        }
        ++hashIndex;
        hashIndex%=sz;
    }
    return NULL;
}

void display()
{
    int i = 0;
    for(i = 0; i<sz; i++)
    {
        if(dataList[i] != NULL)
        {
            cout<<" ("<<dataList[i]->key<<","<<dataList[i]->data.s<<","<<dataList[i]->data.a<<","<<dataList[i]->data.b<<" )"<<endl;
        }
        else
            printf(" ~~~~ \n");
    }
}
int main()
{

    singleItem = (struct Data*)malloc(sizeof(struct Data));

    singleItem->data.a= -1;
//    cout<<"HI\n";
    singleItem->data.b=-1;
//    cout<<"HI\n";
//    singleItem->data.s ;
//    cout<<"HI\n";
    singleItem->key = -1;


    insert_(1,three("hi",20,10));
    insert_(2,three("hello",30,40));
    insert_(42,three("what",70,50));
    insert_(4,three("are",80,17));
    insert_(12,three("these",54,71));
    insert_(14,three("why",53,5));
    insert_(17,three("this",71,23));
    insert_(13,three("man",57,101));
    insert_(37,three("le",27,1001));

    display();

    item = search_(37);
    if(item!=NULL)
        printf("Element Found: "),cout<<item->data.a <<","<<item->data.b<<","<<item->data.s<<endl;
    else
        printf("Not found\n");

    del(item);
//    display();
    item = search_(37);
    if(item!=NULL)
        printf("Element Found: "),cout<<item->data.a <<","<<item->data.b<<","<<item->data.s<<endl;
    else
        printf("Not found\n");
    return 0;
}


