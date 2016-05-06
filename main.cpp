
//delete a node at nth position
//(1) Fix the links
//(2) Free the space

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head; //global variable

//---------- INSERT ----------//
//insert the vale at the end of the list
void Insert(int data){
    Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

//---------- DISPLAY ----------//
//print all the elements
void Display(){
    struct Node* temp = head; //collect the address stored in head
    cout << "List: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//---------- DELETE ----------//
//delete node at position n
void Delete(int n){
    struct Node* temp1 = head;
    int i;
    if(n == 1){
        head = temp1->next; //head now points to 2nd Node
        free(temp1);
        return;
    }
    for(i = 0; i < n-2; i++)
        temp1 = temp1->next; //temp1 points to (n-1)th Node
    struct Node* temp2 = temp1->next; //nth Node
    temp1->next = temp2->next; //(n+1)th Node
    free(temp2); //delete temp2;
}


int main() {
    
    head = NULL; //empty list
    Insert(2); //list: 2
    Insert(4); //list: 2 4
    Insert(6); //list: 2 4 6
    Insert(5); //list: 2 4 6 5
    Display();
    
    int n;
    cout << "Delete a node at: " << endl;
    cin >> n;
    Delete(n);
    Display();
}
