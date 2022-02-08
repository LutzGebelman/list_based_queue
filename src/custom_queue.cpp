#include "custom_queue.h"

template <
    class Key
> class Queue{
    protected:
        struct Node{
            Key Data;
            Node * next = nullptr;
            Node * prev = nullptr;

            bool operator == (Node * rhs){
                return this->Data == rhs->Data;
            }
        };

        Node * new_node = new Node;
        
        bool check_for_key(Node * first, Key data){
            if (first == nullptr) return false;
            Node * temp = first;
            do
            {
                if (temp->Data
                && temp->Data == data) return true;
                temp = temp->next;
            } while (temp != NULL);
            return false;
        }

        Node * get_last(Node * first){
            if(first == nullptr) return first;
            Node * temp = first;
            while(true){
                if ( temp->next == nullptr ) return temp;
                temp = temp->next;
            }
        }
    
    public:
        
        template<class QKey> 
        friend std::ostream& operator << (std::ostream& os, const Queue<QKey>& queue){
            Node * temp = queue.new_node;
            do{
                os << temp->Data << " | ";
                temp = temp->next;
            } while(temp != nullptr);
            return os;
        }

        Queue(){}

        Queue(Key data){
            this->new_node->Data = data;
        }

        bool Put(Key key){
            if (check_for_key(this->new_node, key)) return false;
            Node * last_node = get_last(this->new_node);
            last_node->next = new Node;
            last_node->next->prev = last_node;
            last_node = last_node->next;
            last_node->Data = key;
            return true;
        }
};