#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

unsigned int hash(const char *key) {
    unsigned int hash = 0;
	
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % CACHE_SIZE;
}

Cache* create_cache() {
    Cache *cache = (Cache*)malloc(sizeof(Cache));
    if (cache) {
		int i;
        for (i = 0; i < CACHE_SIZE; i++) {
            cache->items[i] = NULL;
        }
    }
    return cache;
}

void cache_insert(Cache *cache, const char *key, const char *data) {
    unsigned int index = hash(key);
    CachedItem *new_item = (CachedItem*)malloc(sizeof(CachedItem));
    if (new_item) {
        new_item->key = strdup(key);
        new_item->data = strdup(data);
        cache->items[index] = new_item;
    }
}

const char* cache_get(Cache *cache, const char *key) {
    unsigned int index = hash(key);
    CachedItem *item = cache->items[index];
    if (item && strcmp(item->key, key) == 0) {
        return item->data;
    }
    return NULL;
}
