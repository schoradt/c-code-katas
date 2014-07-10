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
 * Global interface defining include file
 *
 * @author Sven Schoradt S. Schoradt <sven.schoradt@googlemail.com>
 *
 * @version 1.0
 *
 * @date 10.07.2014
 */

#include <stdlib.h>

#ifndef CCODEKATAS_CHOP_H
#define CCODEKATAS_CHOP_H

/**
 * Search the target by binary search.
 *
 * @param target value to search
 * @param array  sorted array to search in
 *
 * @return index of the value or -1 if not found
 */
int chop(int target, int* array, size_t size);

#endif
