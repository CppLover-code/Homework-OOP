#pragma once
class Eq
{
	int val;
public:
	Eq(int n) : val(n) {}
	bool operator()(int a) { return a == val;}
};