#include<stdio.h>
#include<stdlib.h>


struct node{
       float coff;
       int expo;
       struct node *link;
}; 


struct node *insert(struct node *head,float coff,int expo){
       struct node *temp = malloc(sizeof(struct node));
       temp->coff = coff;
       temp->expo = expo;
       temp->link = NULL;
       
       if(head == NULL||head->expo < expo){
           temp->link = head;
           head = temp;
       }
       else{
           struct node *ptr = head;
           while(ptr->link!=NULL && ptr->link->expo>expo){
               ptr = ptr->link;
           }
           temp->link = ptr->link;
           ptr->link = temp;
       }
       
       return head;
}


struct node *createPolynomial(struct node *head){
       int n;
       printf("How many terms are there int the Polynomial: \n");
       scanf("%d",&n);
       float coff;
       int expo;
       for(int i=0;i<n;i++){
           printf("Provide cofficient for the term %d:  \n",i+1);
           scanf("%f",&coff);
           printf("Provide exponent for the term %d: \n",i+1);
           scanf("%d",&expo);
           head = insert(head,coff,expo);
       }
       return head;
}


struct node *addPolynomial(struct node *head1,struct node *head2, struct node *head3){
            
            struct node *ptr1 =head1;
            struct node *ptr2 = head2;
            
            while(ptr1 !=NULL && ptr2 != NULL){
                if(ptr1->expo == ptr2->expo){
                    head3 = insert(head3,ptr1->coff+ptr2->coff,ptr1->expo);
                    ptr1=ptr1->link;
                    ptr2= ptr2->link;
                }
                
                else if(ptr1->expo<ptr2->expo){
                    head3 = insert(head3,ptr2->coff,ptr2->expo);
                    ptr2 = ptr2->link;
                }
                
                else if (ptr1->expo>ptr2->expo){
                    head3 = insert(head3,ptr1->coff,ptr1->expo);
                    ptr1 = ptr1->link;
                }
            }
            while(ptr2!=NULL){
                 head3 = insert(head3,ptr2->coff,ptr2->expo);
                 ptr2 = ptr2->link;
             }
             
             while(ptr1!= NULL){
                 head3 = insert(head3,ptr1->coff,ptr1->expo);
                 ptr1 = ptr1->link;
             }
                
            
            return head3;
}


struct node* multiplyPolynomial(struct node *head1,struct node *head2, struct node *head3){
     struct node *ptr1 = head1;
     struct node *ptr2 = head2;
     
     while(ptr1 != NULL){
         ptr2 = head2;
         while(ptr2 != NULL){
           
                head3 = insert(head3,ptr1->coff * ptr2->coff,ptr1->expo+ptr2->expo);
                ptr2 = ptr2->link;
            }
          ptr1 = ptr1->link;
         }
        return head3;
}


void print(struct node *head){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("Polynomial is NULL!\n");
    }
    while(ptr!=NULL){
        printf("%.2fx^%d\t",ptr->coff,ptr->expo);
        ptr = ptr->link;
    }
}


int main(){
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    
    printf("First PolyNomial: \n");
    head1 = createPolynomial(head1);
    printf("Second Polynomial: \n");
    head2 = createPolynomial(head2);
    
    
    print(head1);
    print(head2);
    
    head3 = multiplyPolynomial(head1,head2,head3);
    printf("Resultant Polynomial!");
    print(head3);
    
    
    return 0;
}
