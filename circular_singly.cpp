#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next=nullptr;
};
Node* first = nullptr;
Node* last = nullptr;

void insert_end(){
    Node *p = new Node();
    cout<<"enter the data"<<endl;
    cin>>p->data;
    if(first==nullptr){
        first=last=p;

    }else{
        last->next = p;
        last = p;
    }
    p->next = first;
}

void create_list(){
    char check = 'n';
    
    do{
       insert_end();
       cout<<"do you want to insert again:(y/n): "<<endl;
       cin>>check;
    }while(check=='y'|| check=='Y');
}
void display(){
    
    if(first==nullptr){
        cout<<"the list has nothing to show!"<<endl;
    }
    else{
        Node *p = first;
        
        do{

            cout<<p->data<<" ";
            p=p->next;
        }while(p!=first);
        

        cout<<endl;
    }
}

void insert_start(){
    Node *p = new Node();
    cout<<"enter the data: "<<endl;
    cin>>p->data;
    if(first==nullptr){
        first=last=p;
        p->next = first;
    }else{
        last->next = p;
        p->next = first;
        first=p;
    }
}

void insert_before(int key){
    if(first==nullptr){
        cout<<"the list is empty"<<endl;
    }else{
        Node *p =new Node();
        cout<<"enter the data: "<<endl;
        cin>>p->data;
        if(first->data==key){
            last->next =p;
            p->next = first;
            first=p;
        }else{
            Node *q = first->next;
            Node *q1 = first;
            while(q!=first && q->data!=key){
                q1=q;
                q=q->next;
            }
            if(q!=first){
                q1->next = p;
                p->next=q;
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
    }
}

void insert_after(int key){
    if(first==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;

    }else{
        if(first->data==key){
            Node *p = new Node();
                cout<<"enter the data"<<endl;
                cin>>p->data;
                
            if(first==last){
                p->next = first->next;
                first->next = p;
                last=p;
            }else{
                p->next =first->next;
                first->next = p;
            }
        }else{
            Node * p = first->next;
            while(p!=first && p->data !=key){
                p=p->next;
            }
            if(p!=first){
                Node * q = new Node();
                cout<<"enter the data"<<endl;
                cin>>q->data;

                if(p==last){
                    q->next = p->next;
                    p->next =q;
                    last=q;
                }else{
                    q->next = p->next;
                    p->next = q;
                }
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
    }
}

void search_specific(int key){
    int i=1;
    if(first==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;
    }else{
       
            if(first->data==key){
                cout<<"element at first position"<<endl;
            }
        else{
            Node *p = first;
            do{
                p=p->next;
                i++;

            }while(p!=first && p->data!=key);
            if(p!=first){
                cout<<"element is at "<<i<<"th position"<<endl;
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }

    }
}

void search_before(int key){
    if(first==nullptr || first==last){
        cout<<"empty list or totally one element in there"<<endl;
    }else{
        if(first->data==key){
            cout<<"element is "<<last->data<<endl;
        }else{
            Node *p = first;
            Node *q = first->next;
            while(q!=first && q->data !=key){
                p=q;
                q=q->next;
            }
            if(q!=first){
                cout<<"element is: "<<p->data<<endl;
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
    }
}

void search_after(int key){
    if(first==nullptr || first==last){
        cout<<"list is empty or one element in total"<<endl;
    }else{
        if(first->data==key){
            cout<<first->next->data<<endl;
        }else{
            Node* q = first->next;
            while(q!=first && q->data!=key){
                q=q->next;
            }
            if(q!=first){
                cout<<q->next->data<<endl;
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
    }
}

void delete_node(){
    if(first==nullptr){
        cout<<"list is already empty"<<endl;
    }else if(first==last){
            Node* p = first;
            first=last=nullptr;
            delete p;
        }
        else{
            Node *p = first;
            Node *q = nullptr;
            do{
                q=p;
                p=p->next;
            }while(p!=last);
            q->next = first;
            last=q;
            delete p;
        }
}

void delete_list(){
    while(first!=nullptr){
        delete_node();
    }
}
void delete_specific(int key){
    if(first==nullptr){
        cout<<"list is empty, cant perform deletion"<<endl;
    }else{
        if(first->data==key){
            if(first==last){
                Node *q=first;
                first=last=nullptr;
                delete q;
            }else{
                Node *q= first;
                
                first = first->next;
                delete q;
                last->next = first;
            }
        }else{
            Node *p=first;
            Node *q = nullptr;
            do{
                q=p;
                p=p->next;
            }while(p!=first && p->data !=key);
            if(p!=first){
                if(p==last){
                    q->next = p->next;
                    last=q;
                    delete p;
                }else{
                    q->next = p->next;
                    delete p;
                }
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
    }
}

void delete_before(int key){
    if(first==nullptr || first==last){
        cout<<"not enough elements to delete"<<endl;
    }else{
        Node *p = first;
        Node *q = nullptr;
        if(first->data==key){
            while(p!=last){
                q=p;
                p=p->next;
            }
            q->next = first;
            last=q;
            delete p;
        }else{
            if(first->next->data==key){
                Node *p = first;
                first = first->next;
                delete p;
                last->next = first;
            }else{
                Node *q1 = first->next;
                Node *p = first;
                Node *q = nullptr;
                while(q1!=first && q1->data!=key){
                    q=p;
                    p=q1;
                    q1=q1->next;
                }
                if(q1!=first){
                    q->next = q1;
                    delete p;
                }else{
                    cout<<"key not found in the listt"<<endl;
                }
            }
        }
    }
}

void delete_after(int key){
    if(first==nullptr || first==last){
        cout<<"not enough elements to perform deletion"<<endl;
    }else{
        Node* p=first;
        Node *q = first->next;
        if(p->data==key){
            q=first->next;
            if(p->next==last){
                p->next=q->next;
                last=p;
                delete q;
            }else{
                p->next = q->next;
                delete q;
            }
        }else{
            do{
                p=q;
                q=q->next;
            }while(p!=first && p->data!=key);
            if(p!=first){
                if(p==last){
                    
                    first=first->next;
                    delete q;
                    last->next=first;

                }else if(q==last){
                    p->next=q->next;
                    last=p;
                    delete q;
                    cout<<last->data;
                }
                else{
                    p->next = q->next;
                    delete q;
                    
                }
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
        
    }
}

int main(){
    // cout<<"insert_end"<<endl;
    // insert_end();
    // display();
    // cout<<"create list"<<endl;
    // create_list();
    // display();
    // cout<<"insert_start"<<endl;
    // insert_start();
    // display();
    // cout<<"insert_before 2"<<endl;
    // insert_before(2);
    // display();
    // cout<<"insert_after 4"<<endl;
    // insert_after(4);
    // display();
    // cout<<"search specific 3"<<endl;
    // search_specific(3);
    // display();
    // cout<<"search after 3"<<endl;
    // search_after(3);
    // display();
    // cout<<"search before 2"<<endl;
    // search_before(2);
    // display();
    // cout<<"delete before 5"<<endl;
    // delete_before(5);
    // display();
    // cout<<"delete after 1"<<endl;
    // delete_after(1);
    // display();
    // cout<<"delete specific 5"<<endl;
    // delete_specific(5);
    // display();
    // cout<<"delete end"<<endl;
    // delete_node();
    // display();
    // cout<<"delete list"<<endl;
    // delete_list();
    // display();

     int input=0;
    int element; int key;
    int insert_input;int x;

   do{
     cout<<"MENU"<<endl;
     cout<<"1. creating a linked list "<<endl;
     cout<<"2. Insert element in the list"<<endl;
     cout<<"3. Search element in list"<<endl;
     cout<<"4. Delete element in the list"<<endl;
     cout<<"5. Display the list"<<endl;
     
     cout<<"0. exit the program"<<endl;
     cout<<"enter a number to continue: "<<endl;
     cin>>input;
     switch(input){
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
            cin>>insert_input;
            switch(insert_input){
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
            cin>>insert_input;
            switch (insert_input){
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
            cout<<"4. delete node at end"<<endl;
            cout<<"5. delete list"<<endl;
            cout<<"0. go back to main menu"<<endl;
            cout<<"enter a number to continue: "<<endl;
            cin>>insert_input;
            
        switch(insert_input){
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
            case 4:
            delete_node();
            break;
            case 5:
            delete_list();
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
   }while(input!=0);
}