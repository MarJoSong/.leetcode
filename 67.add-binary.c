/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start

char * addBinary(char * a, char * b){
    int i;
    char carry = '0';
    int lena = strlen(a), lenb = strlen(b);
    int lenl = strlen(a)>strlen(b)?strlen(a):strlen(b);
    int lens = strlen(a)>strlen(b)?strlen(a):strlen(b);
    char *ret = (char*)malloc(lenl+2);
    memset(ret, 0, lenl+2);
    for(i=1; i<=lens; ++i){
        if(a[lena-i] & b[lenb-i]){
            /* 都为1 */
            ret[lenl+1-i] = carry;
            carry = '1';  
        }else if(a[lena-i] | b[lenb-i]){
            ret[lenl+1-i] = '1' ^ carry ;
            carry = '1' & carry;
        }else{
            ret[lenl+1-i] = carry;
            carry = 0;
        }
    }
    if(strlen(a)>strlen(b)){
        for(; i<=lenl; ++i){
            ret[lenl+1-i] = a[lena-i] ^ carry;
            carry = a[lena-i] & carry; 
        }
    }else{
        for(; i<=lenl; ++i){
            ret[lenl+1-i] = b[lena-i] ^ carry;
            carry = b[lena-i] & carry; 
        }
    }
    if(carry = '1'){
        ret[lenl+1-i] = '1';
    }else{
        ret++;
    }
    return ret;
}

// @lc code=end

