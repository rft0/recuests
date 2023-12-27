#ifndef CALLBACK_H
#define CALLBACK_H

#include <stdio.h>

size_t HeaderCallback(void* contents, size_t size, size_t nmemb, void* userdata);
size_t BodyCallback(void* contents, size_t size, size_t nmemb, void* userdata);

#endif