#include "sublist.h"
#include "stdbool.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count){
    int *biggerlist = NULL;
    int *smallerlist = NULL;
    size_t bigcount = 0;
    size_t smallcount = 0;
    bool unequal = true;
    
    if (list_to_compare_element_count > base_list_element_count) {
        if (base_list == NULL) {
            return SUPERLIST;
        }
        biggerlist = list_to_compare;
        smallerlist = base_list;
        bigcount = list_to_compare_element_count;
        smallcount = base_list_element_count;
    } else {
        if (list_to_compare == NULL) {
            if (base_list == NULL) return EQUAL;
            return SUBLIST;
        }
        biggerlist = base_list;
        smallerlist = list_to_compare;
        bigcount = base_list_element_count;
        smallcount = list_to_compare_element_count;
    }

    size_t i = 0;
    size_t common_index;
    COMPARISON:
    for (; (i + smallcount) <= bigcount; i++) {    // Searches for the first element of the smaller set in the bigger one.
        if (smallerlist[0] == biggerlist[i]) {     // The search is tightened so that the smaller list can always fit in
            unequal = false;                       // the bigger one.
            i++;                                                
            common_index = i;
            break;                                              
        }
    }

    if (unequal) return UNEQUAL;    // The flag is by default true, so unless the above loop sets it to false, this condition
                                    // returns unequal.
    for (size_t j = 1; j < smallcount; j++) {
        if (smallerlist[j] != biggerlist[i]) {
            unequal = true;
            i = common_index;    // The common index was assigned above as a starting point in case the search needs to be
            break;               // restarted. 
        }
        i++;
    }

    if (unequal) goto COMPARISON;    // If the flag is set back to true, the search needs to be restarted.

    // At this point, we are certain that the lists are definitely NOT unequal.
    if (base_list_element_count == list_to_compare_element_count) return EQUAL;
    return base_list_element_count > list_to_compare_element_count ? SUBLIST : SUPERLIST;
}