typedef std::set<std::pair<std::string,std::string> > set_of_word_pairs;

bool common(const std::string &a, const std::string &b) 
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j]) return true;
		}
	}
	return false;
}

void common(set_of_word_pairs &answer, const std::vector<std::string>& words, int a, int b)
{
	if(words.size() != a && words.size() != b)
	{
		if(common(words[a], words[b])) answers.insert(words[a], words[b]);
	}
}


void common(set_of_word_pairs &answer, const std::vector<std::string>& words, int a)
{
}

set_of_word_pairs common(const std::vector<std::string>& words)
{

}

int main()
{

}