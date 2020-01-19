/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode *ret, *cur, *pre, *tmp1 = l1, *tmp2 = l2;
    struct ListNode tmp = {0, NULL};

    cur =  (struct ListNode*)malloc(sizeof(struct ListNode));
    memset(cur, 0 ,sizeof(struct ListNode));
    ret = cur;
    while(1){
        cur->val = (tmp1->val + tmp2->val + carry)%10;
        carry = (tmp1->val + tmp2->val + carry)/10;
        if(tmp1->next == NULL && tmp2->next == NULL) break;
        pre =  (struct ListNode*)malloc(sizeof(struct ListNode));
        memset(pre, 0 ,sizeof(struct ListNode));
        cur->next = pre;
        cur = pre;
        if(NULL != tmp1->next) tmp1 = tmp1->next;
        else tmp1 = &tmp;
        if(NULL != tmp2->next) tmp2 = tmp2->next;
        else tmp2 = &tmp;
    }

    if(1 == carry){
        pre =  (struct ListNode*)malloc(sizeof(struct ListNode));
        memset(pre, 0 ,sizeof(struct ListNode));
        pre->val = 1;
        cur->next = pre;
    }
    return ret;
}


// @lc code=end

