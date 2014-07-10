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

/**
 * Function that computes the position of an element in an array 
 * by binary search.
 *
 * @param target target value to search
 * @param array  array to search in
 * @param start  start index
 * @param end    end index
 *
 * @return index of the target element or -1 if not found
 */
int chop_recursive(int target, int* array, int start, int end)
{
    if(end < start) { // handle empty array
        return -1;
    } else if(start == end) { // handle array with 1 element
        if(array[start] == target) {
            return start;
        } else {
            return -1;
        }
    } else { // bigger arrays are split in two parts and we search in the part the element should be
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
    // class recursive function with start and end index
    return chop_recursive(target, array, 0, size - 1);
}