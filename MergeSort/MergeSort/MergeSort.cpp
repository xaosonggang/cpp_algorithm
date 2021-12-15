// MergeSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "../../Utility/utility.h"


void Merge(vector<int>& targVec, vector<int>& tempVec, int start, int mid, int end)
{
    for (int i = start; i <= end; ++i)
    {
        tempVec[i] = targVec[i];
    }

    int leftStart = start;
    int rightStart = mid + 1;
    //插入算法1
    //for (int i = start; i <= end; i++)
    //{
    //    if (leftStart > mid)
    //    {
    //        targVec[i] = tempVec[rightStart++];
    //    }
    //    else if (rightStart > end)
    //    {
    //        targVec[i] = tempVec[leftStart++];
    //    }
    //    else if (tempVec[leftStart] <= tempVec[rightStart])
    //    {
    //        targVec[i] = tempVec[leftStart++];
    //    }
    //    else
    //    {
    //        targVec[i] = tempVec[rightStart++];
    //    }
    //}

    //插入算法2
    while (leftStart <= mid && rightStart <= end)
    {
        if (tempVec[leftStart] <= tempVec[rightStart])
        {
            targVec[start++] = tempVec[leftStart++];
        }
        else
        {
            targVec[start++] = tempVec[rightStart++];
        }
    }

    if (leftStart > mid)
    {
        while (rightStart <= end)
        {
			targVec[start++] = tempVec[rightStart++];
        }
    }
    else if (rightStart > end)
    {
        while (leftStart <=mid)
        {
			targVec[start++] = tempVec[leftStart++];
        }
    }
}

void MergeSort_Recursion(vector<int>& targVec, vector<int>& tempVec, int start, int end)
{
	if (end - start < 1) return;
	int mid = start + (end - start) / 2;
	MergeSort_Recursion(targVec, tempVec, start, mid);
	MergeSort_Recursion(targVec, tempVec, mid + 1, end);
	Merge(targVec, tempVec, start, mid, end);
}

void MergeSort(vector<int>& targVec)
{
	vector<int> tempVec(targVec.size());
	MergeSort_Recursion(targVec, tempVec, 0, static_cast<int>(targVec.size()) - 1);
}

int main()
{
	vector<int> randVec = GetRandomVecInt(100, 999);
	cout << "random vector!" << endl;
	PrintVec(randVec);

    MergeSort(randVec);

	cout << "\n\nmerge sort vector!" << endl;
	PrintVec(randVec);

	for (int i = 0; i < static_cast<int>(randVec.size()) - 1; ++i)
	{
		if (randVec[i] > randVec[i + 1])
		{
			cout << "error sort!!!" << endl;
		}
	}

	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
