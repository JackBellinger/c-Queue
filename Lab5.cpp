#include <iostream>
#include "Queue.h"
#include "Student.h"
using namespace std;

int menu()
{
    int response = 0;
    
    cout << "Menu:" << endl;
    cout << "1. enQueue()" << endl;
    cout << "2. deQueue()" << endl;
    cout << "3. topQueue()" << endl;
    cout << "4. quit" << endl;
    cout << "Please input the option you would like: ";
    cin >> response;
    cout << "---------------------------------------" << endl;
    return response;
}
template <class T>
bool validateInput(int response, Queue<T>* queue, bool clearScreen)
/* returns a bool determining if the program should quit or not, 
 * true if the program should quit
*/
{
    bool quit = false;
    if(response >= 1 && response <= 5)
    {
        switch(response)
        {
            case 1:
            {
				cout << "new data" << endl;
                T* x = new T();
                addObj(queue, x);
                cout << (clearScreen?string(100, '\n'):"");
                break;
            }
            case 2:
            {
                cout << (clearScreen?string(100, '\n'):"");
                queue->deQ();
                break;
            }
            case 3:
            {
                cout << (clearScreen?string(100, '\n'):"");
               	queue->topQ();
                break;
            }
            case 4:
            {
                cout << "back";
                quit = true;
                break;
            }
            
        }//end switch
    }
    else
	{
        cout << (clearScreen?string(100, '\n'):"");
		cout << "Please enter a valid integer" << endl << endl;
	}
      return quit;          
}
void addObj(Queue<int>* queue, int* x)
{
    cout << "What would you like to add? : ";
    cin >> *x;
    queue->enQ(*x);
}

void addObj(Queue<Student>*& queue, Student*& x)
{
    cout << "adding" << endl;
    queue->enQ(*x);
}

int main()
{
    Queue<int>* iQueue = new Queue<int>();
    Queue<Student>* sQueue = new Queue<Student>();
    
    cout << "Choose a Queue type" << endl << "0. Student" << endl << "1. Integer" << endl;
    bool isIQueue = 0;
    cin >> isIQueue;
    cout << "Clear screen?" << endl;
	bool clear = true;
	cin >> clear;
    cout << (clear?string(100, '\n'):"");
    bool quit = false;
    while(!quit)//menu asks for which option, which returns the choice into validateInput, which returns if the program should quit
    {
        if(isIQueue)
            quit = validateInput(menu(), iQueue, clear);
        else
            quit = validateInput(menu(), sQueue, clear);
        //Queue->printQueue();
    }
    return 0;
}

