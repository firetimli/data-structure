/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
  clear();

  // head = NULL;
  // tail = NULL;
  // curr = NULL;

    /// @todo Graded in MP3.1
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
  while(head!=NULL){
    tail = head->next;
    delete head;
    head = tail;
  }

    /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
  ListNode * temp = new ListNode(ndata);

  if(length ==0){
    head = temp;
    tail = head;
    length += 1;
  }
  else{
  temp->next = head;
  head->prev = temp;
  head = temp;
  length += 1;
  }

    /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
  ListNode * temp = new ListNode(ndata);

  if (length == 0){
    head = temp;
    tail = head;
    length += 1;
  }
  else{
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
    length +=1;
  }
    /// @todo Graded in MP3.1
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */

template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint)
{
    /// @todo Graded in MP3.1

    ListNode *curr = startPoint;
    if(startPoint == endPoint){

      return;
    }


    if (length != 0){

      while(curr != endPoint){
        ListNode * temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
        // if(temp->next == NULL){
        //   curr->next = curr->prev;
        //   curr->prev = NULL;
        //   break;
        // }

      }

      ListNode * temp2 = curr->next;
      curr->next = curr->prev;
      curr->prev = temp2;

      ListNode * temp3 = startPoint;
      startPoint = endPoint;
      endPoint = temp3;

    }


}




/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n)
{

    if (length <= 1 || n == 1){
        return;
    }
    else if(n == length){

      reverse();

      return;
    }

    ListNode * temp = head;
    ListNode * newhead = head;
    ListNode * newtail = NULL;

    int count  = n;
    while(temp != NULL){
      if(temp->next == NULL){
        // cout << "[newhead] " << newhead->data << endl;
        // cout << "[temp] " << temp->data << endl;
        reverse(newhead,temp);

        ListNode * tempfinal = temp->next;
        temp->next = newhead->prev;
        newhead->prev = tempfinal;

        if(newhead->prev != NULL){
          newhead->prev->next = newhead;
        }


        // cout << "[newhead] " << newhead->data << endl;
        // cout << "[temp] " << temp->data << endl;
        //
        // cout << "[newhead]->next " << newhead->next->data << endl;
        // cout << "[newhead]->prev " << newhead->prev->data << endl;
        //
        //
        // cout << "[temp]->prev " << temp->prev->data << endl;

        tail = temp;
        break;
        }
      else if(count == 1){
        // ListNode* curr = newhead;

          reverse(newhead,newtail);

          if (head==newtail){
            head = newhead;
          }



          ListNode * tempnext = temp->prev;
          ListNode * store = newtail->next;
          newtail->next = tempnext;
          newhead->prev = store;

// cout << __LINE__ << endl;
          tempnext->prev = newtail;
// cout << __LINE__ << endl;

          if(newhead->prev != NULL){
            newhead->prev->next = newhead;
          }

          // cout << "newhead " << newhead->data << endl;
          // cout << "newtail " << newtail->data << endl;
          // cout << "temp " << temp->data << endl;
          // cout << "tempnext " << tempnext->data << endl;
          // curr = newhead;
          // while (curr != NULL) {
          //     cout << "cur " << curr->data << endl;
          //     if (curr->prev) {
          //       cout << "cur->prev " << curr->prev->data << endl;
          //     }
          //     else{
          //       cout << "cur->prev " << curr->prev << endl;
          //     }
          //     if (curr->next) {
          //       cout << "cur->next " << curr->next->data << endl;
          //     }
          //     else{
          //       cout << "cur->next " << curr->next << endl;
          //     }
          //     curr = curr->next;
          // }
          // cout << "tmp data " << temp->data << endl;

          temp = tempnext;
          newhead = temp;
          count = n;


      }


      temp = temp->next;
      newtail = temp;

      count --;
    }

    // ListNode *test = tail;
    // while(test != head){
    //   cout << "backwarding..." << endl;
    //   cout << test->data << endl;
    //   test = test->prev;
    // }
    /// @todo Graded in MP3.1
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    if(length <= 1){
      return;
    }
    ListNode * curr = head->next;

    while (curr!= tail) {
      if(curr->next == tail){
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        curr->next = NULL;
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
        break;
      }

      ListNode * walk = curr->next->next;

      curr->next->prev = curr->prev;
      curr->prev->next = curr->next;

      curr->next = NULL;
      curr->prev = tail;
      tail->next = curr;
      tail = curr;

      //fix the connection

      curr = walk;
    }
    /// @todo Graded in MP3.1
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();


    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    /// @todo Graded in MP3.2
    ListNode * end;

    if (start == NULL){
      return NULL;
    }

      for (int i = 0; i < splitPoint; i++) {
        end = start;
        start = start->next;
      }
      end->next = NULL;


    return start; // change me!
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
  ListNode * secondnext = NULL;
  ListNode * firstprev = NULL;// change me!
  ListNode * newhead = NULL;

  if(first == NULL || second == NULL){
    return NULL;
  }
  if(second->data < first->data){
    newhead = second;

  }
  else{
    newhead = first;
  }

  while(second != NULL){
    if(second->data < first->data){
      secondnext = second->next;

      second->next = first;
      first->prev = second;
      if (firstprev != NULL)
      {
        firstprev->next = second;
        second->prev= firstprev;
      }
      first = second;
      second = secondnext;
    }
    else{

      firstprev = first;
      first = first->next;
    }

    if(first == NULL){
        firstprev->next = second;
        if(second != NULL){
          second->prev = firstprev;
        }
        break;
      }
    }

   return newhead;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

template <class T>
void List<T>::printback()
{
  ListNode * temp = tail;
  while(temp != 0){
    cout << temp->data << endl;
    temp = temp->prev;
  }


}
/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{

  ListNode *newhead = NULL;
  if (chainLength == 1){
    return start;
  }
  else{
    int splitPoint = (chainLength+1)/2;
    ListNode * left = start;
    ListNode * right = this->split(start, splitPoint);
    int chainLength2 = chainLength/2;
    right = mergesort(right,chainLength2);
    left = mergesort(left,(chainLength-chainLength2));
    newhead = merge(right,left);


  }
    /// @todo Graded in MP3.2
    return newhead;
}
