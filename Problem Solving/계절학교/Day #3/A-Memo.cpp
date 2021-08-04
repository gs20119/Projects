
#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *next;
    struct Node *prev;
    string data;
};

int main()
{
    struct Node *head = new Node;
    struct Node *tail = new Node;
    struct Node *curr = new Node;
    int N; cin >> N;
    
    head->next = tail; tail->prev = head; 
    curr = head;
    
    while(N--){
        int i; string X;
        cin >> i; if(i==3) cin >> X;
        if(i==1) if(curr!=head) curr = curr->prev;
        if(i==2) if(curr->next!=tail) curr = curr->next;
        if(i==3){
            struct Node *New = new Node; 
            New->data = X; New->prev = curr; New->next = curr->next;
            curr->next->prev = New;
            curr->next = New; curr = curr->next;
        }if(i==4) if(curr!=head){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr = curr->prev;
        }
    }
    
    curr = head->next;
    while(curr!=tail){
        cout << curr->data;
        curr = curr->next;
    }
    
}
