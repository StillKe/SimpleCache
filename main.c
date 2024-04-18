#include <stdio.h>
#include "cache.h"

int main() {
    Cache *cache = create_cache();

    cache_insert(cache, "page1", "Content of page 1");
    cache_insert(cache, "page2", "Content of page 2");

    printf("Cached data for 'page1': %s\n", cache_get(cache, "page1"));
    printf("Cached data for 'page2': %s\n", cache_get(cache, "page2"));

    return 0;
}
