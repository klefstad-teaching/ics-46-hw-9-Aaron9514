#include "ladder.h"


void error(string word1, string word2, string msg)
{
    cerr << word1 << ", " << word2 << ", " << msg << endl;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    if (begin_word == end_word) 
        error(begin_word, end_word, "are the same word");
    else {
        queue<vector<string>> ladder_q;
        ladder_q.push({begin_word});
        set<string> visited;
        visited.insert(begin_word);
        while (!ladder_q.empty()) {
            vector<string> ladder = ladder_q.front();
            ladder_q.pop();
            for (string word : word_list)
                if (is_adjacent(ladder.back(), word)) {
                    if (visited.find(word) == visited.end()) {
                        // word not seen yet
                        visited.insert(word);
                        vector<string> ladder_cpy = ladder;
                        ladder_cpy.push_back(word);
                        if (word == end_word)
                            return ladder_cpy;
                        ladder_q.push(ladder_cpy);
                    }
                }
        }
    }
    return {};
}

bool is_adjacent(const string& word1, const string& word2)
{
    int distance = word1.length() - word2.length();
    if (abs(distance) > 1) return false;
    return edit_distance_within(word1, word2, 1);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    string str1_cpy = str1;
    for (size_t i = 0; i < str1.length(); ++i)
        if (str1[i] != str2[i]) {
            if (str1.length() < str2.length())  // insert
                str1_cpy.insert(i, str2, i, 1);
            else if (str1.length() > str2.length()) // delete
                str1_cpy.erase(i, 1);
            else   // substitute
                str1_cpy[i] = str2[i];
            break;
        }
    return str1_cpy == str2;
}

void load_words(set<string> & word_list, const string& file_name)
{
    ifstream in(file_name);
    for (string word; in >> word;)
        word_list.insert(word);
    in.close();
}