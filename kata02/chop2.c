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
 * Implementation number 0 to create test cases
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
    int start = 0;
    int end = size - 1;

    // handle empty array
    if(end < start) return -1;

    int split = -1;

    while(start < end) {
        split = start + ((end - start) / 2) + 1;
        
        if(target < array[split]) {
            end = split - 1;
        } else {
            start = split;
        }
    };

    if(start == end && target == array[start]) {
        return start;
    }

    return -1;
}