/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node* temp = head;
//         while(temp != NULL){
//             Node* copyNode = new Node(temp->val);
//             copyNode->next = temp->next;
//             temp->next = copyNode;
//             temp = temp->next->next;
//         }
//         // 2nd step
//         temp = head;
//         while(temp != NULL){
//            Node* copyNode = temp->next;
//            if(temp->random){
//             copyNode->random = temp->random->next; 
//            }
//            else{
//             copyNode->random = NULL;
//            }
//         }
//         Node* dummyNode = new Node(-1);
//         Node* res = dummyNode;
//         temp = head;
//         while(temp != NULL){
//             res->next = temp->next;
//            temp->next = temp->next->next;
//             res = res->next;
//             temp= temp->next;
//         }
//         return dummyNode->next;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hashMap;
        Node* cur = head;

        while (cur) {
            hashMap[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        while (cur) {
            Node* copy = hashMap[cur];
            copy->next = hashMap[cur->next];
            copy->random = hashMap[cur->random];
            cur = cur->next;
        }

        return hashMap[head];        
    }
};