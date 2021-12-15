#pragma once

#include <iostream>
#include <vector>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

//交换vector数据
template<class T> void SwapVecVal(vector<T>& vec, int nSrcIndex, int nTargIndex)
{
	if (nSrcIndex == nTargIndex) return;
	if (nSrcIndex< 0 || nSrcIndex > static_cast<int>(vec.size() - 1)) return;
	if (nTargIndex< 0 || nTargIndex > static_cast<int>(vec.size() - 1)) return;
	T temp = vec[nSrcIndex];
	vec[nSrcIndex] = vec[nTargIndex];
	vec[nTargIndex] = temp;
	return;
}

//打印vector
template<class T> void PrintVec(const vector<T>& vec)
{
	cout << "<<<Begin Print Vector>>>" << endl;
	int count = 0;
	for (const auto& elem : vec)
	{
		cout << elem << "\t";
		if (++count % 10 == 0) cout << endl;
	}
	cout << endl
		<< "<<End Print Vector>>>" << endl;
	return;
}

//取得随机数
vector<int> GetRandomVecInt(int nCount, int nMaxNum = 9999);


