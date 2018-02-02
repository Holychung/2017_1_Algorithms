#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a >= b ? a : b;
}

// cards structure
struct Card{
    int suit;
    char rank;
    int len = 1; // default length
};

// do parsing and save data in card structure
void parse_str(int cnum, Card *c)
{
    for(int i = 0; i < cnum; i++)
    {
        string str;
        cin >> str;

        // ex: 5A
        if(str.length() == 2)
        {
            c[i].suit = str[0] - 48;
            c[i].rank = str[1];
        }
        // ex: 13A
        else if(str.length() == 3)
        {
            c[i].suit = 10*(str[0] - 48) + (str[1] - 48);
            c[i].rank = str[2];
        }
    }
    return;
}

// dynamic programming // find longest subsequence
int find_longest_subseq(int cnum, Card *c)
{
    int longest = 0;
    for(int i = cnum - 1; i >= 0; i--)
    {
        int index = i+1;
        while(index < cnum)
        {
            // the card has rank 8 itself
            if(c[i].suit == 8)
            {
                c[i].len = max(c[i].len, 1 + c[index].len);
            }
            // the same suit or rank or one has rank 8
            else if(c[index].suit == 8 || c[i].suit == c[index].suit || c[i].rank == c[index].rank)
            {
                c[i].len = max(c[i].len, 1 + c[index].len);
            }
            longest = max(longest, c[i].len);
            index++;
        }
    }
    return longest;
}

int main()
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int card_num;
        cin >> card_num;
        Card seqence[card_num];
        parse_str(card_num, seqence);
        cout << find_longest_subseq(card_num, seqence) << endl;
    }

    return 0;
}
