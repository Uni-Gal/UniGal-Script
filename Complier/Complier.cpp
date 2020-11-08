#include <iostream>
#include <fstream>
#include <algorithm>
#include "pugixml.hpp"

using namespace std;

string DefaultType_text = "text";
string DefaultType_code = "code";
string DefaultType_logic = "struct";

string FormatString(string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	return str;
}

int main(void)
{

	pugi::xml_document unigal;
	pugi::xml_parse_result result = unigal.load_file("Simple.unigal");
	string src = FormatString(unigal.select_single_node("/unigal-script/head/src/text()").node().value());
	string dst = FormatString(unigal.select_single_node("/unigal-script/head/dst/text()").node().value());
	string ver = FormatString(unigal.select_single_node("/unigal-script/head/ver/text()").node().value());
	cout << "[src=" << src << "]" << endl;
	cout << "[dst=" << dst << "]" << endl;
	cout << "[ver=" << ver << "]" << endl;
	cout << "开始解析脚本，若需要编译成目标语言则输入1，不需要编译成目标语言则输入0" << endl;
	int flag_complier = 0;
	cin >> flag_complier;
	ofstream objectfile;
	if (flag_complier == 1)
	{
		if (dst == "BKE")
		{
			objectfile.open("Simple2.bkspr");
		}
		else if (dst == "librian")
		{
			cout << "本编译器输出结果为ANSI编码，需要用户手工处理为UTF-8方可支持Librian" << endl;
			objectfile.open("入口.liber");
		}
	}
	int iterator = 0;
	int mode = 0;
	string LatestCharacter = "NULL";
	while (true)
	{
		cout << "==== Press 1 to next row ====" << endl;
		cout << "==== Press 2 to exit     ====" << endl;
		cin >> mode;
		if (mode == 1)
		{
			iterator += 1;
			char xpath[250];
			sprintf(xpath, "%s%d%s", "/unigal-script/body/*[", iterator, "]");
#ifdef _DEBUG
			cout << "[" << iterator << "]" << xpath << endl;
#endif // DEBUG
			cout << "[ID= " << iterator << " ]" << endl;
			cout << "[type= " << unigal.select_node(xpath).node().name() << " ]" << endl;
			string type = unigal.select_node(xpath).node().name();
			if (type == "text")
			{
				//SHOW
				cout << "[character= " << FormatString(unigal.select_node(xpath).node().child("character").child("name").child_value()) << " ]" << endl;
				cout << "[content= " << FormatString(unigal.select_node(xpath).node().child("content").child("part").child_value()) << " ]" << endl;
				//COMPLIER
				string CurrentCharacter = FormatString(unigal.select_node(xpath).node().child("content").child("part").child_value());
				if (flag_complier == 1)
				{
					if (dst == "BKE")
					{
						//【凉子】[r]
						//抱歉，等很久了么？？[p]
						if (LatestCharacter == CurrentCharacter)
						{
							//说话角色已变更
							LatestCharacter = CurrentCharacter;
							objectfile << FormatString(unigal.select_node(xpath).node().child("character").child("name").child_value()) << "[r]" << endl;
						}
						else
						{
							//说话角色未变更
							;
						}
						objectfile << FormatString(unigal.select_node(xpath).node().child("content").child("part").child_value());
					}
					else if (dst == "librian")
					{
						//潘大爺 「今天天氣不錯，去散步吧。」
						objectfile << FormatString(unigal.select_node(xpath).node().child("character").child("name").child_value()) << " ";
						objectfile << "「" << FormatString(unigal.select_node(xpath).node().child("content").child("part").child_value()) << "」" << endl;
					}
				}
			}
			else if (type == "code")
			{
				cout << "[code type= " << unigal.select_node(xpath).node().first_child().name() << " ]" << endl;
				string codetype = unigal.select_node(xpath).node().first_child().name();
				if (codetype == "action")
				{
					string code_actiontype = unigal.select_node(xpath).node().first_child().first_child().name();
					if (code_actiontype == "newline")
					{
						//SHOW
						cout << "[action= newline ]" << endl;
						//COMPLIER
						if (flag_complier == 1)
						{
							cout << "generate obj file" << endl;
							if (dst == "BKE")
							{
								cout << "dst == BKE" << endl;
								objectfile << "[p]" << endl;
							}
							if (dst == "librian")
							{
								cout << "dst == librian" << endl;
							}
						}
						else
						{
							;
						}
					}
					if (code_actiontype == "waitclick")
					{
						cout << "[action= waitclick ]" << endl;
					}
				}
				if (codetype == "resource")
				{
					;
				}
				if (codetype == "logic")
				{
					;
				}
				if (codetype == "extension")
				{
					;
				}
			}
			else if (type == "struct")
			{
				;
			}
			else
			{
				;
			}
		}
		else
		{
			if (flag_complier != 0)
			{
				//进行后处理
				if (dst == "BKE")
				{
					objectfile << "@quit" << endl;
				}
				exit(0);
			}
			else
			{
				//不进行后处理
				exit(0);
			}
		}
	}
	return 0;
}