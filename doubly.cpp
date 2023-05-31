#include <iostream>
using namespace std;

struct Node{
    float gpa;
    Node*next = nullptr;
    Node* prev = nullptr;
};

Node* first  = nullptr;
Node* last = nullptr;

void insert_end(){
    Node* p = new Node;
    cout<<"enter the gpa: "<<endl;
    cin>>p->gpa;
    if(first==nullptr){
        first = last = p;
    }else{
        last->next = p;
        p->prev = last;
        last=p;
    }
}

void create_list(){
    char check ='n';
    do{
        insert_end();
        cout<<"do you want to enter again: "<<endl;
        cin>>check;
    }while(check=='y' || check=='Y');
}

void display(){
    if(first==nullptr){
        cout<<"the list is empty"<<endl;
    }else{
        Node *p = first;
        while(p!=nullptr){
            cout<<p->gpa<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}

void insert_start(){
    Node* p= new Node;
    cout<<"enter the gpa: "<<endl;
    cin>>p->gpa;
    if(first==nullptr){
        first=last=p;
    }else{
        p->next = first;
        first->prev = p;
        first=p;
    }
}
void insert_before(float key){
    if(first==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;
    }else{
        Node*q=nullptr;
        Node* p=first;

        while(p!=nullptr && p->gpa!=key){
            q=p;
            p=p->next;
        }
        if(p!=nullptr){
            Node* temp = new Node;
            cout<<"enter the gpa: "<<endl;
            cin>>temp->gpa;
            if(key==first->gpa){
                temp->next=p;
                p->prev = temp;
                first=temp;
            }else{
                temp->next = p;
                temp->prev = q;
                q->next = temp;
                p->prev=temp;
            }
            cout<<"element inserted!"<<endl;
        }else{
            cout<<"element not found in the list"<<endl;
        }
    }
}
void insert_after(float key){
    if(first==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;

    }else{
        Node *q = first;
        Node *p= q->next;
        while(p!=nullptr && q->gpa!=key){
            q=p;
            p=p->next;
        }
        if(q->gpa==key){
            Node *temp = new Node;
            cout<<"enter the gpa: "<<endl;
            cin>>temp->gpa;
            if(q==last){
                temp->next=p;
                temp->prev=q;
                q->next=temp;
                last=temp;
            }else{
                temp->next = p;
            temp->prev = q;
            q->next = temp;
            p->prev=temp;
            }
            cout<<"element inserted!"<<endl;
        }else{
            cout<<"element not found in the list"<<endl;
        }
    }
}

void search_specific(float key){
    int i=1;
    Node* q= first;
    while(q!=nullptr && q->gpa !=key){
        q=q->next;
        i+=1;
    }
    if(q!=nullptr){
        cout<<"the key is at"<<i<<"th position"<<endl;
    }else{
        cout<<"key not found in the list"<<endl;
    }
}

void search_before(float key){
    Node *p = first;
    Node *q = nullptr;
    if(first==nullptr || first->gpa==key){
        cout<<"unable to iterate through list"<<endl;
    }else{
        

        while(p!=nullptr && p->gpa !=key){
            q=p;
            p=p->next;
        }
        if(p!=nullptr){
            cout<<"the element before "<<key<<"is "<<q->gpa<<endl;
        }else{
            cout<<"key not found!"<<endl;
        }
    }
}
void search_after(float key){
    if(first==nullptr){
        cout<<"the list is empty, cant find the key"<<endl;
    }else{
        Node *q=first;
        
        while(q!=nullptr && q->gpa !=key){
           q=q->next;
        }
        if(q!=nullptr){
            if(q!=last){
                cout<<"the element after key is: "<<q->next->gpa<<endl;
            }else{
                cout<<"there is no element after the key!"<<endl;
            }
        }else{
            cout<<"key not found!"<<endl;
        }
    }
}

void delete_node(){
    if(first==nullptr){
        cout<<"list is already empty"<<endl;
    }else{
        Node* q=nullptr;
        Node *p = first;

        if(p->next==nullptr){
            first = last = nullptr;
        }else{
            while(p->next!=nullptr){
            q=p;
            p=p->next;
        }
        q->next = nullptr;
        last=q;

        }

        delete p;
        
        
    }
}

void delete_list(){
    while(first!=nullptr){
        delete_node();
    }
}

void delete_specific(float key){
    if(first==nullptr){
        cout<<"list is empty, cant perform deletion"<<endl;
    }else{
        Node*p = first;
        Node *q = nullptr;
        while(p!=nullptr && p->gpa !=key){
            q=p;
            p=p->next;
        }
        if(p==nullptr){
            cout<<"couldnt find the key t delete"<<endl;
        }else{
            if(p==first &&p==last){
                first=last=nullptr;
            }else
            if(p==last){
                q->next=nullptr;
                last=q;
            }else if(p==first){
                {
                    p->next->prev=nullptr;
                    first=p->next;
                }
                
            }
            else{
                q->next = p->next;
                p->next->prev = q;
            }

            delete p;
            cout<<"element deleted"<<endl;
        }
    }
}

void delete_before(float key){
    Node *p = first;
    Node * q=nullptr;
    if(first==nullptr || p->gpa==key){
        cout<<"cannot perform deletion here!"<<endl;
    }else{
        while(p!=nullptr && p->gpa!=key){
            q=p;
            p=p->next;
        }
        if(p!=nullptr){
            if(q==first){
                p->prev=nullptr;
                first=p;
                delete q;
            }else{
                p->prev = q->prev;
                q->prev->next = p;
                delete q;
            }
            cout<<"element deleted"<<endl;
        }else{
            cout<<"element not found"<<endl;
        }
    }
}

void delete_after(float key){
    Node* p=first;
    Node * q=first;
    if(first==nullptr || p==last){
        cout<<"cannot perform deletion"<<endl;
    }else{
        while(p!=last && q->gpa!=key){
            q=p;
            p=p->next;
        }
        if(q->gpa==key){
            if(p==last){
            q->next=nullptr;
            last=q;
            delete p;
        }else{
            q->next = p->next;
            p->next->prev = q;
            delete p;
        }
        cout<<"element deleted"<<endl;
        }else{
            cout<<"element not found or element is not there after the key"<<endl;
        }
    }
}

int main(){
     int menu_input=0;
    float element; float key;
    int insert_menu_input;

   do{
     cout<<"MENU"<<endl;
     cout<<"1. creating a linked list "<<endl;
     cout<<"2. Insert element in the list"<<endl;
     cout<<"3. Search element in list"<<endl;
     cout<<"4. Delete element in the list"<<endl;
     cout<<"5. Display the list"<<endl;
     
     cout<<"0. exit the program"<<endl;
     cout<<"enter a number to continue: "<<endl;
     cin>>menu_input;
     switch(menu_input){
        case 1: 
            create_list();
            break;
        case 2:
            
            cout<<"1. insert element at start of the list"<<endl;
            cout<<"2. Insert at the end of list"<<endl;
            cout<<"3. Insert after specific element"<<endl;
            cout<<"4. Insert before specific element"<<endl;
            cout<<"0. Go back to the main menu"<<endl;
            cout<<"enter a number to continue"<<endl;
            cin>>insert_menu_input;
            switch(insert_menu_input){
                case 1:
                
                
                insert_start();
                break;
                case 2:
                
               
                insert_end();
                break;
                case 3:
                
                cout<<"enter the element you want to insert after: "<<endl;
                cin>>key;
               
                insert_after(key);
                break;
                case 4:
                
                cout<<"enter the element you want to insert before: "<<endl;
                cin>>key;
                
                insert_before(key);
                break;
                case 0:
                break;
            }
            break;
        case 3:
            
            cout<<"1. Search specific element"<<endl;
            cout<<"2. Search before specific element"<<endl;
            cout<<"3. Search after specific element"<<endl;
            
            cout<<"0. go back to main menu"<<endl;
            cout<<"enter a number to continue: "<<endl;
            cin>>insert_menu_input;
            switch (insert_menu_input){
                case 1:
                
                cout<<"enter element to search"<<endl;
                cin>>element;
                search_specific(element);
                break;
                case 2:
                
                cout<<"enter element you want to search before: "<<endl;
                cin>>element;
                search_before(element);
                break;

                case 3:
                
                cout<<"enter element you want to search after: "<<endl;
                cin>>element;
                search_after(element);
                break;

                
                case 0:
                break;

            }
            break;
            
        case 4:
            if(first!=nullptr){
                cout<<"1. Delete specific element"<<endl;
            cout<<"2. Delete before specific element"<<endl;
            cout<<"3. Delete after specific element"<<endl;
            
            cout<<"0. go back to main menu"<<endl;
            cout<<"enter a number to continue: "<<endl;
            cin>>insert_menu_input;
            
        switch(insert_menu_input){
            case 1:
            
            cout<<"enter the element you want to delete: "<<endl;
            cin>>element;
            delete_specific(element);
            break;

            case 2:
            
            cout<<"enter the element you want to delete item before: "<<endl;
            cin>>element;
            delete_before(element);
            break;
            case 3:
            
            cout<<"enter the element you want to delete item after: "<<endl;
            cin>>element;
            delete_after(element);
            break;
            case 0:
                break;
        }
            }else
            cout<<"list is already empty"<<endl;
            
        break;
        case 5:
        display();
        break;
      
        case 0:
        exit(0);

     }
   }while(menu_input!=0);
    
    
}