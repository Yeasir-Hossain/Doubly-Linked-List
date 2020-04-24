#include<iostream>
#include<stdlib.h>
#include<strings.h>
using namespace std;
struct node
{
    int roll;
    char name[100];
    node *next,*prev;
};
class doublylink
{
    node *head,*tail;
public:
    doublylink();
    void insert1st();
    void insertlast();
    void insertbefore();
    void insertafter();
    void deletelist();
    void deletefirst();
    void deletelast();
    void deleteinfo();
    void traverse();
    int findinfo();

};
doublylink :: doublylink()
{
    head=tail=NULL;
}

void doublylink::insert1st()
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    if(newnode==NULL)
    {
        cout<<"Allocation failed"<<endl;
        exit(1);
    }
    cout<<"Enter name:";
    cin>>newnode->name;
    cout<<"Enter roll:";
    cin>>newnode->roll;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }


}
void doublylink::insertlast()
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    cout<<"Enter name:";
    cin>>newnode->name;
    cout<<"Enter roll:";
    cin>>newnode->roll;

    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
        return;
    }
    tail->next=newnode;
    newnode->next=NULL;
    newnode->prev=tail;
    tail=newnode;
}
void doublylink::insertbefore()
{
    node *i;
    i=head;
    char n[100];
    cout<<"Enter name before which you want to insert the data:";
    cin>>n;
    if(i==NULL)
        cout<<"No record"<<endl;
    if((strcmp(head->name,n)==0))
    {
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        cout<<"Enter name:";
        cin>>newnode->name;
        cout<<"\nEnter roll:";
        cin>>newnode->roll;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        int nodenumber=0,k;
        for(i=head; i!=NULL; i=i->next)
        {
            nodenumber++;
            if(strcmp(i->name,n)==0)
                break;
        }
        if(i==NULL)
        {
            cout<<"Not found";
            return;
        }
        for(k=1,i=head; k<nodenumber; i=i->next,k++);
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        cout<<"Enter name:";
        cin>>newnode->name;
        cout<<"\nEnter roll:";
        cin>>newnode->roll;
        (i->prev)->next=newnode;
        newnode->prev=i->prev;
        newnode->next=i;
        i->prev=newnode;

    }

}
void doublylink::insertafter()
{
    node *i;
    i=head;
    char n[100];
    cout<<"Enter name after which you want to insert the data:";
    cin>>n;
    if(i==NULL)
        cout<<"No record"<<endl;
    if((strcmp(head->name,n)==0))
    {
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        cout<<"Enter name:";
        cin>>newnode->name;
        cout<<"\nEnter roll:";
        cin>>newnode->roll;
        newnode->next=head->next;
        newnode->prev=head;
    }
    else
    {
        int nodenumber=0,k;
        for(i=head; i!=NULL; i=i->next)
        {
            nodenumber++;
            if(strcmp(i->name,n)==0)
                break;
        }
        if(i==NULL)
        {
            cout<<"Not found";
            return;
        }
        for(k=1,i=head; k<nodenumber; i=i->next,k++);
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        cout<<"Enter name:";
        cin>>newnode->name;
        cout<<"\nEnter roll:";
        cin>>newnode->roll;
        if(i==tail)
        {
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=NULL;
            tail=newnode;
        }
        else
        {
            (i->next)->prev=newnode;
            newnode->prev=i;
            newnode->next=i->next;
            i->next=newnode;
        }

    }

}
void doublylink::deletelist()
{
    node *i,*temp;
    for(i=head; i!=NULL; )
    {
        temp=i->next;
        free(i);
        i=temp;
    }
    head=tail=NULL;

}
void doublylink::deletefirst()
{
    if(head==NULL)//No node
        return;
    else if(head==tail)//only one node
    {
        free(head);
        head=tail=NULL;
        return;
    }
    else
    {
        node *temp= head;
        head=head->next;
        free(temp);
    }

}
void doublylink::deletelast()
{
    node *temp;
    if(head==NULL)//No node
    {
        cout<<"Nothing to delete"<<endl;;
        return;
    }
    else if(head==tail)//only one node
    {
        free(head);
        head=tail=NULL;
        return;
    }
    else
    {
        temp=tail;
        (tail->prev)->next=NULL;
        tail=tail->prev;
        free(temp);
    }

}
void doublylink::deleteinfo()
{
    node *temp,*i;
    char n[100];
    cout<<"Enter name you want to delete:";
    cin>>n;
    if(head==NULL)
    {
        cout<<"Nothing to delete"<<endl;;
        return;
    }
    //If name matches with first node
    else if(head==tail)//only one node
    {
        free(head);
        head=tail=NULL;
        return;
    }
    else
    {


        //check other nodes
        int k=0;
        for(i=head; i!=NULL; i=i->next)
        {
            k++;
            if(strcmp(i->name,n)==0)
                break;
        }
        if(i==NULL)
        {
            cout<<"Not found";
            return;
        }
        else if(i==tail)
        {
            deletelast();
        }
        else if(i==head)
        {
            deletefirst();
        }
        else
        {
            temp=i;
            (i->prev)->next=temp->next;
            (i->next)->prev=temp->prev;
            free(temp);

        }

    }
}
int doublylink::findinfo()
{
    char n[100];
    int k=0;
    node *i;
    cout<<"Enter name you want to search:";
    cin>>n;
    for(i=head; i!=NULL; i=i->next)
    {
        k++;
        if(strcmp(i->name,n)==0)
        {
            cout<<"Found at node:"<<k<<endl;
            return k;
        }
    }
    if(i==NULL)
    {
        cout<<"Not found"<<endl;
        return 0;
    }
    system("PAUSE");
}
void doublylink::traverse()
{
    node *i;
    int k=0;
    if(head==NULL)
    {
        cout<<"Nothing to show"<<endl;
    }
    for(i=head; i!=NULL; i=i->next)
    {
        k++;
        cout<<k<<": "<<i->roll<<"\t"<<i->name<<endl;
    }
    system("PAUSE");
}
int main()
{
    int ch=0,j,n;
    doublylink obj;
    while(ch!=12)
    {
        cout<<"<<==MENU==>>"<<endl;
        cout<<"1.Insert data"<<endl;
        cout<<"2.Insert in first position"<<endl;
        cout<<"3.Insert in last position"<<endl;
        cout<<"4.Insert before a record"<<endl;
        cout<<"5.Insert after a record"<<endl;
        cout<<"6.Delete full list"<<endl;
        cout<<"7.Delete first record"<<endl;
        cout<<"8.Delete last record"<<endl;
        cout<<"9.Delete a record"<<endl;
        cout<<"10.Find position of a record"<<endl;
        cout<<"11.Show full list"<<endl;
        cout<<"12.Quit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter how many records you want to enter:";
            cin>>n;
            for(j=0; j<n; j++)
                obj.insertlast();
            system("CLS");
            break;
        case 2:
            obj.insert1st();
            system("CLS");
            break;
        case 3:
            obj.insertlast();
            system("CLS");
            break;
        case 4:
            obj.insertbefore();
            system("CLS");
            break;

        case 5:
            obj.insertafter();
            system("CLS");
            break;
        case 6:
            obj.deletelist();
            system("CLS");
            break;
        case 7:
            obj.deletefirst();
            system("CLS");
            break;
        case 8:
            obj.deletelast();
            system("CLS");
            break;
        case 9:
            obj.deleteinfo();
            system("CLS");
            break;
        case 10:
            obj.findinfo();
            system("CLS");
            break;
        case 11:
            obj.traverse();
            system("CLS");
            break;
        case 12:
            break;
        default:
            cout<<"Outside 1-11. Try again.\n";
        }//End of switch
    }//End of while
}

