#include <bits/stdc++.h>

using namespace std;

int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    system("cls");
    int tk = 0;
    char ch, buffer[15], operators[] = "+-*/%=";
    ifstream fin("W1.txt");
    int i, j = 0;
    if (!fin.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }
    while (!fin.eof())
    {
        ch = fin.get();  
        for (i = 0; i < 6; ++i)
        {
            if (ch == operators[i])
            {
                cout << ch << " is operator\n";
                tk++;
            }
        }
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;
            if (isKeyword(buffer) == 1)
            {
                cout << buffer << " is keyword\n";
                tk++;
            }
            else
            {
                cout << buffer << " is indentifier\n";
                tk++;
            }
        }
    }
    fin.close();
    cout << "\nTotal number of tokens present in the 'W1.txt' file is: " << tk << "\n\n";
    system("pause");
    return 0;
}