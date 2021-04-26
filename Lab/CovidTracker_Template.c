// PLEASE DONOT MODIFY FROM LINE 2 TO LINE 67
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header files ENTRY_H and ARRAYDICT_H
#ifndef ENTRY_H
#define ENTRY_H

#define NAMESIZE 51
#define DIMENSIONS 3

// Dictionary entry
typedef struct Entry {
  char key[NAMESIZE];
  double value[DIMENSIONS];
} Entry_t;
#endif

#ifndef ARRAYDICT_H
#define ARRAYDICT_H

// Array implementation of dictionary
typedef struct Dict {
  // A buffer to hold entries
  Entry_t *buf;

  // The maximum size of the buffer
  int bufSize;

  // The current size of the buffer
  // should be in the range [0, bufSize)
  int size;

  // Pointer to a function to compare
  // dictionary entries
  int (*key_cmp)(const Entry_t *, const Entry_t *);
} Dict_t;

// Initial size of buffer
#define INIT_SIZE 1000

// Return an empty dictionary
// (or NULL on failure)
Dict_t *makeDict(int (*)(const Entry_t *, const Entry_t *));

// Free memory allocated to dictionary
void freeDict(Dict_t *);

// Put an entry into the dictionary
// and return the new dictionary (or
// NULL on failure). If an entry with
// this entry's key already exists,
// replace the entry with this entry.
Dict_t *put(Dict_t *, const Entry_t *);

// Find an entry with a given key in
// the dictionary (return 1 if found, 0
// otherwise). Remove the entry if
// remove is non-zero.
int get(Dict_t *, Entry_t *, int remove);

// Return the size of the dictionary
int size(const Dict_t *);

#endif

// Write your code below.Follow all the instructions specified.
/* Programming Assignment 1
 *
 * This file implements a dictionary using
 * a sorted array. You have to complete this
 * implementation in this assignment.
 */

/* Part 1 (REQUIRED):
 * The function get() should use binary search
 * since the buffer is sorted in increasing
 * order by entry keys.
 */
// Find an entry with a given key in
// the dictionary (return 1 if found, 0
// otherwise). Remove the entry if
// remove is non-zero.
int get(Dict_t *dict, Entry_t *entry, int remove) {
  // Check if inputs are legal
  if (dict != NULL && entry != NULL) {
    // Search dict->buf for an entry whose
    // key matches the given entry's key
    // using binary search.

    // Hint: See the function binarySearch
    // in the lecture notes

    // Step 1:
    // Initialize two variables lo and hi
    // as with binarySearch. Note that the
    // size of the array 'n' is dict->size

    // Step 2:
    // Create a while-loop just like binarySearch

    // Step 3:
    // Inside the while-loop, compute the mid-point
    // just like binarySearch

    // Step 4:
    // Use the function dict->key_cmp() to compare
    // the mid-point element with entry. You can
    // save the function result in a temporary
    // variable.

    // Step 5:
    // The three cases in binarySearch correspond
    // to the temporary variable being negative,
    // positive, or zero. Write an if-else if-else
    // structure similar to binarySearch, and fill
    // the first two cases like in binarySearch.

    // Step 6:
    // For the case when key_cmp() returns 0 (the
    // keys match), use the same logic as in
    // arraydict.c to set *entry to the correct
    // buffer entry and, if remove is non-zero,
    // to copy elements leftwards and reduce the
    // size of the dictionary. In either case,
    // return 1 to indicate success.
  }

  // Note: If the while-loop terminates without
  // success, the code will reach here and
  // return 0, as desired

  // Illegal input(s) or unable to find a match
  // so return 0 to indicate failure
  return 0;
}

/* Part 2 (OPTIONAL):
 * Modify the function put() to use binary
 * search to find a location at which to insert
 * the given entry.
 */
// Put an entry into the dictionary
// and return the new dictionary (or
// NULL on failure). If an entry with
// this entry's key already exists,
// replace the entry with this entry.
Dict_t *put(Dict_t *dict, const Entry_t *entry) {
  if (dict == NULL || entry == NULL) {
    return NULL; // illegal input(s)
  }

  // dict != NULL and entry != NULL
  // Search dict's buffer for an Entry_t
  // whose key matches entry's key

  // Step 1: Modify this part to use
  // binary search
  for (int i = 0; i < dict->size; ++i) {
    // Use the key_cmp function to compare keys
    if (dict->key_cmp(&(dict->buf[i]), entry) == 0) {
      // Found match at position i, so replace
      // the element at buf[i] with this entry
      dict->buf[i] = *entry;
      return dict; // return without changing size
    }
  }

  // Step 2 (see below)

  // Unable to find a match, so need to
  // add a new Entry_t to the buffer

  // First check if the buffer has reached
  // its maximum size
  if (dict->size == dict->bufSize) {
    // In this case, we try to re-allocate
    // a new buffer that is twice as large
    int newSize = 2 * (dict->size);

    // Now try to re-allocate a fresh buffer
    // of this size using realloc()
    Entry_t *temp = (Entry_t *)realloc(dict->buf, newSize * sizeof(Entry_t));

    // If realloc failed, simply return NULL
    // (do not modify anything)
    if (temp == NULL) {
      return NULL;
    }

    // Re-allocation succeeded (temp != NULL)
    // Note that realloc() will automatically
    // copy dict->buf entries into temp and,
    // if necessary, free the old dict->buf
    dict->buf = temp;        // resized buffer
    dict->bufSize = newSize; // record new maximum size
  }

  // At this point, there is guaranteed to
  // be room in the buffer to add an entry

  // Step 2: Modify this code so that the
  // new entry is added in sorted order

  // Hint: The while-loop of binarySearch
  // ends when lo > hi. At this point, the
  // location at which to insert the new
  // entry is: hi + 1.
  dict->buf[(dict->size)++] = *entry; // increase dict->size
  return dict;
}

/*** DO NOT MODIFY BELOW THIS LINE ***/

Dict_t *makeDict(int (*cmp)(const Entry_t *, const Entry_t *)) {
  if (cmp == NULL) {
    return NULL; // illegal input
  }

  // Try and allocate space for a Dict_t
  Dict_t *dict = (Dict_t *)malloc(sizeof(Dict_t));

  // If allocation failed, return NULL
  if (dict == NULL) {
    return NULL;
  }

  // Allocation succeeded (dict != NULL.
  // Try to allocate space for a buffer
  // of INIT_SIZE Entry_t's.
  dict->buf = (Entry_t *)malloc(INIT_SIZE * sizeof(Entry_t));

  // If allocation failed, free up memory
  // already allocated and return NULL
  if (dict->buf == NULL) {
    free(dict); // already allocated
    return NULL;
  }

  // Allocation succeded
  dict->bufSize = INIT_SIZE; // maximum size of buffer
  dict->size = 0;            // current size of buffer
  dict->key_cmp = cmp;       // comparison function
  return dict;               // return a new Dict_t
}

// DO NOT MODIFY (same as in arraydict.c)
void freeDict(Dict_t *dict) {
  // If non-NULL, free all allocated space
  if (dict != NULL) {
    free(dict->buf);
    free(dict);
  }
}

// DO NOT MODIFY (same as in arraydict.c)
int size(const Dict_t *dict) {
  // If dict is NULL, size is zero
  return dict == NULL ? 0 : dict->size;
}

// main program file.PLEASE DONOT MODIFY FROM HERE"
/*
 Note: DO NOT MODIFY THIS FILE!
 */

// Function to compare keys
int key_cmp(const Entry_t *a, const Entry_t *b) {
  return strcmp(a->key, b->key); // compare keys as strings
}

// The main program
int main() {
  // Make a dictionary
  Dict_t *dict = makeDict(key_cmp);

  // Check if it is non-NULL
  if (dict != NULL) {

    // Repeatedly read the input
    while (1) {
      char line[NAMESIZE];
      Entry_t e;
      int remove;

      // Read a line of data
      scanf("%s", line);

      // Examine the first character
      switch (line[0]) {
      // s = size
      case 's':
        printf("Size: %d\n", size(dict));
        break;

      // g = get
      case 'g':
        // Read the key to get, and whether to remove
        scanf("%s", e.key);
        scanf("%d", &remove);

        // Check if get was successful
        if (get(dict, &e, remove)) {
          // Successful, so print 3-dimensions of value
          printf("(%lf, %lf, %lf)\n", e.value[0], e.value[1], e.value[2]);
        } else {
          // Unsuccessful, so print message
          printf("No entry with key %s\n", e.key);
        }
        break;

      // p = put
      case 'p':
        // Read the key and value to put
        scanf("%s", e.key);
        for (int i = 0; i < DIMENSIONS; ++i) {
          scanf("%lf", &e.value[i]);
        }

        // Attempt to put entry into dict
        Dict_t *temp = put(dict, &e);

        // Check if attempt was successful
        if (temp != NULL) {
          // Successful
          printf("Added entry with key %s\n", e.key);
          dict = temp; // update dict pointer
        } else {
          // Unsuccessful
          printf("Error\n");
        }
        break;

      // Anything else = quit
      default:
        freeDict(dict);
        return 0;
      }
    }
  }
}
