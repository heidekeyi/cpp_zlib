//
// Created by 12131 on 2022/9/2.
//

#ifndef SYMBOL_PARSE_H
#define SYMBOL_PARSE_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char key[32];
    char value[32];
} Map;

typedef struct {
    int count;
    Map map[32];
} Handle;

int retrieve_handle(Handle *handle, const char *path);

int retrieve_value(const Handle *handle, const char *key, const char **value);


#ifdef __cplusplus
}
#endif

#endif //SYMBOL_PARSE_H
