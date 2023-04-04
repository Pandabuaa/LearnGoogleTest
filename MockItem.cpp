#include <gmock/gmock.h>
#include "Item.h"
template<typename T> class MockItem {
public:
	MOCK_METHOD( Item<T> ,add,(Item<T>&, Item<T>&));
	MOCK_METHOD(Item<T> ,mul,(Item<T>&, Item<T>&));
};

template<template<typename S>typename Mocktype, typename T> class ItemHub {
public:
	Mocktype<T> add(Mocktype<T>&, Mocktype<T>&);
	Mocktype<T> mul(Mocktype<T>&, Mocktype<T>&);
};