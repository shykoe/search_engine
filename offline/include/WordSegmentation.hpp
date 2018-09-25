
#ifndef _WD_WORD_SEGMENTATION_H_
#define _WD_WORD_SEGMENTATION_H_


#include "cppjieba/Jieba.hpp"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace wd
{

const char * const DICT_PATH = "/home/shykoe/code/search_engine/jieba.dict.utf8";
const char * const HMM_PATH = "/home/shykoe/code/search_engine/hmm_model.utf8";
const char * const USER_DICT_PATH = "/home/shykoe/code/search_engine/user.dict.utf8";


class WordSegmentation
{
public:
	WordSegmentation()
		: _jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH)
	{
		cout << "cppjieba init!" << endl;
	}


	vector<string> operator()(const char * src)
	{
		vector<string> words;
		_jieba.CutAll(src, words);//cut with hmm
		return words;
	}

private:
	cppjieba::Jieba _jieba;
};

}// end of namespace wd


#endif
