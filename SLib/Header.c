#include "Header.h"
#include <stddef.h> // Zbog NULL - UNDECLARED


Queue * initQueue()
{

	Queue *a = (Queue*)malloc(sizeof(Queue));
	if (a == NULL)
	{
		return NULL;
	}
	a->rear = NULL;
	a->front = NULL;
	return a;
}


Node *initNode(int data, Node *prev)
{

	Node *a = (Node*)malloc(sizeof(Node));
	if (a == NULL)
	{
		return NULL;
	}
	a->data = data;
	a->next = NULL;
	a->prev = prev;
	return a;
}

void enqueue(Queue *a, int data)
{
	Node *node = initNode(data, a->front);
	if (a->rear == NULL)
	{
		a->rear = node;
		a->size = 1;
	}
	else
	{
		a->front->next = node;
		a->size = a->size + 1;
	}
	a->front = node;
}

int isEmpty(Queue *a)
{
	if (a->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int dequeue(Queue *a)
{
	if (isEmpty(a) == 1)
	{

		return 0;
	}
	else
	{
		int data = a->front->data;
		if (a->rear == a->front)
		{

			a->front = NULL;
			a->rear = NULL;
		}
		else
		{
			a->front = a->front->prev;
			a->front->next = NULL;
			free(a->front->next);
		}

		a->size--;

		return data;
	}
}

void dequeueALL(Queue * a)
    {
        if (isEmpty(a) == 1)
            {
                printf("Queue is empty - you can't remove elements");
            }
        else{
            while(a->size!=0){
                dequeue(a);
            }
        }

    }

void deleteQ(Queue *a){
        dequeueALL(a);
        free(a);
    }

void printALL(Queue *a)
{
	Node *node = a->rear;
	printf("Queue elements: \n");
	while (node != NULL)
	{
		printf("%d\n", node->data);
		node = node->next;
	}

	printf("\n");
}

int isFull(Queue *a){

        Node * node = a->rear;
        int cnt;
        if(isEmpty(a)==1){
            return 0;
        }
        else{
            while(node!=NULL){
                node = node->next;
                cnt++;
            }
            if(cnt==a->size){
                return 1;
            }
            else{
                return 0;
            }
        }
    }




    /*struct Queue *initializeQ(){
		struct Queue *a=(struct Queue*)malloc(sizeof(struct Queue) );
			if (a == NULL)
			{
				return NULL;
			}
			a->rear = NULL;
			a->front = NULL;
			a->size=0;
			return a;
	}




    Node *initializeN(int data, Node * prev)
	{

		Node *a = (Node*)malloc(sizeof(Node));
		if (a == NULL)
		{
			// Failed to create memory
			return NULL;
		}
		else{
		a->data = data;
		a->next = NULL;
		a->prev = prev;
		}
		return a;
	}



    void enqueue(Queue *a, int data)
	{
		// Create a new node
		Node* node = initializeN(data, a->front);
		if (a->rear == NULL)
		{
			// When adding a first node of queue
			a->rear = node;
			a->size = 1;
		}
		else
		{
			a->rear->next = node;
			a->size = a->size + 1;
		}
		a->rear = node;
	}

	int isEmpty(Queue *a)
		{
			if (a->size == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

    void dequeue(Queue * a)
    {
        if (isEmpty(a) == 1)
            {
                // When queue is empty
                printf("Queue is empty - you can't remove elements");
            }
        else
            {
                //int data = a->rear->data; // Uzmi vrijednost sa prednjeg Queue-a i spremi ju pod varijablu data
                Node * temp = a->rear; // Inicijaliziraj novi èvor koji je jednak a->rear-u
                if (a->rear == a->front) // Ako su null to znaci da QUEUE ima samo jedan NODE unutra
                {
                    a->front=NULL;
                    a->rear=NULL;
                }
                else
                {
                    a->rear = a->rear->next;
                    a->rear->prev = NULL;
                    ////a->front->next=a->rear->prev;
                    ////a->rear->prev = NULL;
                    //
                    //a->rear=a->rear->prev;
                    //a->rear->next = NULL;
                    free(a->rear->next);// JEL IDE FREE OVDJE? Ja mislim da da jer ce se koristiti u iducim funkcijama za brisanje
                }
                // Change queue size
                a->size--;
            }
    }

    void dequeueALL(Queue * a)
    {
        if (isEmpty(a) == 1)
            {
                // When queue is empty
                printf("Queue is empty - you can't remove elements");
            }
        else{
            while(a->size!=0){
                dequeue(a);
            }
        }


    }

    void deleteQ(Queue *a){
        dequeueALL(a);
        free(a);
    }

    void printdata(Queue * a)
        {
            Node * node = a->rear;
            printf("Element\n:");
            while (node != NULL)
            {
                printf(" %d\n", node->data);
                node = node->next;
            }
            printf("\n");
        }



    int isFull(Queue *a){

        Node * node = a->rear;
        int cnt;
        if(isEmpty(a)==1){
            return 0;
        }
        else{
            while(node!=NULL){
                node = node->next;
                cnt++;
            }
            if(cnt==a->size){
                return 1;
            }
            else{
                return 0;
            }
        }
    } */
