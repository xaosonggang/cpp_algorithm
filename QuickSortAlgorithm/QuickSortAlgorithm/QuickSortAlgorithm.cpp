// QuickSortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "../../Utility/utility.h"
#include "deque"
#include "queue"

using std::queue;

void QuickSort_Recursion(vector<int>& targVec, int nLeftIndex, int nRightIndex)
{
    if (nLeftIndex >= nRightIndex) return;
    if (nLeftIndex < 0 || nRightIndex >= static_cast<int>(targVec.size())) return;

    int pivotVal = targVec[nRightIndex];
    int leftMaxIndex = nLeftIndex;
    int rightMinIndex = nRightIndex - 1;

    while (true)
    {
        while (leftMaxIndex < nRightIndex && targVec[leftMaxIndex] <= pivotVal)
            ++leftMaxIndex;
        while (rightMinIndex >= nLeftIndex && targVec[rightMinIndex] > pivotVal)
            --rightMinIndex;
        if (leftMaxIndex > rightMinIndex) break;
        SwapVecVal(targVec, leftMaxIndex, rightMinIndex);
    }
    SwapVecVal(targVec, leftMaxIndex, nRightIndex);

    QuickSort_Recursion(targVec, nLeftIndex, leftMaxIndex - 1);
    QuickSort_Recursion(targVec, leftMaxIndex + 1, nRightIndex);
}

void QuickSort_Deque(vector<int>& targVec)
{
    if (targVec.size() < 1) return;

    std::deque<int> indexDeque = { 0, static_cast<int>(targVec.size()) - 1 };
    queue<int> indexQueue(indexDeque);
    while (indexQueue.size() > 1)
    {
        int left = indexQueue.front();
        indexQueue.pop();
        int right = indexQueue.front();
        indexQueue.pop();
        if (left >= right) continue;
        if (left < 0 || left > static_cast<int>(targVec.size()) - 1) continue;
        if (right < 0 || right > static_cast<int>(targVec.size()) - 1) continue;

        int pivotVal = targVec[right];
        int leftIndex = left;
        int rightIndex = right - 1;

        while (true)
        {
            while (leftIndex < right && targVec[leftIndex] <= pivotVal)
                ++leftIndex;
            while (rightIndex >= left && targVec[rightIndex] > pivotVal)
                --rightIndex;
            if (leftIndex >= rightIndex) break;
            SwapVecVal(targVec, leftIndex, rightIndex);
        }
        SwapVecVal(targVec, leftIndex, right);

        if (leftIndex - 1 > left)
        {
            indexQueue.push(left);
            indexQueue.push(leftIndex - 1);
        }
        if (right > leftIndex + 1)
        {
            indexQueue.push(leftIndex + 1);
            indexQueue.push(right);
        }

        cout << left << "\t" << right << endl;
    }
    return;
}

void QuickSort_Desc(vector<int>& targVec, int nLeftIndex, int nRightIndex)
{
    if (nLeftIndex >= nRightIndex) return;
    if (nLeftIndex < 0 || nLeftIndex >= static_cast<int>(targVec.size())) return;
    if (nRightIndex < 0 || nRightIndex >= static_cast<int>(targVec.size())) return;

    int pivotVal = targVec[nLeftIndex];
    int leftMaxIndex = nLeftIndex + 1;
    int rightMinIndex = nRightIndex;

    while (true)
    {
        while (leftMaxIndex <= nRightIndex && targVec[leftMaxIndex] > pivotVal)
            ++leftMaxIndex;
        while (rightMinIndex > nLeftIndex && targVec[rightMinIndex] <= pivotVal)
            --rightMinIndex;
        if (leftMaxIndex >= rightMinIndex) break;
        SwapVecVal(targVec, leftMaxIndex, rightMinIndex);
    }
    SwapVecVal(targVec, rightMinIndex, nLeftIndex);

    QuickSort_Desc(targVec, nLeftIndex, rightMinIndex - 1);
    QuickSort_Desc(targVec, rightMinIndex + 1, nRightIndex);
    return;
}

int main()
{
    vector<int> randVec = GetRandomVecInt(0, 999);
    cout << "random vector!" << endl;
    PrintVec(randVec);

    //QuickSort_Recursion(randVec, 0, static_cast<int>(randVec.size()) - 1);
    //QuickSort_Deque(randVec);
    QuickSort_Desc(randVec, 0, static_cast<int>(randVec.size()) - 1);

    cout << "\n\nquick sort vector!" << endl;
    PrintVec(randVec);

    for (int i = 0; i < static_cast<int>(randVec.size()) - 1; ++i)
    {
        if (randVec[i] < randVec[i + 1])
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
