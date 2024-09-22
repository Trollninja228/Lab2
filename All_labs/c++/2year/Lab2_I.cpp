#include <iostream>
#include <string>
using namespace std;
class Node{
public:
	string value;
	Node *Next;
};

Node* add_front(Node *n, string s, Node *list){
	Node *book=new Node();
    book->value=s;
    book->Next=n;
    Node* end_of_list=list;
    while(end_of_list->Next!=NULL){
        end_of_list=end_of_list->Next;
    }
    end_of_list->Next=new Node();
    Node* new_element=end_of_list->Next;
    new_element->value="ok";
    return book;
}
void add_back(Node* n, string s, Node *list){
    Node* book=new Node();
    Node* end=n;
    while(end->Next!=NULL){
        end=end->Next;
    }
    end->Next=book;
    book->value=s;
    Node* end_of_list=list;
    while(end_of_list->Next!=NULL){
        end_of_list=end_of_list->Next;
    }
    end_of_list->Next=new Node();
    Node* new_element=end_of_list->Next;
    new_element->value="ok";
}
Node* erase_front(Node* n, Node *list){
    if(n->value==""){
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value="error";
    }else{
        Node* n_head=n->Next;
        n->Next=NULL;
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value="ok";
        return n_head;
    }
    
}
Node* erase_back(Node* n, Node *list){
    if(n->value==""){
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value="error";
        return n;
    }else{
        Node* end=n;
        while(end->Next->Next!=NULL){
            end=end->Next;
        }
        end->Next->Next=NULL;
        end->Next=NULL;
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value="ok";
    }
} 
Node* front(Node* n, Node *list){
    if(n->value==""){
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value="error";
        return n;
    }else{
        Node* end=n;
        while(end->Next!=NULL){
            end=end->Next;
        }
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value=n->value;
    }
}
Node* back(Node* n, Node *list){
    if(n->value==""){
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value="error";
        return n;
    }else{
        Node* end=n;
        while(end->Next!=NULL){
            end=end->Next;
        }
        Node* end_of_list=list;
        while(end_of_list->Next!=NULL){
            end_of_list=end_of_list->Next;
        }
        end_of_list->Next=new Node();
        Node* new_element=end_of_list->Next;
        new_element->value=end->value;
    }
    
}
Node* clear(Node *n, Node *list){
    Node* newhead=new Node();
    Node* end_of_list=list;
    while(end_of_list->Next!=NULL){
        end_of_list=end_of_list->Next;
    }
    end_of_list->Next=new Node();
    Node* new_element=end_of_list->Next;
    new_element->value="error";
    return newhead; 
}
int main(){
    Node *head=new Node();
    Node *list=new Node();
    head->Next=NULL;
    string s,s1;
    while(1){
        cin>>s;
        if(s=="exit"){
            list->Next=new Node();
            Node* end=list->Next;
            while(end->Next!=NULL){
                cout<<end->value<<endl;
                end=end->Next;
            }
            cout<<"goodbye";
            return 0;
        }
        if(s=="add_front"){
            cin>>s1;
            head=add_front(head,s1, list);
        }
        if(s=="add_back"){
            cin>>s1;
            add_back(head,s1, list);
        }
        if(s=="erase_front"){
            head=erase_front(head, list);
        }
        if(s=="erase_back"){
            erase_back(head, list);
        }
        if(s=="front"){
            front(head, list);
        }
        if(s=="back"){
            back(head, list);
        }
        if(s=="clear"){
            head=clear(head, list);
        }
        
    }
}
