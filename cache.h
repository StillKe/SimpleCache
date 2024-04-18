#ifndef CACHE_H
#define CACHE_H

#define CACHE_SIZE 100

typedef struct CachedItem {
    char *key;
    char *data;
} CachedItem;

typedef struct Cache {
    CachedItem *items[CACHE_SIZE];
} Cache;

Cache* create_cache();
void cache_insert(Cache *cache, const char *key, const char *data);
const char* cache_get(Cache *cache, const char *key);

#endif /* CACHE_H */
