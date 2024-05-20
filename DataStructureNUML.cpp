#include <iostream>
using namespace std; 

											// Linear Search; 
int linear(int arr[], int value){ 
for (int i=0; i<=sizeof(arr) / sizeof(arr[0]); i++){ 
if (arr[i]==value){ 
return i; 
}
}
return -1; 
}

											//Binary Search 
int binary (int arr[], int size ,int value){
int left = 0; 
int right = size -1; 
while (left <= right){ 
int mid = left + (right-left)/2;
//int mid = (start+end)/2; 
if (arr[mid]==value){ 
return mid; 
}
else if(value > arr[mid])
left = mid+1; 
else if (value < arr[mid])
right = mid-1; 
}
}

///.............................Sorting.............................///

									//Selection Sort 
int SelectionSort(int arr[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        for (int j = i; j <= size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}


											//Bubble Sort
int BubbleSort(int arr[], int size)
{
	for (int i=0; i<size;i++){ 
		for (int j=0 ; j< size; j++){ 
			if (arr[j]>arr[j+1]){ 
				int temp = arr[j]; 
				arr[j]= arr[j+1]; 
				arr[j+1] = temp; 
			}
		}
	}
    
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}

											//Insertion Sort
int InsertionSort(int arr[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}

    ///////////////////////////////////////Linear Data Structures///////////////////////////////////////////////////////////
   ///                                               Linked List;                                                       ///
  ///                                               Stacks;                                                            ///
 ///                                               Queus;                                                             ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			//........................................Singly Linked List...............................................//
class node
{
public:
   int data;
   node* next;
	node(int value, node *newnode) : data(value), next(newnode){};
};

class LinkedList
{
private:
   node *head;

public:
   LinkedList() : head(NULL){};
   //Linked list Insertion at head 
   void InsertAtHead(int value){ 
   head = new node (value, head); 
   }
   
   
	//Linked list insertion Insertion At Any Position
   void insertAtAnyPosition(int value, int position)
   {
      node *temp = head;
      if (position <= 0)
      {
         head = new node(value, head);
      }
      for (int i = 0; i < position - 1 && temp->next != NULL; i++)
      {
         temp = temp->next;
      }
      if (temp == NULL || temp->next == NULL)
      {
         return;
      }
      temp->next = new node(value, temp->next);
   }
   
   
	//linked List search
   bool search(int value)
   {
      for (node *temp = head; temp != NULL; temp = temp->next)
      {
         if (temp->data == value)
         {
            return true;
         }
      }
   }
	
	
	//Linked List Display
   void Display()
   {
      for (node *temp = head; temp != NULL; temp = temp->next)
      {
         cout << temp->data << "-->";
      }
   }
   
   
   //Linked List remove from First Position
      void RemovefromFirst()
      {
         node *temp = head;
         head = temp->next;
         delete temp;
      }
      
      
	//Linked List remove From Any Position
      void RemoveAnyValue(int value)
      {
         node *temp = head;
         while (temp != NULL && temp->data == value)
         {
            head = temp->next;
            delete temp;
            temp = head;
         }
         while (temp != NULL && temp->next != NULL)
         {
            if (temp->next->data == value)
            {
               node *toDelete = temp->next;
               temp->next = temp->next->next;
               delete toDelete;
            }
            temp = temp->next;
         }
      }
      
      
	//Linked List Insert At The End
      void insertAtEnd(int value)
      {
         if (head == NULL)
         {
            return;
         }
         node *temp = head;
         while (temp->next != NULL)
         {
            temp = temp->next;
         }
         temp->next = new node(value, NULL);
      }
      
      
	//Linked List delete At the end
      void DeleteAtEnd()
      {
         if (head == NULL)
         {
            return;
         }
         if (head ->next == NULL){ 
         delete head; 
         head = NULL; 
         return; 
		 }
         node *temp = head;
         while (temp->next->next != NULL)
         {
            temp = temp->next;
         }
         delete temp->next;
		 temp->next = NULL;
      }
   };
   
   
			//..............................................Doubly...........................................//
   class node { 
public: 
int data; 
node *next; 
node *prev; 
node (int value, node*lastNode = NULL,node*newnode = NULL ): data(value), next(newnode), prev(lastNode){};  
};

class Doubly { 
  node*head; 
  node*tail; 
  public: 
  Doubly(): head(NULL), tail(NULL){}; 
  
  
  //Ading A new node To Tail: 
  void AddtoTail(int Value){ 
  node*newnode = new node (Value); 
  if (!head){ 
  tail = head = newnode; 
  }
  else { 
  tail-> next = newnode ; 
  newnode->prev = tail; 
  tail=newnode; 
  }
  }
  
  //Adding A Now Node To The Head: 
  void AddtoHead(int value){ 
  node* newnode = new node(value); 
  if (!head){ 
  head = tail = newnode;  
  }
  else { 
  head -> prev = newnode; 
  newnode -> next = head; 
  head = newnode; 
  }
  }
  
  
//Add at any position; .......(this function is dependent on AddtoHead(), AddtoTail() function)
int AddatAnyPos(int value, int position){
node *newnode = new node (value);  
node*temp= head; 
for (int i=0; i<= position-1; i++){ 
if (temp==NULL){ 
	head = tail = newnode;  	
}
temp = temp -> next; 
}
if (temp==tail){ 
 AddtoTail(value); 
}
else if (temp!=NULL){ 
newnode-> next = temp -> next; 
newnode -> prev = temp;
temp -> next = newnode;  
}
else if (temp->next != NULL){ 
temp-> next -> prev = newnode; 
} 
}


// Search in the Doubly; 
bool Search(int value){ 
for (node*temp=head; temp!=NULL; temp= temp->next ){ 
if (temp->data == value){
	return true; 
}
}
return false; 
}

// Print Start to end
void PrintSTND(){ 
node* temp= head; 
while (temp!=NULL){ 
cout<<temp->data<<"->"; 
temp = temp -> next; 
}
}

//print End to Start
void printETST(){ 
node*temp = tail; 
while (temp!=head){ 
cout<<temp->data<<"<-"; 
temp = temp->prev; 
}
}

//DELETE AT HEAD; 
void DeleteAtHead(){ 
if (!head){ 
return; 
}
node*temp = head; 
if (head->next){
 head = head -> next; 
 head->prev = NULL; 
}
else { 
head = tail = NULL; 
}
delete temp; 
return; 
}
  
  //DELETE AT TAIL
  void DeleteAtTail(){ 
  if (!head){ 
  return; 
  }
  if (head ==tail){ 
  delete head; 
  tail = head = NULL; 
  return; 
  }
  node*temp =tail; 
  tail = tail-> prev; 
  tail -> next  = NULL; 
  delete temp ; 
  }
  
  //DELTE AT ANY POSITION
  void DeleteAtAnyPos(int position){ 
  if (position<=0){ 
  return; 
  }
  node*temp = head; 
  for (int i = 0; i<= position-1; i++){
  temp = temp -> next;  
  } 
  if (!temp){ 
  return; 
  }
  else if (temp == head){ 
  head = head ->next; 
  }
  else if (temp  == tail){ 
  tail = tail->prev;  
  }
  else { 
  temp -> next ->prev = temp -> prev; 
  temp -> prev -> next = temp -> next; 
  }
  delete temp; 
} 
};
		///////...................................Circlur linked list............................/////

class node { 
	public: 
	int data; 
	node*next; 
	node (int value, node*newnode = NULL): data(value), next(newnode){}; 
};
class Clist{ 
node*head; 
public: 
Clist(): head(NULL){}; 
//INSERT AT HEAD IN CIRCULAR LINKEDLIST ;
void InsertAtHead(int value){ 
node* newnode  = new node (value);  
if(!head){ 
head = newnode; 
head->next= head; 
}
else { 
newnode -> next = head->next; 
head -> next = newnode;
head = newnode; 
}
}
//INSERT AT TAIL IN CIRCULAR LINKED LIST; 
void InsertAtTail(int value){ 
node* newnode = new node(value); 
if (!head){ 
head = newnode; 
head->next = head; 
}
else { 
node*temp= head;
while (temp->next!=head){ 
temp = temp->next; 
}
temp->next  = newnode;
newnode -> next = head;
}
}
//INSERT AT ANY POSITION
void InsertAtAnyPosition(int value,int position){ 
node*newnode = new node (value); 
if (!head){ 
head = newnode; 
head-> next = head; 
}
else {
node*temp =head;  
for (int i=0; i<position-1; i++){ 
temp = temp->next; 
}
newnode->next =temp->next;
temp->next  = newnode; 
}
}
//SEARCH IN CIRCULAR LINKED LIST
bool search (int value){ 
for (node*temp = head; temp!=head->next; temp = temp->next){ 
if (temp->data==value){ 
return true; 
}
}
return false; 
}

//Display in circular linked list
void Display() { 
    if (!head) return; 
    node* temp = head; 
    do { cout << temp->data << "->"; temp = temp->next; } while (temp != head); 
    cout << endl; 
}

//Remove at head; 
void removeAtHead(){ 
if (!head){ 
return; 
}
else if(head->next ==head){ 
delete head; 
head = NULL; 
}
else { 
node*temp= head->next; 
head->next  = temp ->next; 
delete temp; 
}
}

//Remove from tail
void removeFromTail(){ 
if (!head){ 
return; 
}
if (head->next == NULL){ 
delete head; 
head = NULL; 
return;
}
node*temp=head; 
while (temp->next->next!=head){ 
temp = temp->next; 
}
node *toDelete = temp->next; 
temp->next = head; 
delete toDelete;  
}

//Remove At Any position
void removeFromAnyPosition(int position){ 
if (!head){ 
return; 
}
else if (position==0){ 
if (head->next == head){ 
delete head; 
head = NULL; 
return; 
}
else { 
node *temp= head; 
while (temp->next != head){ 
temp = temp->next; 
}
node*toDel = head; 
head = head->next; 
temp-> next = head; 
delete toDel;
}
}
node*temp = head; 
for(int i=0; i<position-1; i++){ 
temp = temp->next; 
if (temp->next==head){ 
return; //POSITION OUT
}
}
node *toDelete = temp->next; 
temp->next = toDelete->next; 
delete toDelete; 
}
}; 

						//.............................STACKS......................................//
					   //                            USING ARRAYS                                 //
	class Stacks {
private:
    int top;
    int max =1000; 
    int arr[1000]; 
public: 
Stacks (): top(-1){}; 
void push(int value){ 
if (top == max-1){ return;}
else { 
top++; 
arr[top] = value; 
return; 
}
}
int pop(){ 
if (top == -1){return-1; }
else { 
int popval = arr[top]; 
top--; 
return popval;
}
}

bool isempty (){ return (top==-1); }
bool isFull(){ return (top == max-1); }
int peek (){ return arr[top]; }

void display() {
for (int i=0; i<=top; i++){ 
cout<<arr[i]<<endl; 
} 
}
};
                 //                             USING LinkedList                                //
    

class node { 
public: 
int data; 
node*next; 
node (int value, node*newnode = NULL): data(value), next(newnode){};  
}; 
class Stacks { 
private: 
node* top; 
public: 
Stacks ():top(NULL){}; 

~Stacks() {
        while (top != NULL) {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    
	void push(int value){ 
    node*newnode = new node (value); 
    newnode->next = top; 
    top =newnode; 
    return; 
	}
	
	int pop(){
	 if (isEmpty()){ 
	 return-1; 
	 }
	 else 
	 { 
	 node *temp = top; 
	 int popval = temp->data; 
	 top = top ->next; 
	 delete temp; 
	 return popval; 
	 }
	}
	
	bool isEmpty(){ 
	return (top==NULL); 
	}
	
	
	int peek (){ 
	if (isEmpty()){ 
	return -1; 
	}
	else { 
	return top->data;
	}
	}
	

};

					//.............................Queus......................................//

//                                                 Circular Queu                                   //

class Queue { 
private: 
int capacity = 10000; 
int rear; 
int front; 
int size ; 
int arr[10000]; 
public: 
Queue():  rear(0), front(0), size(0) {}; 

bool isEmpty(){ return size==0; }

bool isFull(){ return size == capacity; }

int peek (){ 
if (isEmpty()){ return -1;}
else{return (arr[front]);}
}


int Enqueu(int value){ 
if (isFull())
{
return -1;
 }
else { 
arr[rear] = value;
rear = (rear+1)%capacity;
size++;  
}
return 0; 
} 



int Dequeu (){ 
if (isEmpty()){
	return -1; 
}
else { 
int Deval = arr[front]; 
front = (front+1)%capacity; 
size--; 
return Deval; 
}
}


void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        int count = 0;
        while (count < size) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        cout << endl;
    }


};

//...................................................Linear Queu in Array................................................//

class Queue {
    static const int capacity = 100;
    int front;
    int rear;
    int size;
    int arr[capacity];

public:
    Queue() : front(-1), rear(-1), size(0) {}

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
    
    int enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return -1;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        size++;
        return 0;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int dequeueValue = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
        size--;
        return dequeueValue;
    }
	int peek() {
        if (isEmpty()|| front>rear) {
            return -1;
        }
        else {
            return arr[front];
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

//..........................................................Queu using Linked List,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,//
class node { 
public: 
int data; 
node*next; 
node(int value, node*newnode):data(value), next(newnode){}; 
};

class queue{ 
node*top; 
public:
queue():top(NULL){}; 

void Enqueu(int value){ 
top = new node (value, top); 
}



int Dequeu(){ 
if (top == NULL){ 
return-1;
}
else { 
node* toDeq = top; 
top = top-> next; 
delete toDeq; 
}
 }
 
bool isEmpty(){ 
return (top== NULL); 
}

void Display(){ 
for (node*temp = top; top!=NULL; top = top->next){ 
cout<<temp->data<<" "; 
}
}
};
