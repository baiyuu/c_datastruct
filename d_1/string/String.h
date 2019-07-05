
#include <iostream>

using namespace std;
namespace String {
    /*
        StrAssian(T ,*char) 生成一个值等于常量char 的串T 
        StrCopy
        clear
        isEmpty
        length
        compare
        concat
        subString
        index
        replace
        StrInsert
        StrDelete
     */


    void next(string t, int *next) {
//        string source = "ababaaaba";
//        string target = "ababaa";
        std::cout << t << std::endl;
        int i = 1;
        int j = 0;
        next[1] = 0;
        int len = t.length();
        // t[i] 表示后缀， t[j]表示前缀
        while (i < len)
            if (j == 0 || t[i - 1] == t[j - 1]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];

            }
    }

    void next_val(string t, int *next) {
        int i = 1;
        int j = 0;  
        next[1] = 0;
        while (i < t.length()) {
            if (j == 0 && t[i] == t[j]) {
                ++i;
                ++j;
                if (t[i] != t[j]) {
                    next[i] = j;
                } else {
                    next[i] = next[j];
                }
            } else {
                j = next[j];
            }
        }

    }


    int kmp(string source, string target, int position = 1) {
        int p[20];
        int p2[20];
        next(target, p);
        next_val(target, p2);
        int slen = static_cast<int>(source.length());
        int tlen = static_cast<int>(target.length());

        for (int i = 1; i <= tlen; i++)
            printf("%d\t", p[i]);
        printf("\n");
        
        for (int i = 1; i <= tlen; i++)
            printf("%d\t", p2[i]);
        printf("\n");


        int i = 0;
        int j = 1;

        while (i <= slen && j <= tlen) {
            if (j == 0 || source[i] == target[j]) {
                ++i;
                ++j;
            } else {
                j = p[j];
            }
        }

        if (j > tlen) {
            return i - tlen;
        } else {
            return 0;
        }

    }

    void testKmp() {
        string source = "ababaacaba";
        string target = "caba";
        int a = kmp(source, target);
        std::cout << "字串的位置：" << a << std::endl;
    }

    void run() {
        testKmp();
    }
}