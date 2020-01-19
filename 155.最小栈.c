/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 */

// @lc code=start

#define MINSTACKSIZE 8

typedef struct {
    int *content;
    int length;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *myStack;
    myStack->content = (int *)malloc(sizeof(int) * MINSTACKSIZE);
    memset(myStack->content, 0, sizeof(int) * MINSTACKSIZE);
    myStack->length = -1;
    myStack->size = MINSTACKSIZE;
    return myStack;
}

void minStackPush(MinStack* obj, int x) {
    obj->length++;
    if(obj->length > obj->size)
    {
        int *content = (int *)malloc(sizeof(int) * 2 * obj->size);
        memset(obj->content, 0, sizeof(int) * 2 * obj->size);
        memcpy(content, obj->content, sizeof(int) * obj->length);
        free(obj->content);
        obj->content = content;
    }
    obj->content[obj->length] = x;
}

void minStackPop(MinStack* obj) {

}

int minStackTop(MinStack* obj) {
  
}

int minStackGetMin(MinStack* obj) {
  
}

void minStackFree(MinStack* obj) {
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end

