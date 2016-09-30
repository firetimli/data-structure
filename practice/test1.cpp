#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
    };

// public member
public:

    // constructor
    LinkedList(){
        head = NULL;
        length = 0;// set head to NULL
    }

    // This prepends a new value at the beginning of the list
    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->x = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;
        length ++ ;           // last but not least, make the head point at the new node.
    }

    void print(){
      Node * temp = head;

      while(temp != NULL)
      {
        cout << temp->x << endl;
        temp = temp->next;
      }

      cout << "[lenght]:" << length << endl;
    }

    // Node * merge(Node* first, Node* second)
    // {
    //   Node * firstprev = first;
    //   Node * secondnext = second->next;
    //
    //   while(first != NULL || second != NULL){
    //
    //     if(first == head){
    //       if(first->data > second -> data){
    //         head = second;
    //         second->next = first;
    //       }
    //     }
    //
    //     if(first->data > second->data)
    //     {
    //       firstprev->next = second;
    //       second->next = first;
    //       second = secondnext;
    //     }
    //
    //     firstprev = first;
    //     first = first->next;
    //     second = second->next;
    //     secondnext = second->next;
    //   }
    //   return NULL; // change me!
    // }

    int popValue(){
        Node *n = head;
        int ret = n->x;

        head = head->next;
        delete n;
        length --;
        return ret;

    }

    void take(LinkedList & list1, LinkedList & list2 ){

        Node* tmp1 = list1.head;
        Node* tmp2 = list2.head;

        // fix list1 head pointer
        while(1){
          if (tmp1 == NULL) {
            break;
          }
          if(tmp2 == NULL){
            Node* newhead = list1.head->next;
            delete tmp1;
            list1.length--;

            list1.head = newhead;
            tmp1 = list1.head;
            tmp2 = list2.head;

          }
          else if (tmp1->x != tmp2->x) {
            tmp2 = tmp2->next;
          }
          else if (tmp1->x == tmp2->x) {
            break;
          }
        }

        // fix the rest





        //  Node * temp = list1.head;
         //
        //  int  countup = 0;
        //  Node * temprev = NULL;
         //
         //
        //  while(temp!= NULL){
         //
        //    Node * tempnext = temp->next;
         //
        //    Node * compare = list2.head;
        //    int  countdown = list2.length;
         //
        //    while(compare != NULL){
         //
        //      if(compare->x != temp->x){
        //        countdown --;
        //        if(countdown == 0){
        //          if(temp == head){
        //            head = tempnext;
        //            delete temp;
        //            temp = head;
        //            length --;
        //          }
        //          else{
        //            temprev->next = tempnext;
        //            temp->next = NULL;
        //            delete temp;
        //            temp = tempnext;
        //            length--;
        //          }
        //        }
        //        else{
        //          countup ++;
        //        }
        //      }
         //
        //      compare = compare->next;
        //    }
         //
        //    temprev = temp;
         //
        //    temp = temp->next;
        //  }

       }






// private member
private:
    int length;
    Node *head;
};

int main(){
  LinkedList list;

   list.addValue(8);
   list.addValue(2);
   list.addValue(4);
   list.addValue(8);


  LinkedList list2;

  list2.addValue(4);
  list2.addValue(3);
  list2.addValue(2);
  list2.addValue(1);



  list.take(list,list2);

  cout << "list1" << endl;
   list.print();
   cout << "list2" << endl;
   list2.print();
}
