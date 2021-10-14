
#include <fstream>
#include <string.h>
using namespace std;

int main(void)
{
//    ofstream fw;
//    const char* str = "Testxxxuuu   ";
//    fw.open("C:\\Users\\tramachandran\\Desktop\\out1.txt", ofstream::app);
//    getchar();
//    fw.write(str,strlen(str));
//    fw.close();

    std::string s = "Asd";
    printf("%d\n", s.size());
    for (int i=0; s[i] != '\1'; i++) printf("%c", s[i]);
    return 0;
}
