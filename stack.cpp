#include <iostream>
using namespace std;

struct stack{
    int data;
    stack *next=nullptr;
};
struct stack2{
    int data;
    stack2 *next=nullptr;
};
stack* top = nullptr;
stack* last = nullptr;
stack2* top2 = nullptr;
void push(stack* s){
    
    
    if(top2==nullptr){
        top2=s;
        s->next = top2;
    }else{
        
        s->next = top2;
        top2=s;
    }
}

void reverse(){
    stack* temp = top;
    while(temp!=nullptr){
        stack2.push(temp);
        temp=temp->next;
    }

    stack2* t = top2;
    while(t!=nullptr){
        cout<<t->data;
        t=t->next;
    }
}
void create_list(){
    char check = 'n';
    
    do{
       push();
       cout<<"do you want to insert again:(y/n): "<<endl;
       cin>>check;
    }while(check=='y'|| check=='Y');
}
void display(){
    
    if(top==nullptr){
        cout<<"the list has nothing to show!"<<endl;
    }
    else{
        stack *p = top;
        
        do{

            cout<<p->data<<" ";
            p=p->next;
        }while(p!=top);
        

        cout<<endl;
    }
}





void search_specific(int key){
    int i=1;
    if(top==nullptr){
        cout<<"the list is empty. cant find the key"<<endl;
    }else{
       
            if(top->data==key){
                cout<<"element at top position"<<endl;
            }
        else{
            stack *p = top;
            do{
                p=p->next;
                i++;

            }while(p!=top && p->data!=key);
            if(p!=top){
                cout<<"element is at "<<i<<"th position"<<endl;
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }

    }
}

void search_before(int key){
    if(top==nullptr || top==last){
        cout<<"empty list or totally one element in there"<<endl;
    }else{
        if(top->data==key){
            cout<<"element is "<<last->data<<endl;
        }else{
            stack *p = top;
            stack *q = top->next;
            while(q!=top && q->data !=key){
                p=q;
                q=q->next;
            }
            if(q!=top){
                cout<<"element is: "<<p->data<<endl;
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
    }
}

void search_after(int key){
    if(top==nullptr || top==last){
        cout<<"list is empty or one element in total"<<endl;
    }else{
        if(top->data==key){
            cout<<top->next->data<<endl;
        }else{
            stack* q = top->next;
            while(q!=top && q->data!=key){
                q=q->next;
            }
            if(q!=top){
                cout<<q->next->data<<endl;
            }else{
                cout<<"key not found in the list"<<endl;
            }
        }
    }
}

void delete_stack(){
    if(top==nullptr){
        cout<<"list is already empty"<<endl;
    }else if(top==last){
            stack* p = top;
            top=last=nullptr;
            delete p;
        }
        else{
            stack *p = top;
            stack *q = nullptr;
            do{
                q=p;
                p=p->next;
            }while(p!=last);
            q->next = top;
            last=q;
            delete p;
        }
}

void delete_list(){
    while(top!=nullptr){
        delete_stack();
    }
}
void delete_specific(int key){
    if(top==nullptr){
        cout<<"list is empty, cant perform deletion"<<endl;
    }else{
        if(top->data==key){
            if(top==last){
                stack *q=top;
                top=last=nullptr;
                delete q;
            }else{
                stack *q= top;
                
                top = top->next;
                delete q;
                last->next = top;
            }
        }else{
            stack *p=top;
            stack *q = nullptr;
            do{
                q=p;
                p=p->next;
            }while(p!=top && p->data !=key);
            if(p!=top){
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
    if(top==nullptr || top==last){
        cout<<"not enough elements to delete"<<endl;
    }else{
        stack *p = top;
        stack *q = nullptr;
        if(top->data==key){
            while(p!=last){
                q=p;
                p=p->next;
            }
            q->next = top;
            last=q;
            delete p;
        }else{
            if(top->next->data==key){
                stack *p = top;
                top = top->next;
                delete p;
                last->next = top;
            }else{
                stack *q1 = top->next;
                stack *p = top;
                stack *q = nullptr;
                while(q1!=top && q1->data!=key){
                    q=p;
                    p=q1;
                    q1=q1->next;
                }
                if(q1!=top){
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
    if(top==nullptr || top==last){
        cout<<"not enough elements to perform deletion"<<endl;
    }else{
        stack* p=top;
        stack *q = top->next;
        if(p->data==key){
            q=top->next;
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
            }while(p!=top && p->data!=key);
            if(p!=top){
                if(p==last){
                    
                    top=top->next;
                    delete q;
                    last->next=top;

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

stack* pop(){
    if(top==nullptr){
        return nullptr;
    }else{
        stack* temp = top;
        top = top->next;
        
    }return top;
}
void peek(){
    if(top==nullptr){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<top->data<<endl;
    }
}



int main(){
    // cout<<"insert_end"<<endl;
    // insert_end();
    // display();
    // cout<<"create list"<<endl;
    // create_list();
    // display();
    // cout<<"push"<<endl;
    // push();
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
    // delete_stack();
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
                
                
                push();
                break;
                case 2:
                
               
                //insert_end();
                break;
                case 3:
                
                cout<<"enter the element you want to insert after: "<<endl;
                cin>>key;
               
                //insert_after(key);
                break;
                case 4:
                
                cout<<"enter the element you want to insert before: "<<endl;
                cin>>key;
                
                //insert_before(key);
                break;
                case 0:
                break;
            }
            break;
        case 3:
            
            cout<<"1. peek element"<<endl;
            cout<<"2. Search before specific element"<<endl;
            cout<<"3. Search after specific element"<<endl;
            
            cout<<"0. go back to main menu"<<endl;
            cout<<"enter a number to continue: "<<endl;
            cin>>insert_input;
            switch (insert_input){
                case 1:
                
                peek();
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
            if(top!=nullptr){
                cout<<"1. pop element"<<endl;
            cout<<"2. Delete before specific element"<<endl;
            cout<<"3. Delete after specific element"<<endl;
            cout<<"4. delete stack at end"<<endl;
            cout<<"5. delete list"<<endl;
            cout<<"0. go back to main menu"<<endl;
            cout<<"enter a number to continue: "<<endl;
            cin>>insert_input;
            
        switch(insert_input){
            case 1:
            
            cout<<pop()<<endl;
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
            delete_stack();
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