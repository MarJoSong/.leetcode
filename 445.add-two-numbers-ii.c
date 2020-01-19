/*
 * @lc app=leetcode id=445 lang=c
 *
 * [445] Add Two Numbers II
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
    int num1, num2;
    struct ListNode *cur,*pre;
    int len1=0,len2=0,carry = 0;;
    int mid[1024] = {0};
    int *tmp1 = (int*)malloc(sizeof(int)*1024);
    int *tmp2 = (int*)malloc(sizeof(int)*1024);
    memset(tmp1, 0, sizeof(int)*1024);
    memset(tmp2, 0, sizeof(int)*1024);

    for(cur=l1; cur!=0; cur = cur->next){
        mid[len1++] = cur->val;
    }
    memcpy(tmp1+=(1024-len1),mid, len1*sizeof(int));

    memset(mid, 0, sizeof(int)*1024);
    for(cur=l2; cur!=0; cur = cur->next){
        mid[len2++] = cur->val;
    }
    memcpy(tmp2+=(1024-len2),mid, len2*sizeof(int));

    cur =  (struct ListNode*)malloc(sizeof(struct ListNode));
    memset(cur, 0 ,sizeof(struct ListNode));
    do{
        cur->val = (tmp1[--len1]+ tmp2[--len2]+carry)%10;
        carry = (tmp1[len1]+ tmp2[len2]+carry)/10;
        pre =  (struct ListNode*)malloc(sizeof(struct ListNode));
        memset(pre, 0 ,sizeof(struct ListNode));
        pre->next = cur;
        cur = pre;
    }while(len1>0 || len2>0);

    if(1 == carry){
        cur->val = 1;
        return cur;
    }
    return cur->next;
}

// @lc code=end

