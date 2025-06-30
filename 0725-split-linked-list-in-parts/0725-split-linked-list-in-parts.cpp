/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Intuition: Isme kya tha ki hame apne list ko todna tha kuchh parts me toh uske liye n/k aur n%k wala logic hi lafta hai but mai jaha par fasa vo tha ki kaise mai apne nodes ke parts ko vector me dalu toh uske liye ek loop jo ki hoga mere k ke liye yani ki uske k parts hain baki ka bas andar jo tha vo toh number of nodes in one part aur remainder ne sambhal liya
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp!= NULL){
            n+=1;
            temp = temp->next;
        }
        vector<ListNode*>ans(k,NULL);
        int parts = n/k;
        int remainder = n%k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i=0;curr!= NULL && i<k;i++){
            ans[i] = curr;
            for(int j = 1;j<=parts+(remainder>0 ? 1:0);j++){// yr aise statements likna hi growth hai ternary operators ka use karna achhi practice hai code me
                prev = curr;
                curr = curr->next;
            }
            
            prev->next = NULL;// yaha par code fat ja raha tha kyuki mainr pre!= NULL ki condition nahi lagayi thi aur jab bhi linkedlist ke questions karo iss baat ka jarur dhyan rakho ki kahi par koi jo pointer ja raha aage vo null ki condition usme lgaani rah toh nahi gayi
            remainder--;
        }
        return ans;
    }
};
// time complexity: 0(L+k) har nodes ko ham visit kar rahe aur har k parts ko is liye l+k aa raha hai.