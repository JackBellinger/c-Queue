#ifndef Queue_H
#define Queue_H

template <class T>
struct QueNode
{
	T data;
	QueNode<T>* next;
};

template <class T>
class Queue
{
private:
	QueNode<T>* front;
	QueNode<T>* back;
	int queSize;
	int queCount;
public:
	Queue<T>(int = 10);
	~Queue<T>();
	void enQ(const T);
	T deQ();
	T topQ() const; //returns the first element in the Queue<T>
	bool isEmpty() const;
	bool isFull() const;
};

#endif
