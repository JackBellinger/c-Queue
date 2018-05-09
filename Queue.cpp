#include "Queue.h"
#include "Student.h"
#include <iostream>
using namespace std;

/*QueNode<T>* front;
QueNode<T>* back;
int queSize;
int queCount;*/
template <class T>
Queue<T>::Queue(int size)
{
	queSize = size;
}

template <class T>
Queue<T>::~Queue()
{
	if(front == NULL)
        cout << "Queue is empty" << endl;
    else
    {
        QueNode<T>* temp = front;
        QueNode<T>* deleter = temp;
        while(temp != NULL)//go until it finds null, we past the last node
        {
            deleter = temp;
            temp = temp->next;//move temp down the stack
            delete deleter;   //delete the node we passed
        }
        
    }
}

template <class T>
void Queue<T>::enQ(const T d)
{
	if(!isFull())
    {
	cout<<"Pushing" << endl;
        QueNode<T>* newNode= new QueNode<T>();
        newNode->data = d;
		if(front == NULL)
			front = newNode;
		if(back == NULL)
			back = newNode;
		else
		{
			back->next = newNode;
			back = newNode;
		}
        queCount++;
    }else
        cout << "Queue is full" << endl;
    cout<<"pushed" << endl;
}

template <class T>
T Queue<T>::deQ()
{
	if(!isEmpty())
    {
        //cout << "pop" << endl;
        QueNode<T>* deleter = front;
        front = front->next;
        delete deleter;
        queCount--;
    }else
        cout << "Queue is empty" << endl;
}

template <class T>
T Queue<T>::topQ() const
//returns the first element in the Queue<T>
{
	if(front != NULL)
	{
		cout << front->data << endl;
    	return front->data;
	}
	else
		cout << "Empty queue" << endl;
	return T();
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return queCount <= 0;
}

template <class T>
bool Queue<T>::isFull() const
{
	return queCount >= queSize;
}
