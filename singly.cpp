#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next=nullptr;
};
Node* first = nullptr;
Node* last = nullptr;

void insert_end(){
    Node *p = new Node;
    cout<<"enter the data: "<<endl;
    cin>>p->data;
    //check whether the list is empty or not
    if(first==nullptr){
        first = last = p;
    }else{
        last->next = p;
        last=p;
    }
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
    Node* p = first;
    if(first==nullptr){
        cout<<"the list has nothing to show!"<<endl;
    }
    else{
        while(p!=nullptr){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}

void insert_start(){
    Node *p = new Node;
    cout<<"enter the data; "<<endl;
    cin>>p->data;
    if(first==nullptr){
        first=last=p;
    }else{
        p->next= first;
        first=p;
    }
}

void insert_before(int key){
    if(first==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;
    }else{
        Node*q=nullptr;
        Node* p=first;

        while(p!=nullptr && p->data!=key){
            q=p;
            p=p->next;
        }
        if(p!=nullptr){
            Node* temp = new Node;
            cout<<"enter the data: "<<endl;
            cin>>temp->data;
            if(key==first->data){
                temp->next=p;
                first=temp;
            }else{
                temp->next = p;
                q->next = temp;
            }
            cout<<"element inserted!"<<endl;
        }else{
            cout<<"element not found in the list"<<endl;
        }
    }
}

void insert_after(int key){
    if(first==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;

    }else{
        Node *q = first;
        Node *p= q->next;
        while(p!=nullptr && q->data!=key){
            q=p;
            p=p->next;
        }
        if(q->data==key){
            Node *temp = new Node;
            cout<<"enter the data: "<<endl;
            cin>>temp->data;
            temp->next = p;
            q->next = temp;
            cout<<"element inserted!"<<endl;
        }else{
            cout<<"element not found in the list"<<endl;
        }
    }
}

void search_specific(int key){
    int i=0;
    if(first==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;
    }else{
        Node* p =first;
        while(p!=nullptr && p->data!=key){
            i+=1;
            p=p->next;
        }
        if(p!=nullptr){
            cout<<"the key is present at "<<i+1<<" position"<<endl;
        }else{
            cout<<"element not found"<<endl;
        }
    }
}

void search_before(int key){
    Node *p = first;
    Node *q = nullptr;
    if(first==nullptr || first->data==key){
        cout<<"unable to iterate through list"<<endl;
    }else{
        

        while(p!=nullptr && p->data !=key){
            q=p;
            p=p->next;
        }
        if(p!=nullptr){
            cout<<"the element before"<<key<<"is "<<q->data<<endl;
        }else{
            cout<<"key not found!"<<endl;
        }
    }
}

void search_after(int key){
    if(first==nullptr){
        cout<<"the list is empty, cant find the key"<<endl;
    }else{
        Node *q=first;
        
        while(q!=nullptr && q->data !=key){
           q=q->next;
        }
        if(q!=nullptr){
            if(q!=last){
                cout<<"the element after key is: "<<q->next->data<<endl;
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

        }

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
        Node*p = first;
        Node *q = nullptr;
        while(p!=nullptr && p->data !=key){
            q=p;
            p=p->next;
        }
        if(p==nullptr){
            cout<<"couldnt find the key t delete"<<endl;
        }else{
            if(p==last){
                q->next=nullptr;
                last=q;
            }else{
                q->next = p->next;
            }

            delete p;
            cout<<"element deleted"<<endl;
        }
    }
}

void delete_before(int key){
    if(first==nullptr || first==last){
        cout<<"not enough elements to delete"<<endl;
    }else{
        Node *p = first->next;
        Node *q=nullptr;
        Node *q1 = first;

        if(p->data==key){
            first = p;
            delete q1;
        }else{
            while(p!=nullptr && p->data !=key){
                q=q1;
                q1=p;
                p=p->next;
            }
            if(p!=nullptr){
                q->next = p;
                delete q1;
            }else{
                cout<<"key not found, cant perform deletion"<<endl;
            }
        }
        

    }
}

void delete_after(int key){
    if(first==nullptr || first==last){
        cout<<"not enough elements to perform deletion"<<endl;
    }else{
        Node* q=first;
        Node* q1 = q->next;
        Node *p = q1->next;

        while(p!=nullptr && q->data !=key){
            q=q1;
            q1=p;
            p=p->next;
        }
        if(q->data !=key){
            cout<<"cant perform deletion bcz of no available position after key"<<endl;
        }else{
            q->next=p;
            delete q1;
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