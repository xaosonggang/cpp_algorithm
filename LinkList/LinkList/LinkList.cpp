// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "../../Utility/utility.h"
#include "LinkListClass.h"


int main()
{
	LinkList<int> lList;
	PrintLinkList(lList);

	vector<int> randVec(GetRandomVecInt(16, 999));
	cout << "Rand Vec:" << endl;
	PrintVec(randVec);

	for (const auto& elem : randVec)
	{
		lList.Insert(lList.GetSize(), elem);
	}

	cout << "\n\n After insert" << endl;
	PrintLinkList(lList);

	/*
	cout << "\n\n Delete All LinkList" << endl;
	//lList.Delete(randVec[1]);
	//lList.Delete(randVec[0]);
	//lList.Delete(randVec[randVec.size()-1]);
	lList.DeleteIndex(1);
	lList.DeleteIndex(0);
	lList.DeleteIndex(static_cast<int>(randVec.size()) -3);
	PrintLinkList(lList);
	*/

	cout << "\n\n Search" << endl;
	cout << "s 2:" << lList.Search(randVec[2]) << endl;
	cout << "s 0:" << lList.Search(randVec[0]) << endl;
	cout << "s v 1:" << lList.SearchIndex(1) << endl;
	cout << "s v end:" << lList.SearchIndex(static_cast<int>(randVec.size()) -1) << endl;
	PrintLinkList(lList);

	cout << "\n\n Update" << endl;
	lList.Update(randVec[2], 101);
	lList.Update(randVec[0], 102);
	lList.UpdateIndex(1, 103);
	lList.UpdateIndex(static_cast<int>(randVec.size()) - 1, 104);
	PrintLinkList(lList);

	cout << endl;
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
