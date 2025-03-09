#include "ladder.h"

int main(int argc, char * argv[])
{
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    if (argc > 2)
        print_word_ladder(generate_word_ladder(argv[1], argv[2], word_list));
          
    else
        print_word_ladder(generate_word_ladder("cat", "cog", word_list));
    verify_word_ladder();     
}