//
// Created by 12131 on 2022/9/2.
//


#include "parse.h"
#include <stdio.h>
#include <string.h>

void parse(Handle *handle, const char *buffer);

int is_space(char ch);

const char *filter_space(const char *buffer);

const char *skip_line(const char *buffer);

int copy_key(Map *map, const char *buffer);

int copy_value(Map *map, const char *buffer);

int decimal(const char *s, int *count);

int retrieve_handle(Handle *handle, const char *path) {
    char buffer[4 * 1024];
    int res = -1;
    if (NULL == handle || NULL == path) {
        printf("NULL == handle || NULL == path\n");
        return res;
    }
    FILE *file = fopen(path, "rb");
    if (NULL == file) {
        printf("open error: %s\n", path);
        return res;
    }
    memset(buffer, 0, sizeof(buffer));
    fread(buffer, sizeof(*buffer), sizeof(buffer) - 1, file);
    if (ferror(file)) {
        printf("read error: %s\n", path);
    } else {
        res = 0;
    }
    fclose(file);
    if (res) {
        return -1;
    }
    parse(handle, buffer);
    const char *v = NULL;
    retrieve_value(handle, "number", &v);
    if (!v) {
        printf("init failure, key of number is not exist\n");
        return -1;
    }
    if (decimal(v, &handle->count)) {
        printf("init failure, key of number is not integer\n");
        return -1;
    }
    return 0;
}

int retrieve_value(const Handle *handle, const char *key, const char **value) {
    if (NULL == handle || NULL == key || NULL == value) {
        printf("NULL == handle || NULL == key || NULL == retrieve_value\n");
        return -1;
    }
    int index = 0;
    int size = sizeof(handle->map) / sizeof(Map);
    while (index < size) {
        if (!strcmp(handle->map[index].key, key)) {
            *value = handle->map[index].value;
            break;
        }
        ++index;
    }
    return 0;
}

void parse(Handle *handle, const char *buffer) {
    memset(handle, 0, sizeof(Handle));
    const char *ptr = filter_space(buffer);
    int index = 0;
    while (*ptr) {
        if ('#' == *ptr) {
            ptr = skip_line(ptr);
            continue;
        }
        int len = copy_key(handle->map + index, ptr);
        len += copy_value(handle->map + index, ptr + len);
        ptr += len;
        ptr = filter_space(ptr);
        if (is_space(handle->map[index].key[0]) || is_space(handle->map[index].value[0])) {
            memset(handle->map + index, 0, sizeof(Map));
        } else {
            ++index;
        }
    }
}

const char *filter_space(const char *buffer) {
    while (*buffer && is_space(*buffer)) {
        ++buffer;
    }
    return buffer;
}

const char *skip_line(const char *buffer) {
    while (*buffer && (*buffer != '\n')) {
        ++buffer;
    }
    return filter_space(buffer);
}

int copy_key(Map *map, const char *buffer) {
    int index = 0;
    char *ptr = map->key;
    int size = sizeof(map->key) / sizeof(*ptr) - 1;
    while (*buffer) {
        ++index;
        if (*buffer == '=' || is_space(*buffer) || index >= size) {
            break;
        }
        *ptr++ = *buffer++;
    }
    return index;
}

int copy_value(Map *map, const char *buffer) {
    int index = 0;
    char *ptr = map->value;
    int size = sizeof(map->value) / sizeof(*ptr) - 1;
    while (*buffer == '=') {
        ++index;
        ++buffer;
    }
    while (*buffer && !is_space(*buffer) && index < size) {
        ++index;
        *ptr++ = *buffer++;
    }
    return index;
}

int is_space(char ch) {
    return ch <= 0x20 || ch > 0x7e;
}

int decimal(const char *s, int *count) {
    int value = 0;
    while (*s) {
        if (*s >= '0' && *s <= '9') {
            value *= 10;
            value += *s - 48;
        } else {
            return -1;
        }
        ++s;
    }
    if (value > 108) {
        value = 108;
    }
    *count = value;
    return 0;
}