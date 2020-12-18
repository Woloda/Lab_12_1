#include <iostream>

using namespace std;

void p_create();
void p_delete();

struct Data
{
	Data* link1,
		* link2;
	int inform;
};

Data* p;

int main(void)
{	
	p_create();
	p_delete();

	return 0;
}

void p_create()
{
	p = new Data;                       //1
	p->inform = 1;                      //2
	p->link1 = new Data;                //3
	p->link1->inform = 2;               //4
	p->link1->link2 = p;                //5
	p->link1->link1 = new Data;         //6
	p->link1->link1->inform = 3;        //7
	p->link1->link1->link2 = p->link1;  //8
	p->link2 = new Data;                //9
	p->link2->inform = 4;               //10
	p->link2->link1 = p;                //11
	p->link2->link2 = p->link1->link1;  //12
	p->link1->link1->link1 = p->link2;  //13
}

void p_delete()
{
	delete p->link2;                    //14
	delete p->link1->link1;             //15
	delete p->link1;                    //16
	delete p;                           //17
}