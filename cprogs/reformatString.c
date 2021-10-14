/*
Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit.
That is, no two adjacent characters have the same type.
Return the reformatted string or return an empty string if it is impossible to reformat the string.
Input: s = "a0b1c2"
Output: "0a1b2c"
*/

char * reformat(char * s)
{
    int len = strlen(s);
    int charcount = 0;
    int digitcount = 0;
    
    char* result = malloc(sizeof(len));
    memset(result, 0, len);
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9') digitcount++;
        if (s[i] >= 'a' && s[i] <= 'z') charcount++;
    }
    
    // printf("C = %d, D = %d\n", charcount, digitcount);
    // check if the abs(igit - chars) <= 1 if feasible
    if (charcount - digitcount > 1 || charcount - digitcount < -1) 
    {
        return result;
    }
    
    int p = 0; // digit position
    int q = 1; // char position
    for (int j = 0; j < len; j++)
    {
        if (s[j] >= '0' && s[j] <= '9') 
        {
            result[p] = s[j]; 
            p += 2;
        }
        else 
        {
            result[q] = s[j]; 
            q += 2;
        }
    }
    
    return result;
}

int main()
{
    char str[] = "ab123";
    char* r = reformat(str);
    printf("%s\n", r);
    
    return 0;
}