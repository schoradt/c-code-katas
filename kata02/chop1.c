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

int chop_recursive(int target, int* array, int start, int end)
{
    if(end < start) {
        return -1;
    } else if(start == end) {
        if(array[start] == target) {
            return start;
        } else {
            return -1;
        }
    } else {
        int split = start + ((end - start) / 2) + 1;

        if(target < array[split]) {
            return chop_recursive(target, array, start, split - 1);
        } else {
            return chop_recursive(target, array, split, end);
        }
    }
}

int chop(int target, int* array, size_t size)
{
    return chop_recursive(target, array, 0, size - 1);
}