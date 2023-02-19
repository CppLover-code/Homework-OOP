#pragma once
class Inc
{
	const int val;
public:
	Inc(const int n) : val(n){}
	int operator()(int a) { return  a + val; }
};