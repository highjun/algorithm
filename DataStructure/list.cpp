#include<iostream>
#include<list>
#include<assert.h>

using namespace std;

template <typename T>
struct Node{
    T value;
    struct Node<T> *prev;
    struct Node<T> *next;
};

template <typename T>
class LinkedList{
public:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    int n_node;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->n_node = 0;    
    }
    T front(){
        return head->value;
    }
    T back(){
        return tail->value;
    }
    int size(){
        return n_node;
    }
    void push_back(T val){
        Node<T> *node = new Node<T>;
        node->value = val;
        node->next = NULL;
        node->prev = tail;
        if(tail!= NULL)
            tail->next = node;
        else
            head = node;
        tail = node;
        n_node++;
    }
    void push_front(T val){
        Node<T> *node = new Node<T>;
        node->value = val;
        node->next = head;
        node->prev = NULL;
        if(head!= NULL)
            head->prev = NULL;
        else
            tail = node;
        head = node;
        n_node++;
    }
    void pop_front(){
        Node<T> *tmp = head;
        head = head->next; 
        head->prev = NULL;
        n_node--;
        free(tmp);
    }
    void pop_back(){
        Node<T> *tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        n_node--; 
        free(tmp);
    }
    void clear(){
        Node<T>* node;
        n_node = 0;
        for(node = head; node!= NULL;){
            Node<T> *tmp = node;
            node = node->next;
            free(tmp);
        }
        head = tail = NULL;
    }
    void print(){
        Node<T>* node;
        for(node = head; node!= NULL; node = node->next){
            cout << node->value;
            if(node != tail){
                cout << " <-> ";
            }else{
                cout << endl;
            }
        }
    }
};


void cmp_list(list<int> ls1, LinkedList<int>* ls2){
    assert(ls1.size() == ls2->size());
    list<int>::iterator iter= ls1.begin();
    Node<int> * node = ls2->head;
    for(int i = 0;i <ls1.size();i++){
        assert(node->value == *iter);
        node = node->next;
        iter++;
    }
}

int main(){
    list<int> list1;
    LinkedList<int> *list2 = new LinkedList<int>;
    
    list1.push_front(9);
    list2->push_front(9);
    cmp_list(list1, list2);

    list1.push_back(3);
    list2->push_back(3);
    cmp_list(list1,list2);

    for(int i = 2; i<21; i+=3){
        list1.push_front(i);
        list2->push_front(i);
    }
    cmp_list(list1,list2);

    list1.pop_front();
    list2->pop_front();
    cmp_list(list1,list2);

    list1.pop_back();
    list2->pop_back();
    cmp_list(list1,list2);

    list1.clear();
    list2->clear();

    free(list2);
    return 0;
}
