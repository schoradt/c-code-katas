/*
 * C Code Katas 
 *
 * Kata 02
 *
 * Author  : S. Schoradt <sven.schoradt@googlemail.com>
 * Created : 10.07.2014
 * 
 * Copyright (c) 2014 by Sven Schoradt.
 *
**/

/**
 * @file 
 * Implementation number 3 - an other recursive version without start and end pointers
 *
 * @author Sven Schoradt S. Schoradt <sven.schoradt@googlemail.com>
 *
 * @version 1.0
 *
 * @date 10.07.2014
 */

#include "chop.h"
#include <stdio.h>

int chop(int target, int* array, size_t size)
{
    // handle empty array
    if(size == 0) {
        return -1;
    } else if(size == 1) { // single element array - check value
        if(array[0] == target) {
            return 0;
        } else {
            return -1;
        }
    } else {
        int split = (size / 2);

        if(target < array[split]) {
            return chop(target, array, split);
        } else {
            int res;

            if((res = chop(target, array + split, size - split)) != -1) {
                return split + res;    
            } else {
                return res;
            }
            
        }
    }
}