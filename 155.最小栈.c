/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 */

// @lc code=start

#define MINSTACKSIZE 8

typedef struct
{
		int **content;
		int length;
		int size;
} MinStack;

void safe_free(void* ptr)
{
		if(NULL != ptr)
		{
				free(ptr);
				ptr = NULL;
		}
}
/** initialize your data structure here. */

MinStack *minStackCreate()
{
		MinStack *myStack = (MinStack *)malloc(sizeof(MinStack));
		myStack->content = (int **)malloc(sizeof(int *) * MINSTACKSIZE);
		memset(myStack->content, 0, sizeof(int *) * MINSTACKSIZE);
		myStack->length = 0;
		myStack->size = MINSTACKSIZE;
		return myStack;
}

void minStackPush(MinStack *obj, int x)
{
		obj->length++;
		if (obj->length > obj->size)
		{
				int **content = (int **)malloc(sizeof(int *) * 2 * obj->size);
				memset(content, 0, sizeof(int *) * 2 * obj->size);
				memcpy(content, obj->content, sizeof(int *) * (obj->length - 1));
				safe_free(obj->content);
				obj->content = content;
				obj->size = obj->size * 2;
		}
		obj->content[obj->length - 1] = (int *)malloc(sizeof(int) * 2);
		obj->content[obj->length - 1][0] = x;
		if (obj->length == 1)
		{
				obj->content[obj->length - 1][1] = x;
		}
		else
		{
				obj->content[obj->length - 1][1] = x < obj->content[obj->length - 2][1] ? x : obj->content[obj->length - 2][1];
		}
}

void minStackPop(MinStack *obj)
{
		if (obj->length == 0)
				return;

		if (NULL != obj->content[obj->length - 1])
		{
				safe_free(obj->content[obj->length - 1]);
				obj->content[obj->length - 1] = NULL;
		}
		obj->length--;
}

int minStackTop(MinStack *obj)
{
		return obj->content[obj->length-1][0];
}

int minStackGetMin(MinStack *obj)
{
		return obj->content[obj->length-1][1];
}

void minStackFree(MinStack *obj)
{
		for (int i = 0; i < obj->length; ++i)
		{
				if (NULL != obj->content[i])
				{
						safe_free(obj->content[i]);
				}
		}
		safe_free(obj->content);
		safe_free(obj);
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
