#include <iostream>
using namespace std;
class node
{
  public:
  int data;
  node *next ;
  node(int data)
  {
    this->data=data;
    next = NULL;
  }
};
node *takeinput()
{
  int data;
  cin>>data;
  node *head=NULL;
  node *tail=NULL;
  while(data!=-1)
  {
    node *newnode = new node(data);
    if(head==NULL)
    {
      head=newnode;
      tail=newnode;
    }
    else
    {
      tail->next = newnode;
      tail = tail->next;
    }
    cin>>data;
  }
  return head;
}
void print(node *head)
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head= head->next;
  }
}
node *insertnode(node *head,int data,int i)
{
   node *newnode = new node(data);
   int count =0;
   node *temp = head;
   if(i==0)
   {
     newnode->next=head;
     head=newnode;
     return head;
   }
   while(temp!=NULL && count<i-1)
   {
     temp = temp->next;
     count++;
   }
   if(temp !=NULL)
   {
      node *a= temp->next;
      temp->next=newnode;
      newnode->next=a;
   }
  return head;
}
node *deletenode(node*head,int i)
{
  node *temp=head;
  int count=0;
  while(count<i-1)
  {
    temp=temp->next;
    count++;
  }
  if(temp!=NULL)
  {
    node *a=temp->next;
    node *b=a->next;
    temp->next=b;
    delete a;
    return head;
  }
  return head;
}
node *appendnode(node *head,int n,int i)
{
  node *temp =head;
  node *temp2=head;
  node *temp3=head;
  int count=0;
  while(count<n-i-1)
  {
    temp=temp->next;
    temp2=temp2->next;
    count++;
  }
  if (temp2!=NULL && head!=NULL && temp3!=NULL )
  {
    temp2=temp2->next;
    temp->next =NULL;
    head=temp2; 
  }
  count=0;
  while(count<i-1)
  {
    temp2=temp2->next;
    count++;
  }
  temp2->next=temp3;
  return head;
}
node *reverselinkedlist(node *head)
{
  node *previous=NULL;
  node *current=head;
  node *nex = NULL;
  while(current!=NULL)
  {
    nex=current->next;
    current->next=previous;
    previous=current;
    current=nex;
  }
  return previous;
}
node *midpoint(node *head)
{
  node *slow = head;
  node *fast = head->next;
  while(fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}
node *merge(node *head1,node *head2)
{
  if(head1 == NULL)
  {
    return head2;
  }
  if(head2 == NULL)
  {
    return head1;
  }
  node *head=NULL;
  node *tail=NULL;
  if(head1->data < head2->data)
  {
    head = head1;
    tail = head1;
    head1 = head1->next;
  }
  else
  {
    head = head2;
    tail = head2;
    head2 = head2->next;
  }
  while(head1!=NULL && head2 !=NULL)
  {
    if(head1->data<head2->data)
    {
      tail->next=head1;
      tail = head1;
      head1 = head1->next;
    }
    else
    {
      tail->next=head2;
      tail=head2;
      head2 = head2->next;
    }
  }
  if(head1!=NULL)
  {
    tail->next=head1;
  }
  if(head2!=NULL)
  {
    tail->next=head2;
  }
  return head;
}
node *mergesort(node *head)
{
  if(head == NULL||head->next==NULL)
  {
    return head;
  }
  node *mid=midpoint(head);
  node *half1=head;
  node *half2=mid->next;
  mid->next=NULL;
  half1 = mergesort(half1);
  half2 = mergesort(half2);
  node *finalhead=merge(half1,half2);
  return finalhead;
}
int main()
{
  node *head = takeinput();
  head = mergesort(head);
  print(head);
}   