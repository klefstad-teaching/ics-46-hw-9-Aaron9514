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
    return edit_distance_within(word1, word2, 0);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    if (d > 1) return false;    // to escape algorithm sooner
    if (str1.size() == 0)       // hit the end of one of the strings
        d += str2.size();
    else if (str2.size() == 0)
        d += str1.size();
    else {
        if (str1[0] == str2[0]) // current chars are equal
            return edit_distance_within(str1.substr(1), str2.substr(1), d);
        if (str1.size() < str2.size())  // chars not equal, case 1
            return edit_distance_within(str1, str2.substr(1), d + 1);
        if (str1.size() > str2.size())  //                  case 2
            return edit_distance_within(str1.substr(1), str2, d + 1);
        return edit_distance_within(str1.substr(1), str2.substr(1), d + 1); // case 3
    }
    return d <= 1;
}

void load_words(set<string> & word_list, const string& file_name)
{
    ifstream in(file_name);
    for (string word; in >> word;)
        word_list.insert(word);
    in.close();
}